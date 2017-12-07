#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 69
int main(int argc, char* argv[]) {
  //printf("%d", argc);
  int sem_eyedee, N;
  
 
  if (!strcmp(argv[1], "-c")){
    sscanf(argv[2],"%d",&N);
    sem_eyedee = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
    if (sem_eyedee == 0) {
      semctl(sem_eyedee, 0, SETVAL, N);
      printf("semaphore created: %d\n", KEY);
      printf("Value set: %d\n", N);
      
      
    }else{
      printf("yo son! deres something there already\n");
    
    }
  }
  else if(!strcmp(argv[1], "-v")){
    sem_eyedee = semget(KEY ,0,0);
    printf("semaphore value: %d\n", semctl(sem_eyedee, 0, GETVAL));
  }
  else if (!strcmp(argv[1], "-r")) {
    sem_eyedee = semget(KEY, 0, 0);
    printf("semaphore removed: %d\n", semctl(sem_eyedee, 0, IPC_RMID));
  }
  
}
  

	   
  
    
  
  

	   
	   
      
	   
	   

	   
	 
	 
    
	  
  

