/* ########### Trabajo evaluable SSOO ############
   ################## EJ  10 #####################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() dup() pipe() fork() execlp()*/
#include <sys/stat.h> /* mkfifo() */
#include <sys/types.h> /* mkfifo() */

int main(int argc, char *argv[]){
  /* Variable de los permisos en octal */
  mode_t mode;

  /* Control del numero de argumentos */
  if(argc != 3){
    fprintf(stderr,"Invalid number of arguments, use: mimkfifo <octalperms> <name>\n");
    _exit(EXIT_FAILURE);
  }

  /* Conversion permisos octal */
  sscanf(argv[1],"%o",&mode);

  /* Ejecucion del programa */
  if(mkfifo(argv[2],mode) == -1){
    fprintf(stderr,"Error creating named pipe. Aborting\n");
    _exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}


