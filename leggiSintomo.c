/*
 ============================================================================
 Name        : OspitalOS.c
 Author      : Valerio Cietto
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

  #define _GNU_SOURCE
   #include <stdio.h>
   #include <stdlib.h>
#include <time.h>


#include "configurazione.h"
   int
   main(void)
   {
       FILE * fp;
       char * line = NULL;
       size_t len = 0;
       ssize_t read;
       srand(time(NULL));
       printf("NUMERO_ACCESSI");
       int random= (rand()%30);
       fp = fopen("/media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/reparto.txt", "r");
       if (fp == NULL)
           exit(EXIT_FAILURE);
       int indice =0;
       while ((read = getline(&line, &len, fp)) != -1) {
    	   indice++;
    	   if(indice==random){

           printf("%s", line);
           printf("gravità %d", 10-indice%10);
           printf("\n");
           switch(indice%3) {

              case 0  :
                 printf("ortopedia");
                 break;

              case 1  :
                 printf("medicina generale");
                 break;

              case 2  :
                 printf("chirurgia");
                 break;
              default :
            	  printf("reparto non trovato");
           }
    	   }
       }

       fclose(fp);
       if (line)
           free(line);
       exit(EXIT_SUCCESS);
   }


