#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

FILE* secureOpen(char *pathFile, char *mode);
void dbg();
char *smalloc(int num, int size);
int sclose();

#endif // UTILITY_H_INCLUDED
