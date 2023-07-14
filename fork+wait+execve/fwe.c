#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){



	pid_t pid;
	pid = fork();

	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	int i = 1;
	if(pid != 0){
	while(i<5){
	i++;
  
	if(pid !=0){
	pid = fork();
	wait(NULL);
	}
	}
	}


	if(pid == 0){
	
	execve(argv[0], argv, NULL);
	}else{
	
		wait(NULL);
		printf("%s\n","done with child");

	}

	return (0);


}
