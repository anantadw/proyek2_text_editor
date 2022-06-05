#include "input_handling.h"

/* mengalokasikan node baru untuk list */
address createNode(char c) {
	address new_node;
	
	new_node = (address) malloc(sizeof(node));
    if (new_node != NULL) {
        new_node->character = c;
        new_node->previous = NULL;
        new_node->next = NULL;
    }

    return new_node;
}

/* menginput karakter ke list */
void inputCharacter(char c, List *text, int *column, address *pointer) {
	address node;
	
	node = createNode(c);
	if (node != NULL) {
		if ((*pointer) == NULL && (*text).first != NULL) {
			node->next = (*text).first;
			(*text).first->previous = node;
			(*text).first = node;
		} else if ((*pointer) == NULL) {
            (*text).first = node;
        } else if ((*pointer)->next != NULL) {
        	(*pointer)->next->previous = node;
        	node->next = (*pointer)->next;
        	(*pointer)->next = node;
        	node->previous = (*pointer);
		} else if ((*pointer)->next == NULL) {
        	(*pointer)->next = node;
        	node->previous = (*pointer);
		}
		(*pointer) = node;
	}
	
	(*text).number_of_column++;
	(*column)++;
}

/* membuat baris baru */
void newLine(List *text, int *row, int *column, address *pointer, List *text2) {
	address node, temp;
	int count;
	
	node = createNode('\n');
	if ((*pointer) == NULL) {
		if ((*text).first != NULL) {
			(*text2).first = (*text).first;
		}
		(*text).first = node;
	} else if ((*pointer)->next == NULL) {
		(*pointer)->next = node;
		(*pointer) = NULL;
		(*text).number_of_column++;
	} else if ((*pointer)->next != NULL) {
		temp = (*pointer)->next;
		temp->previous = NULL;
		(*pointer)->next = node;
		node->previous = (*pointer);
		(*text2).first = temp;
		count = countColumn(*text2);
		(*text2).number_of_column = count;
		(*pointer) = NULL;
	}
	
	(*column) = 0;
	(*row)++;
	gotoXY(*row, *column);
}

/* menghapus 1 karakter terakhir dari list */
void deleteCharacter(List *text, int *column, address *pointer) {
	address temp;
	
	if ((*pointer) == NULL) {
		return;
	} else if ((*pointer)->previous != NULL && (*pointer)->next != NULL) {
		temp = (*pointer);
		(*pointer) = temp->previous;
		(*pointer)->next = temp->next;
		temp->next->previous = temp->previous;
		temp->next = NULL;
		temp->previous = NULL;
		free(temp);
	} else if ((*pointer)->previous == NULL && (*text).first->next == NULL) {
		(*text).first = NULL;
		free(*pointer);
		(*pointer) = NULL;
	} else if ((*pointer)->previous == NULL && (*text).first != NULL) {
		temp = (*pointer);
		(*pointer) = temp->next;
		temp->next = NULL;
		(*pointer)->previous = NULL;
		(*text).first = (*pointer);
		(*pointer) = NULL;
		free(temp);
	} else if ((*pointer)->next == NULL) {
		temp = (*pointer);
		(*pointer) = temp->previous;
		temp->previous = NULL;
		(*pointer)->next = NULL;
		free(temp);
	}
	
	if ((*text).number_of_column > 0) {
		(*text).number_of_column--;
	}
	
	if ((*column) > 0) {
		(*column)--;
	}
	printf("\b \b");
}

/* menyalin isi dari suatu baris */
List copy(List text) {
	List copy_result;
	address node, new_node, last;
	
	node = text.first;
	while (node != NULL) {
		new_node = createNode(node->character);
		if (new_node != NULL) {
			if (copy_result.first == NULL) {
	            copy_result.first = new_node;
	        } else {
	        	last = copy_result.first;
	        	while (last->next != NULL) {
	        		last = last->next;
				}
				
				new_node->next = last->next;
				new_node->previous = last;
				last->next = new_node;
				last = new_node;
			}
		}
		node = node->next;
	}
	copy_result.number_of_column = text.number_of_column;
	
	return copy_result;
}

/* untuk menyimpan hasil salinan suatu baris */
void paste(List *text, List copy, int row, int *column, address *pointer) {
	address node;
	
	if (copy.first != NULL) {
		(*text).first = copy.first;
		(*text).number_of_column = copy.number_of_column;
		
		node = (*text).first;
		while (node != NULL) {
			(*pointer) = node;
			node = node->next;
		}
		(*column) = copy.number_of_column;
	}
}

void gotoXY(int x, int y) {
	COORD c;
	
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void moveLeft(address *pointer, int *column, int row) {
	if ((*pointer) != NULL && (*column) > 0) {
		(*pointer) = (*pointer)->previous;
		(*column)--;
		gotoXY((*column), row);
	}
}

void moveRight(address *pointer, int *column, int row, List text) {
	if ((*pointer) == NULL && text.first != NULL) {
		(*pointer) = text.first;
	} else if ((*pointer)->next != NULL && (*column) < text.number_of_column) {
		(*pointer) = (*pointer)->next;
	} else {
		return;
	}
	
	(*column)++;
	gotoXY((*column), row);
}

void moveUp(address *pointer, int *cursor_row, int *column, List *text) {
	int count = 0, i;
	address node;

	if ((*pointer) != NULL && (*text).first != NULL) {
		count = countColumn(*text);
		node = (*text).first;
		if ((*column) < count)
		{
			for (i = 1; i < (*column); i++)
			{
				node = node->next;
			}
		}
		else if ((*column) > count)
		{
			for (i = 1; i < count; i++) {
				node = node->next;
			}
			(*column) = count;
		}
		(*pointer) = node;
		(*cursor_row)--;
	} else if ((*pointer) == NULL) {

	}

	gotoXY((*column), (*cursor_row));
}

void printText(List text[], int row, int column, int cursor_row) {
	int i;
	address node;
	
	system("cls");
//	printf("Baris : %d Kolom : %d\n", row, column);
	
	for (i = 0; i <= row; i++) {
		node = text[i].first;
		while (node != NULL) {
			printf("%c", node->character);
			node = node->next;
		}
	}
	
	gotoXY(column, cursor_row);
}

int countColumn(List text) {
	address node;
	int count = 0;
	
	node = text.first;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	
	return count;
}

void clearClipboard(List *clipboard) {
	(*clipboard).number_of_column = 0;
	(*clipboard).first = NULL;
}
