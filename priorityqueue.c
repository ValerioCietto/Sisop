#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct { void * data; int pri; } q_elem_t;
typedef struct { q_elem_t *buf; int n, alloc; } pri_queue_t, *pri_queue;

#define priq_purge(q) (q)->n = 1
#define priq_size(q) ((q)->n - 1)
/* first element in array not used to simplify indices */
pri_queue priq_new(int size)
{
  if (size < 4) size = 4;

  pri_queue q = malloc(sizeof(pri_queue_t));
  q->buf = malloc(sizeof(q_elem_t) * size);
  q->alloc = size;
  q->n = 1;

  return q;
}

void priq_push(pri_queue q, void *data, int pri)
{
  q_elem_t *b;
  int n, m;

  if (q->n >= q->alloc) {
    q->alloc *= 2;
    b = q->buf = realloc(q->buf, sizeof(q_elem_t) * q->alloc);
  } else
    b = q->buf;

  n = q->n++;
  /* append at end, then up heap */
  while ((m = n / 2) && pri < b[m].pri) {
    b[n] = b[m];
    n = m;
  }
  b[n].data = data;
  b[n].pri = pri;
}

/* remove top item. returns 0 if empty. *pri can be null. */
void * priq_pop(pri_queue q, int *pri)
{
  void *out;
  if (q->n == 1) return 0;

  q_elem_t *b = q->buf;

  out = b[1].data;
  if (pri) *pri = b[1].pri;

  /* pull last item to top, then down heap. */
  --q->n;

  int n = 1, m;
  while ((m = n * 2) < q->n) {
    if (m + 1 < q->n && b[m].pri > b[m + 1].pri) m++;

    if (b[q->n].pri <= b[m].pri) break;
    b[n] = b[m];
    n = m;
  }

  b[n] = b[q->n];
  if (q->n < q->alloc / 2 && q->n >= 16)
    q->buf = realloc(q->buf, (q->alloc /= 2) * sizeof(b[0]));

  return out;
}

/* get the top element without removing it from queue */
void* priq_top(pri_queue q, int *pri)
{
  if (q->n == 1) return 0;
  if (pri) *pri = q->buf[1].pri;
  return q->buf[1].data;
}

/* this is O(n log n), but probably not the best */
void priq_combine(pri_queue q, pri_queue q2)
{
  int i;
  q_elem_t *e = q2->buf + 1;

  for (i = q2->n - 1; i >= 1; i--, e++)
    priq_push(q, e->data, e->pri);
  priq_purge(q2);
}

int main()
{
printf("init\n");
  int i, p;
  pri_queue q = priq_new(0);
  const char s= ',';
  char *token = "    ";
  char *paziente ="        ";
  char *gravita = " ";
  char *strtoparse;
  const char *y;
  char *pazienti[] ={
	    "6453,febbre,2", "7873,ictus,9", "1345,vomito,5", "9829,diarrea,4", "9091,graffio,0" };
  int k=0;
  for(k=0;k<1;k++){

  		  printf("\t\tfor %d\n",k);

  		  token = strtok("", ",");
  		printf("\t\tfor %d\n",k);
  		  if(k==1){
  			  paziente=token;
  		  }
  		  else if (k==2){
  			  gravita=token;
  		  }
  	  }
  	  printf(" gravita %d",atoi(gravita));
  	  priq_push(q, paziente, 9-atoi(gravita));


  int j=0;
  printf("init for\n");
  for(j=0; j<5;j++){

	  int k=0;
	  printf("\tfor %d\n",j);

	  for(k=0;k<3;k++){

		  printf("\t\tfor %d\n",k);

		  token = strtok(pazienti[j], ",");

		  if(k==1){
			  paziente=token;
		  }
		  else if (k==2){
			  gravita=token;
		  }
	  }
	  printf(" gravita %d",atoi(gravita));
	  priq_push(q, paziente, 9-atoi(gravita));

  }
  const char *c;
  //, *tasks[] ={
  //  "6453,febbre", "7873,ictus", "1345,vomito", "9829,diarrea", "9091,graffio" };
  //int pri[] = { 9-2, 9-9, 9-5, 9-4, 9-0 };




  /* push all 5 tasks into q */
  /*
  for (i = 0; i < 5; i++)
    priq_push(q, tasks[i], pri[i]);
    */
  srand(time(NULL));
  int r;
  /* pop them and print one by one */

  while ((c = priq_pop(q, &p))){
	  r=rand()%2+1;
	  unsigned int time_to_sleep = r; // sleep 10 seconds

	  printf("time to wait %d\n",r);
	  	while(time_to_sleep)
	  	     time_to_sleep = sleep(time_to_sleep);
    printf("%d: %s\n", p, c);

    //TODO incrementa semaforo


  }
  return 0;
}
