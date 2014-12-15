/* ########### Trabajo evaluable SSOO ############
   ################## EJ  2 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <signal.h> /* Libreria de signal */
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() */

void handler(int sig);

int main(int argc,char *argv[]){
  int sig;
  
  /* Control del numero de argumentos */
  if(argc != 2){
    fprintf(stderr,"Invalid number of arguments, use: escudo2 <number>\n");
    _exit(EXIT_FAILURE);
  }

  /* Conversion de la señal recibida y control de la misma */
  sig = atoi(argv[1]);
  if(sig <= 0){
    fprintf(stderr,"Invalid signal or SIGNULL\n");
    _exit(EXIT_FAILURE);
  }

  /* Instalacion del manejador */
  if(signal(sig,handler) == SIG_ERR){
    fprintf(stderr,"The signal can't be caught\n");
    _exit(EXIT_FAILURE);
  }

  /* Bucle infinito */
  while(1);

  return EXIT_SUCCESS;
}

void handler(int sig){
  printf("Signal received %d\n",sig);
  _exit(EXIT_SUCCESS);
}

/* Webgrafia:
   - www.tutorialspoint.com/c_standard_library/c_function_signal.htm

   para saber que se puede invocar una funcion cuando se maneja la señal */
