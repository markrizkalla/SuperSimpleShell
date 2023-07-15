#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{

	pid_t pid;
	pid = fork();

	while(pid != 0){
	
		wait(NULL);
		pid = fork();
	}

	char * buffer = malloc(1024);
	size_t len = 1024;

	
        char d[] = " \n";

	if(pid == 0){
	      
		 while(1){

                printf("$ ");

                getline(&buffer , &len , stdin);

               //  buffer[strcspn(buffer, "\n")] = 0;

		char * portion = strtok(buffer,d);
		char * portion2 = strtok(NULL,d);

		printf("%s\n",portion);

		
                char *argv[] = {portion,portion2,NULL};

                      execvp(argv[0], argv);
               }	
	}
	return (0);

}
