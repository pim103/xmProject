#ifndef XML_H_INCLUDED
#define XML_H_INCLUDED

int addClient(char *pathFile, char *name, char *firstname, char* action, struct tm *time);
int initXml(char *pathFile);
char *chosenAction();

#endif // XML_H_INCLUDED
