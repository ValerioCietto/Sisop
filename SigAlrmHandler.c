/*
 * signal.c
 *
 *  Created on: Jan 14, 2016
 *      Author: valerio
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);
int aperto=1;
int main()
{
   signal(SIGALRM, sighandler);
   pid_t pidd=getpid();
   while(aperto)
   {
      printf("%d ospedale aperto\n", pidd);
      sleep(1);
   }
   printf("ospedale chiuso");
   return(0);
}

void sighandler(int signum)
{

aperto=0;
   //printf("Caught signal %d, coming out...\n", signum);

}
