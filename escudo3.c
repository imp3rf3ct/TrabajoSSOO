/* ########### Trabajo evaluable SSOO ############
   ################## EJ  3 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <signal.h> /* Libreria de signal */
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() */

void handler(int sig);

int main(int argc, char *argv[]){
  int sig;
  
  /* Control de numero de argumentos */
  if(argc != 2){
    fprintf(stderr,"Invalid number of arguments, use: escudo3 <number>\n");
    _exit(EXIT_FAILURE);
  }

  /* Conversion de la señal recibida y control de la misma */
  if((sig = atoi(argv[1])) <= 0){
    fprintf(stderr,"Invalid signal or SIGNULL\n");
    _exit(EXIT_FAILURE);
  }

  /* Bucle infinito */
  while(1){

    /* Instalacion del manejador dentro del bucle infinito */
    if(signal(sig,handler) == SIG_ERR){
      fprintf(stderr,"The signal can't be caught\n");
      _exit(EXIT_FAILURE);
    }

  }

  return EXIT_SUCCESS;
}

void handler(int sig){
  printf("Recibida la señal %d\n",sig);
}
