/* ########### Trabajo evaluable SSOO ############
   ################## EJ  1 ######################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <signal.h> /*Libreria de signal*/
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
  int sig;

  /* Control del numero de argumentos */
  if(argc != 2){
    fprintf(stderr,"Invalid number of arguments, use : escudo1 <signal>\n");
    return EXIT_FAILURE;
  }
  
  /*Control de la señal recibida */
  if (strcmp(argv[1],"SIGINT") == 0){
    sig = 2;
  }
  else if (strcmp(argv[1],"SIGKILL") == 0){
    sig = 9;
  }
  else if (strcmp(argv[1],"SIGSTOP") == 0){
    sig = 19;
  }
  else{
    sig = atoi(argv[1]);
  }

  if(sig <= 0){
    fprintf(stderr,"Invalid signal, or SIGNULL\n");
    return EXIT_FAILURE;
  }
  
  /* Manejador de señales */
  if(signal(sig,SIG_IGN) == SIG_ERR){
    fprintf(stderr,"The signal can't be ignored\n");
    return EXIT_FAILURE;
  }
  
  /*Bucle infinito*/
  while(1) ;
  

  return EXIT_SUCCESS;

}

/* Webgrafia:
   - stackoverflow.com/questions/4014827/best-way-to-switch-on-a-string-in-c
   - unixhelp.ed.ac.uk/CGI/man-cgi?signal+7

   utilizadas tanto para hacer el switch con strings (sucesion de else if) y para controlar las señales mediante enteros. */
    
