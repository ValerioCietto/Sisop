#define LOG_FILE "/../../media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/log1.txt"

void log_to_file(char* text){
	FILE *f = fopen(LOG_FILE, "a");
	//FILE *f = fopen("log1.txt", "a");

	if (f == NULL){


		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(f,text);
	fprintf(f,"\n");
	fclose(f);
}
