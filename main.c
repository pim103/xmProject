#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "config.h"
#include "utility.h"
#include "xml.h"

int main(int argc, char **argv)
{
    char name[50];
    char firstname[50];
    char *action;
    char pathFile[50];
    char namePath[50] = "01basti%s%d%s%d%s%d.xml";
    char day[2] = "";
    char month[2] = "";
    char year[2] = "";

    time_t timestamp = time(NULL);
    struct tm *date;
    date = localtime(&timestamp);

    if(date->tm_mday < 10) day[0] = '0';
    if(date->tm_mon < 10) month[0] = '0';
    if(date->tm_year < 10) year[0] = '0';

    sprintf(pathFile, namePath, day, date->tm_mday, month, date->tm_mon, year, (1900+date->tm_year)%100);
    printf("pathFile : %s\n", pathFile);

    do{
        // Ecriture du nom / prénom
        printf("Nom : ");
        fscanf(stdin, "%s", name);
        printf("\nPrenom : ");
        fscanf(stdin, "%s", firstname);

        action = smalloc(5, sizeof(char));
        action = chosenAction();

        //Update time
        timestamp = time(NULL);
        date = localtime(&timestamp);

        //Acces xml
        if(access(pathFile, W_OK && R_OK) == 0)
        {
            addClient(pathFile, name, firstname, action, date);
        }
        else
        {
            initXml(pathFile);
            addClient(pathFile, name, firstname, action, date);
        }
    }while(name != NULL || firstname != NULL);

    return 1;
}
