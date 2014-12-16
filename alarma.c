/* ########### Trabajo evaluable SSOO ############
   ################## EJ  4 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <signal.h> /* Libreria de signal */
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS */
#include <unistd.h> /* _exit(), alarm(), pause()*/

void handler(int sig);

int main(int argc, char *argv[]){
  int n_sec; /* Numero de segundos de alarma */
  int n_msg = 0;

  /* Control numero argumentos */
  if (argc != 2){
    fprintf(stderr,"Invalid number of arguments, use: alarma <seg>\n");
    _exit(EXIT_FAILURE);
  }
  
  /* Controlamos que el numero de mensajes de alarma sea correcto  */
  if((n_sec = atoi(argv[1])) <= 0){
    fprintf(stderr,"Error, invalid number of sec\n");
    _exit(EXIT_FAILURE);
  }

  while (1){

    /* Instalacion del manejador de alarma */
    if (signal(SIGALRM,handler) == SIG_ERR){
      fprintf(stderr,"The signal can't be caught\n");
      _exit(EXIT_FAILURE);
    }

    /* Lanzamiento de la alarma */
    alarm(n_sec);

    /* Esperamos a que se capture la alarma */
    pause();

    /* Mostramos por pantalla que hemos recibido la alarma*/
    printf("Alarma %d\n",++n_msg);

  }

  return EXIT_SUCCESS;

}

void handler(int sig){}
