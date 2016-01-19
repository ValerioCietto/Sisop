* ospital.c
 *
 *  Created on: Jan 12, 2016
 *      Author: valerio
 */


#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<time.h>
#include <signal.h>

#include</../../media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/configurazione.h>
#define LOGFILE '/../../media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/log.txt'


typedef struct paziente{
	char* sintomo;
	int reparto;
	int gravita;
	pid_t pid;
}paz;

struct paziente creaPaziente(){
	struct paziente p;
	p.sintomo= getSintomo();

	FILE *f = fopen("/../../media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/pazienti.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	int i =0;
	srand(time(NULL));
	int r,z;
	for(i=0;i<100;i++){
		/* print some text */
		srand(time(NULL)+i);
		r=rand()%9999;
		const char *text = getSintomoRandom(i);
		strip(text);
		srand(time(NULL)+i);
		z=rand()%10+1;

		fprintf(f, "%d,", r);
		fprintf(f, "%s,", text);
		fprintf(f, "%d\n", z);

	}
	fclose(f);

	log_to_file("ciao");
	return p;

}

void log_to_file(char* text){
	FILE *f = fopen("/../../media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/log1.txt", "a");
	//FILE *f = fopen("log1.txt", "a");

	if (f == NULL){


		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(f,text);
	fprintf(f,"\n");
	fclose(f);
}

void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
    	if(*s != '\t' && *s != '\n') {
    		*p2++ = *s++;
    	} else {
    		++s;
    	}
    }
    *p2 = '\0';
}

typedef void (*sighandler)(int);
int aperto=1;
void sig_handler(int signo)
{
    if (signo == SIGALRM){
        printf("received SIGalrm\n");
        log_to_file("ciao");
        aperto=0;
    }

}



int main(){
	//sig_handler t;

	printf("%d\n", getpid());
	log_to_file("ciao");

	struct paziente p;
	p=creaPaziente();

	printf(p.sintomo);

	unsigned int time_to_sleep = TEMPO_APERTURA; // aspetta 20sec default
	while(time_to_sleep)
		time_to_sleep = sleep(time_to_sleep);
	puts("tutti a casa!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;

}
