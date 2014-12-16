/* ########### Trabajo evaluable SSOO ############
   ################## EJ  6 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <signal.h> /* Libreria de signal */
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() dup() */
#include <sys/stat.h> /* open() */
#include <sys/types.h> /* open() */
#include <fcntl.h> /* open() */

#define MAXPATH 4096

int main(int argc, char *argv[]){
  int fd;
  char path[MAXPATH];

  /* Controlar numero de argumentos */
  if(argc < 3){
    fprintf(stderr,"Invalid number of arguments, use entrada <file> <program> [arg1,arg2,...,argN]\n");
    _exit(EXIT_FAILURE);
  }
  
  /* Creacion del path donde se encuentra todos los datos */
  sprintf(path,"../data/%s",*++argv);

  /* Apertura del archivo de donde se redireccionara a la entrada estandar del programa */
  if((fd = open(path,O_RDONLY)) == -1){
    fprintf(stderr,"Failed to open %s\n",*argv);
    _exit(EXIT_FAILURE);
  }
  
  /* Cierre del descriptor de la entrada estandar */
  close(STDIN_FILENO);

  /* Duplicamos el descriptor del archivo que ahora sera el  mismo que el de la entrada estandar ya que dup elige el menor descriptor posible y al estar cerrado el STDIN_FILENO = 0 pues asignara el 0 */

  dup(fd);

  /* Cierre del descriptor del archivo al estar duplicado */
 
  close(fd);

  /* Ejecucion del programa indicado */

  if(execvp(*++argv,argv) == -1){
    fprintf(stderr,"Fail to execute %s\n",*argv);
    _exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;

}

/* Bibliografia:

   - Manuales de UNIX tanto para dup() como para execvp() */
