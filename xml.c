#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <winsock.h>
#include <MYSQL/mysql.h>

#include "config.h"
#include "utility.h"
#include "xml.h"
#include "xml.h"

char balise1[30] = "<lieu nom='Bastille'>";
char balise2[15] = "</lieu>";
char balise3[15] = "<client>";
char balise4[15] = "</client>";
char balise5[15] = "<action>";
char balise6[15] = "</action>";
char balise7[15] = "<date>";
char balise8[15] = "</date>";
char balise9[15] = "<nom>";
char balise10[15] = "</nom>";
char balise11[15] = "<prenom>";
char balise12[15] = "</prenom>";

int addClient(char *pathFile, char *name, char *firstname, char* action, struct tm *date)
{
    int i = 0;
    int j = 0;
    char buffer[1000][500];
    FILE *xmlFile = NULL;

    do{
        xmlFile = secureOpen(pathFile, "rb");
        while(fgets(buffer[i], 2000, xmlFile))
        {
            i++;
        }
        fclose(xmlFile);

        if(i<1)
        {
            xmlFile = secureOpen(pathFile, "wb");
            initXml(pathFile);
            fclose(xmlFile);
        }
    }while(i < 1);

    xmlFile = secureOpen(pathFile, "wb");

    for(j = 0; j < i-1; j++)
    {
        fprintf(xmlFile, "%s", buffer[j]);
        printf("%s", buffer[j]);
    }
    fprintf(xmlFile, "\t%s\n\t\t%s %s %s\n\t\t%s %s %s\n\t\t%s %s %s\n\t\t%s %d:%d:%d %s\n\t%s", balise3, balise9, name, balise10, balise11, firstname, balise12, balise5, action, balise6, balise7, date->tm_hour, date->tm_min, date->tm_sec, balise8, balise4);
    fprintf(xmlFile, "\n%s", buffer[j]);

    fclose(xmlFile);

    return 1;
}

int initXml(char *pathFile)
{
    FILE *xmlFile;
    xmlFile = secureOpen(pathFile, "wb");

    fprintf(xmlFile, "%s", balise1);
    fprintf(xmlFile, "\n%s", balise2);

    fclose(xmlFile);
    return 1;
}

char *chosenAction()
{
    int choiceAction;
    char *action;
    action = smalloc(5, sizeof(char));

    do{
        printf("Entree : 1  || Sortie : 2\n");
        scanf("%d", &choiceAction);
        switch(choiceAction)
        {
            case INPUT:
                strcpy(action, "Entrée");
                break;
            case OUTPUT:
                strcpy(action, "Sortie");
                break;
            default:
                printf("Saisie erronee\n");
        }
    }while(choiceAction < 1 || choiceAction > 2);

    return action;
}
