#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void){

	char *buffer = malloc(1024);
	size_t len = 1024;

	char **arr = malloc(1024);
	char d[] = " ";

	while(1){
	
		printf("$ ");
		getline(&buffer , &len , stdin);
		char *portion = strtok(buffer,d);
		int i = 0;
		while(portion != NULL){
			arr[i] = portion;
			printf("%s\n", arr[i]);
			portion = strtok(NULL,d);
			i++;
		}

		free(arr);
	
	}



	return (0);

}
