#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <winsock.h>
#include <MYSQL/mysql.h>

#include "config.h"
#include "bdd.h"

int initSql()
{
    MYSQL connectXml;
    mysql_init(&connectXml);

    mysql_options(&connectXml, MYSQL_READ_DEFAULT_GROUP, "option");
    if(mysql_real_connect(&connectXml, "localhost", "root", "", "xml", 0, NULL, 0))
    {
        printf("Connexion établie\n");
    }
    else
    {
        printf("Erreur de connexion\n");
    }

    mysql_close(&connectXml);

    return 1;
}
