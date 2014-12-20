/* ########### Trabajo evaluable SSOO ############
   ################## EJ  11 #####################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS srand() rand() */
#include <unistd.h> /* _exit() fork() execlp() getpid() sleep() */
#include <sys/wait.h> /* wait() */
#include <sys/types.h> /* getpid() wait() kill() */
#include <signal.h> /* signal() kill() */

#define N_PROC 4

pid_t pidproc[N_PROC];

void finalizarProcesos(int signum);

int main(int argc, char *argv[]){
  int i;
  pid_t chd_pid;

  /* Inicializar matriz */
  for(i = 0; i < N_PROC; i++){
    pidproc[i] = 0;
  }
  
  /* Control del numero de argumentos */
  if(argc != 2){
    fprintf(stderr,"Incorrect number of arguments, use: padre <nmaxsec>\n");
    _exit(EXIT_FAILURE);
  }
  
  /* Instalador del manejador del CTRL + C */
  if(signal(SIGINT,finalizarProcesos) == SIG_ERR){
    fprintf(stderr,"Signal can't be caught\n");
    _exit(EXIT_FAILURE);
  }

  for(i = 0; i < N_PROC; i++){
    switch(chd_pid = fork()){
    case -1:
      fprintf(stderr,"Forking Error\n");
      _exit(EXIT_FAILURE);
    case 0:
      if(execl("./hijo","hijo",argv[1],NULL) == -1){
	fprintf(stderr,"Exec Error\n");
	_exit(EXIT_FAILURE);
      }
      _exit(EXIT_FAILURE);
    default:
      pidproc[i] = chd_pid;
    }
  }

  while(i > 0){
    chd_pid = wait(NULL);
    printf("El proceso %d ha terminado\n",chd_pid);
    i--;
  }

  printf("El proceso padre ha terminado\n");
  return EXIT_SUCCESS;
}

void finalizarProcesos(int signum){
  int i;
  printf("Activated CTRL + C\n");
  printf("Finishing processes\n");
  
  /* Finalizando procesos */
  for(i = 0; i < N_PROC; i++){
    if(pidproc[i] != 0){
      if(kill(pidproc[i],SIGINT) == -1){
	fprintf(stderr,"Impossible to kill %d\n",pidproc[i]);
	_exit(EXIT_FAILURE);
      }
      printf("CTRL + C -->  %d \n",pidproc[i]);
      pidproc[i] = 0;
    }
  }
  _exit(EXIT_FAILURE);
}



  
  
  
