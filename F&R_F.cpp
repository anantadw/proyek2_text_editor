// C program to find and replace a word
// in a File by another given word
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Function to find and
// replace a word in File
void findAndReplaceInFile()
{
    FILE *ifp, *ofp;
    char word[100], ch, read[100], replace[100], fn[20], fo[20];
    int word_len, i, p = 0;
	
	printf("\n\tEnter the file name: ");
	fflush(stdin);
	scanf("%s",fn);
	
	printf("\n\tEnter the file name for saving: ");
	fflush(stdin);
	scanf("%s",fo);
	
    ifp = fopen(fn, "r");
    ofp = fopen(fo, "w+");
    if (ifp == NULL || ofp == NULL) {
        printf("Can't open file.");
        exit(0);
    }
    puts("THE CONTENTS OF THE FILE ARE SHOWN BELOW :\n");
 
    // menampilkan konten file ke layar 
    while (1) {
        ch = fgetc(ifp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }

    puts("\n\nEnter the word to find:");
    fflush(stdin);
    fgets(word, 100, stdin);

    // removes the newline character from the string
    word[strlen(word) - 1] = word[strlen(word)];
 
    puts("Enter the word to replace it with :");
    fflush(stdin);
    fgets(replace, 100, stdin);
 
    // removes the newline character from the string
    replace[strlen(replace) - 1] = replace[strlen(replace)];
 
    // comparing word with file
    rewind(ifp);
    while (!feof(ifp)) {
 
        fscanf(ifp, "%s", read);
 
        if (strcmp(read, word) == 0) {
 
            // for deleting the word
            strcpy(read, replace);
        }
 
        // In last loop it runs twice
        fprintf(ofp, "%s ", read);
    }
 
    // Printing the content of the Output file
    rewind(ofp);
    while (1) {
        ch = fgetc(ofp);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
 
    fclose(ifp);
    fclose(ofp);
}
 
// Driver code
int main()
{
    findAndReplaceInFile();
    
    return 0;
}