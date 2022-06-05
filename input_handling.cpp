#include "input_handling.h"

/* menginput karakter ke list */
void inputCharacter(char c, List *text, int *column, address *pointer)
{
	address node;
	
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
void newLine(List *text, int *row, int *column, address *pointer, List *text2)
{
	address node, temp;
	int count;
	
	node = createNode('\n');
	// jika baris kosong (cursor di awal)
	if ((*pointer) == NULL)
	{
		if ((*text).first != NULL)
		{
			(*text2).first = (*text).first;
		}
		(*text).first = node;
	}
	// jika cursor di akhir baris
	else if ((*pointer)->next == NULL)
	{
		(*pointer)->next = node;
		(*pointer) = NULL;
		(*text).number_of_column++;
	} 
	// jika cursor di tengah baris
	else if ((*pointer)->next != NULL)
	{
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
	
	if ((*pointer) == NULL)
	{
		return;
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
void paste(List *text, List copy, int row, int *column, address *pointer)
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
	else if ((*pointer)->next != NULL && (*column) < text.number_of_column)
	{
		(*pointer) = (*pointer)->next;
	}
	else
	{
		return;
	}
	
	(*column)++;
	gotoXY((*column), row);
}

/* menggerakan cursor ke atas */
void moveUp(address *pointer, int *cursor_row, int *column, List *text)
{
	int count = 0, i;
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
	}
	else if ((*pointer) == NULL)
	{

	}

	gotoXY((*column), (*cursor_row));
}

void clearClipboard(List *clipboard)
{
	(*clipboard).number_of_column = 0;
	(*clipboard).first = NULL;
}
