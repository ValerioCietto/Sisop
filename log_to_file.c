void log_to_file(char* text){
	FILE *f = fopen("LOG_FILE", "a");
	if (f == NULL){
		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(f,text);
	fclose(f);
}
