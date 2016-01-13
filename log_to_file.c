#define LOG_FILE "/../../media/documents/home/valerio/Programmazione/Eclipse Mars Workspace/OspitalOS/src/log1.txt"

/**
 * log_to_file
 * @param text text to append at the end of the log file
 * LOG_FILE must be defined (default in configuration.h)
 */
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
