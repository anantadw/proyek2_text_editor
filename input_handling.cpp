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
void inputCharacter(char c, List *text, int *column) {
	address node, last;
	
	node = createNode(c);
	if (node != NULL) {
		if ((*text).first == NULL) {
            (*text).first = node;
        } else {
        	last = (*text).first;
        	while (last->next != NULL) {
        		last = last->next;
			}
			
			node->next = last->next;
			node->previous = last;
			last->next = node;
			last = node;
		}
	}
	
	(*text).number_of_column++;
	(*column)++;
	printf("%c", c);
}

/* membuat baris baru */
void newLine(List *text, int *row, int *column) {
	address node, last;
	
	node = createNode('\n');
	if (node != NULL) {
		if ((*text).first == NULL) {
            (*text).first = node;
        } else {
        	last = (*text).first;
        	while (last->next != NULL) {
        		last = last->next;
			}
			
			node->next = last->next;
			node->previous = last;
			last->next = node;
			last = node;
		}
	}
	
	(*text).number_of_column++;
	(*row)++;
	(*column) = 0;
	printf("\n");
}

/* menghapus 1 karakter terakhir dari list */
void deleteCharacter(List *text, int *column) {
	address last, before_last;
	
	last = (*text).first;
	if (last == NULL) {
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	
	before_last = last->previous;
	if (before_last != NULL) {
		before_last->next = NULL;
		last->previous = NULL;
	} else {
		(*text).first = NULL;
	}
	free(last);
	
	(*text).number_of_column--;
	if ((*text).number_of_column < 0) {
		(*text).number_of_column = 0;
	}
	
	(*column)--;
	if ((*column) < 0) {
		(*column) = 0;
	}
	printf("\b \b");
}

