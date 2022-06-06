#include "input_handling.h"

/* menginput karakter ke list */
void inputCharacter(char c, List *text, int *column, address *pointer)
{
	address node, last;
	
	node = createNode(c);
	if (node != NULL)
	{	
		// insert first - input di awal baris, baris sudah ada karakter
		if ((*pointer) == NULL && (*text).first != NULL)
		{
			node->next = (*text).first;
			(*text).first->previous = node;
			(*text).first = node;
		}
		// insert first - input di awal baris kosong
		else if ((*pointer) == NULL)
		{
            (*text).first = node;
        }
        // insert after - input di tengah baris
		else if ((*pointer)->next != NULL)
		{
        	(*pointer)->next->previous = node;
        	node->next = (*pointer)->next;
        	(*pointer)->next = node;
        	node->previous = (*pointer);
		}
		// insert last - input di akhir baris
		else if ((*pointer)->next == NULL)
		{
        	(*pointer)->next = node;
        	node->previous = (*pointer);
		}
		
		(*pointer) = node;
	}
	
	(*text).number_of_column++;
	(*column)++;
}

/* membuat baris baru */
void newLine(List text[], int *row, int *cursor_row, int *column, address *pointer)
{
	address node, temp, temp2;
	int count,i ;
	
	node = createNode('\n');
	// jika cursor di awal
	if ((*pointer) == NULL)
	{
		// jika baris tidak kosong
		if (text[*cursor_row].first != NULL)
		{
			text[*cursor_row + 1].first = text[*cursor_row].first;
		}
		text[*cursor_row].first = node;
		text[*cursor_row].number_of_column++;
	}
	// jika cursor di akhir baris tapi sudah ada new line
	else if ((*pointer)->next != NULL && (*pointer)->next->character == '\n')
	{
		for (i = *row; i > 0; i--)
		{
			if (i == *cursor_row)
			{
				break;
			}
			temp2 = text[i].first;
			text[i + 1].first = temp2;
		}
		temp2 = NULL;
		text[*cursor_row + 1].first = node;
		text[*cursor_row + 1].number_of_column = 1;
		(*pointer) = NULL;
	}
	// jika cursor di akhir baris
	else if ((*pointer)->next == NULL)
	{
		(*pointer)->next = node;
		(*pointer) = NULL;
		text[*cursor_row].number_of_column++;
	} 
	// jika cursor di tengah baris
	else if ((*pointer)->next != NULL)
	{
		temp = (*pointer)->next;
		temp->previous = NULL;
		(*pointer)->next = node;
		node->previous = (*pointer);
		
		// jika baris selanjutnya kosong
		if (text[*cursor_row + 1].first == NULL)
		{
			text[*cursor_row + 1].first = temp;
			count = countColumn(text[*cursor_row + 1]);
			text[*cursor_row + 1].number_of_column = count;
		}
		else
		{
			for (i = *row; i > 0; i--)
			{
				if (i == *cursor_row)
				{
					break;
				}
				temp2 = text[i].first;
				text[i + 1].first = temp2;
			}
			temp2 = NULL;
			text[*cursor_row + 1].first = temp;
			count = countColumn(text[*cursor_row + 1]);
			text[*cursor_row + 1].number_of_column = count;
		}
		
		(*pointer) = NULL;
	}
	
	(*column) = 0;
	(*row)++;
	(*cursor_row)++;
	gotoXY(*cursor_row, *column);
}

