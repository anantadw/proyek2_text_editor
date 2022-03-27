#ifndef header_H
#define header_h

FILE *fp, *fp1;
char in, fName[35], pilih, fNew[35];

void TampilanAwal();
void Create();
void Read();
void Edit();
void Delete();
void CopyFile();
void RenameFile();
void ReadInput(FILE *fp);

#endif
