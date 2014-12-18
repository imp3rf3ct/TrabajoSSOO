/* ########### Trabajo evaluable SSOO ############
   ################## EJ  8 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() dup() pipe() fork() execlp()*/
#include <sys/wait.h> /* wait() */
#include <sys/types.h> /* wait() */

int main(int argc, char *argv[]){
  int pipefd[2];
  int chd_stat,chd_1,chd_2;
  char *p1,*p2;

  /* Control del numero de argumentos */
  if(argc != 3){
    fprintf(stderr,"Incorrect number of arguments, use: tuberia <p1> <p2>\n");
    _exit(EXIT_FAILURE);
  }

  /* Obtencion de los fd de la pipe */
  if(pipe(pipefd) == -1){
    fprintf(stderr,"Can't create a pipe\n");
    _exit(EXIT_FAILURE);
  }

  /* Obtencion de los programas a ejecutar */
  p1 = argv[1];
  p2 = argv[2];

  /* Creacion y ejecucion de los procesos hijo */
  
  switch(chd_2 = fork()){
  case -1:
    fprintf(stderr,"Forking error\n");
    _exit(EXIT_FAILURE);
  case 0:
    printf("Created %s child %d\n",p2,getpid());

    /* -Cerramos el descriptor de escritura al no ser utilizado
       -Asignamos el descriptor de lectura a la entrada estandar
       -Ejecutamos el programa que espera datos del otro programa */
    close(pipefd[1]);
    close(STDIN_FILENO);
    dup(pipefd[0]);
    close(pipefd[0]);
    execlp(p2,p2,NULL);
    _exit(EXIT_FAILURE);

  default:
    switch(chd_1 = fork()){
    case -1:
      fprintf(stderr,"Forking error\n");
      _exit(EXIT_FAILURE);
    case 0:
      printf("Created %s child %d\n",p1,getpid());

      /* -Cerramos el descriptor de lectura al no ser utilizado
       -Asignamos el descriptor de escritura a la salida estandar
       -Ejecutamos el programa que envia datos al otro programa */
      close(pipefd[0]);
      close(STDOUT_FILENO);
      dup(pipefd[1]);
      close(pipefd[1]);
      execlp(p1,p1,NULL);
      _exit(EXIT_FAILURE);
    }
  }
  /* Cerramos los descriptores de la tuberia */
  close(pipefd[0]); close(pipefd[1]);
  /* Esperamos a que los hijos terminen */
  waitpid(chd_2,&chd_stat,0);
  printf("Child 2 - %d - Has finished with code %d\n",chd_2,chd_stat);
  waitpid(chd_1,&chd_stat,0);
  printf("Child 1 - %d - Has finished with code %d\n",chd_1,chd_stat);
  
  return EXIT_SUCCESS;
}
