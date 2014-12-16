/* ########### Trabajo evaluable SSOO ############
   ################## EJ  4 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#define _POSIX_SOURCE /* kill() */

#include <stdio.h>
#include <signal.h> /* Libreria de signal */
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit() */
#include <sys/types.h> /* kill() */


int main(int argc, char *argv[]){
  int p_id, sig;

  /* Control en el numero de argumentos */
  if(argc != 3){
    fprintf(stderr,"Invalid number of arguments, use: mikill <num signal> <pid>\n");
    _exit(EXIT_FAILURE);
  }

  /* Control en la introduccion de la señal */
  if((sig = atoi(argv[1])) <= 0){
    fprintf(stderr,"Invalid signal, try again\n");
    _exit(EXIT_FAILURE);
  }

  /* Control en la introduccion del pid */
  if((p_id = atoi(argv[2])) <= 1){
    fprintf(stderr,"Invalid pid, try again\n");
    _exit(EXIT_FAILURE);
  }

  /* Ejecucion del kill */
  if(kill(p_id,sig) == -1){
    fprintf(stderr,"Can't kill pid %d\n",p_id);
    _exit(EXIT_FAILURE);
  }
  
  printf("Killed pid - %d - with signal - %d -\n",p_id,sig);

  return EXIT_SUCCESS;
}

/* Webgrafia:
   - https://campusvirtual.uclm.es/pluginfile.php/658314/mod_resource/content/1/SSOOI-1415-Tema3-Sesion3.pdf
   
   En las diapositivas de la asignatura se explica la primitiva kill() y es lo que me ha ayudado a hacer el ejercicio */
