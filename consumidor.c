/* ########### Trabajo evaluable SSOO ############
   ################## EJ  9 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() dup() pipe() fork() execlp()*/
#include <sys/wait.h> /* wait() */
#include <sys/types.h> /* wait() */
#include <fcntl.h> /* open() */

#define MAXBUFFER 4096

int main(int argc, char *argv[]){
  char buffer[MAXBUFFER];
  int tuberia,c_read;
  
  /* Control del numero de argumentos */
  if(argc != 2){
    fprintf(stderr,"Incorrect number of arguments, use: consumidor <pipe_name>\n");
    _exit(EXIT_FAILURE);
  }
  
  /* Apertura de la tuberia */
  if((tuberia = open(argv[1],O_RDONLY)) == -1){
    printf("Fail to open the pipe %s\n",argv[1]);
    _exit(EXIT_FAILURE);
  }

  /* Creacion del bucle de lectura infinita de la tuberia */
  while(1){
    if((c_read =read(tuberia,buffer,sizeof(buffer)))!= 0){
      write(1,buffer,c_read);
    }
    else{
      buffer[0] = '\0';
    }
    
    sleep(5);
  }
  
  return EXIT_SUCCESS;
}
