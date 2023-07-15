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


	if(pid == 0){
	      
		 while(1){

                printf("$ ");

                getline(&buffer , &len , stdin);

                 buffer[strcspn(buffer, "\n")] = 0;

                char *argv[] = {buffer,NULL,"/usr/",NULL};

                      execve(argv[0], argv, NULL);
               }	
	}
	return (0);

}
