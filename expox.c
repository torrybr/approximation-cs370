//torry brelsford
//pa2
//09/28/2015
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
int main( int argc, char *argv[] )  {
   if( argc == 3 ) {
		double arg1 = atof(argv[1]);
		int arg2 = atoi(argv[2]);
		//arg1 is greater than 1 or less than 0, throw error
		if(arg1 > 1 || arg1<0) {
			printf("Value must be between 0 and 1\n");
			return -1;
		}
		//arg2 is less than 1, throw error
		if(arg2 < 1) {
			return -1;
		} 	
		pid_t pid = fork();
		//CHILD PROCESS
		if(pid == 0 ) {
         execv("expoxch",argv);
		} 
		//PARENT PROCESS
		else if(pid > 0 ) {
			printf ( "Parent : Child’s PID = %d\n", pid);
			int status;
			waitpid(pid, &status, 0);
			//Check EXIT codes for child process
			if( WIFEXITED(status) ) {
				WEXITSTATUS(status);
			}
			if(status == 0) {
				printf("Parent: Child's exit code %i(OK)\n",status);
				printf ( "Parent : Parent (PID = %d): done\n", getpid());	
			} else {
				printf("Parent: Child's exit code %i(error)\n",status);
				printf ( "Parent : Parent (PID = %d): done\n", getpid());
			}
		} else {
			return -1;
		}
		//ERROR if !3 arguments
   } else {
	   printf("Too many/few arguments supplied.\n");
	   return -1;
   }
}