/* menghapus 1 karakter terakhir dari list */
void deleteCharacter(List *text, int *column, address *pointer, int *row, int *cursor_row, List *text_previous) {
	address temp, temp2;
	int count = 0;
	
	// jika cursor berada di awal baris dan baris pertama
	if ((*pointer) == NULL && (*text).first == NULL && (*cursor_row) == 0)
	{
		return;
	}
	// jika cursor di awal baris bukan baris pertama
	else if ((*pointer) == NULL && (*text).first == NULL && (*cursor_row) != 0) {
		temp = (*text_previous).first;
		(*column) = 1;
		while (temp->next->character != '\n')
		{
			temp = temp->next;
			(*column)++;
		}
		(*column)++;
		temp2 = temp->next;
		temp2->previous = NULL;
		temp->next = NULL;
		(*pointer) = temp;
		(*text_previous).number_of_column--;
		(*cursor_row)--;
		(*row)--;
		free(temp2);
		gotoXY(*column, *cursor_row);
	}
	// jika cursor di awal baris bukan baris pertama, baris tidak kosong
	else if ((*pointer) == NULL && (*text).first != NULL && (*cursor_row) != 0)
	{
		temp = (*text_previous).first;
		count = countColumn(*text);
		(*column) = 1;
		while (temp->next->character != '\n')
		{
			temp = temp->next;
			(*column)++;
		}
		(*column)++;
		temp2 = temp->next;
		temp2->previous = NULL;
		temp->next = (*text).first;
		(*text).first->previous = temp;
		(*text).first = NULL;
		(*pointer) = temp->next->previous;
		(*text_previous).number_of_column--;
		(*text_previous).number_of_column += count;
		(*cursor_row)--;
		(*row)--;
		free(temp2);
		gotoXY(*column, *cursor_row);
	}
	// delete after - menghapus karakter di tengah baris
	else if ((*pointer)->previous != NULL && (*pointer)->next != NULL)
	{
		temp = (*pointer);
		(*pointer) = temp->previous;
		(*pointer)->next = temp->next;
		temp->next->previous = temp->previous;
		temp->next = NULL;
		temp->previous = NULL;
		free(temp);
	}
	// delete first - menghapus 1 karakter tersisa di baris
	else if ((*pointer)->previous == NULL && (*text).first->next == NULL)
	{
		(*text).first = NULL;
		free(*pointer);
		(*pointer) = NULL;
	}
	// delete first - menghapus karakter awal, baris sudah ada karakter
	else if ((*pointer)->previous == NULL && (*text).first != NULL)
	{
		temp = (*pointer);
		(*pointer) = temp->next;
		temp->next = NULL;
		(*pointer)->previous = NULL;
		(*text).first = (*pointer);
		(*pointer) = NULL;
		free(temp);
	}
	// delete last - menghapus karakter akhir di baris
	else if ((*pointer)->next == NULL)
	{
		temp = (*pointer);
		(*pointer) = temp->previous;
		temp->previous = NULL;
		(*pointer)->next = NULL;
		free(temp);
	}
	
	if ((*text).number_of_column > 0)
	{
		(*text).number_of_column--;
	}
	
	if ((*column) > 0)
	{
		(*column)--;
	}
	printf("\b \b");
}

/* menyalin isi dari suatu baris */
List copy(List text)
{
	List copy_result;
	address node, new_node, last;
	
	node = text.first;
	while (node != NULL)
	{
		new_node = createNode(node->character);
		if (new_node != NULL)
		{
			if (copy_result.first == NULL)
			{
	            copy_result.first = new_node;
	        }
			else
			{
	        	last = copy_result.first;
	        	while (last->next != NULL)
				{
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
void paste(List *text, List copy, int *column, address *pointer)
{
	address node;
	
	if (copy.first != NULL)
	{
		(*text).first = copy.first;
		(*text).number_of_column = copy.number_of_column;
		
		node = (*text).first;
		while (node != NULL)
		{
			(*pointer) = node;
			node = node->next;
		}
		(*column) = copy.number_of_column;
	}
}

/* menggerakan cursor ke kiri */
void moveLeft(address *pointer, int *column, int row)
{
	if ((*pointer) != NULL && (*column) > 0)
	{
		(*pointer) = (*pointer)->previous;
		(*column)--;
		gotoXY((*column), row);
	}
}

/* menggerakan cursor ke kanan */
void moveRight(address *pointer, int *column, int row, List text)
{
	if ((*pointer) == NULL && text.first != NULL)
	{
		(*pointer) = text.first;
	}
	else if ((*pointer)->next != NULL && (*column) < text.number_of_column && (*pointer)->next->character != '\n')
	{
		(*pointer) = (*pointer)->next;
	}
	else
	{
//		printf("%d-%d", *column, text.number_of_column);
		return;
	}
	
	(*column)++;
	gotoXY((*column), row);
}

/* menggerakan cursor ke atas */
void moveUp(address *pointer, int *cursor_row, int *column, List *text)
{
	int count = 0, i, x;
	address node;

	if ((*pointer) != NULL && (*text).first != NULL)
	{
		count = countColumn(*text);
		node = (*text).first;
		if ((*column) < count)
		{
			for (i = 1; i < (*column); i++)
			{
				node = node->next;
			}
			x = *column;
		}
		else if (*column >= count)
		{
			for (i = 1; i < count - 1; i++) {
				node = node->next;
			}
			(*column) = count - 1;
			x = count - 1;
		}
		(*pointer) = node;
	}
	else if ((*pointer) == NULL)
	{
		x = 0;
	}
	
	(*cursor_row)--;
	gotoXY(x, *cursor_row);
}

/* menggerakan cursor ke bawah */
void moveDown(address *pointer, int *cursor_row, int *column, List *text)
{
	int count = 0, i, x;
	address node;

	if ((*pointer) != NULL && (*text).first != NULL)
	{
		count = countColumn(*text);
		node = (*text).first;
		if ((*column) < count)
		{
			for (i = 1; i < (*column); i++)
			{
				node = node->next;
			}
			x = *column;
		}
		else if (*column >= count)
		{
			for (i = 1; i < count; i++) {
				node = node->next;
			}
			(*column) = count;
			x = count;
		}
		(*pointer) = node;
	}
	else if ((*pointer) == NULL)
	{
		x = 0;
	}
	
	(*cursor_row)++;
	gotoXY(x, *cursor_row);
}

void clearClipboard(List *clipboard)
{
	(*clipboard).number_of_column = 0;
	(*clipboard).first = NULL;
}
