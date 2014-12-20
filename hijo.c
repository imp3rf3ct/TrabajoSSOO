/* ########### Trabajo evaluable SSOO ############
   ################## EJ  11 #####################
   ######### CARLOS JESUS CEBRIAN SANCHEZ ########
   ################ 48686394 V ################### */

#include <stdio.h>
#include <stdlib.h> /* Macros EXIT_FAILURE, EXIT_SUCCESS srand() rand() */
#include <sys/types.h> /* getpid() */
#include <unistd.h> /* getpid() */

int main(int argc, char *argv[]){
  int seed,ttslp;

  /* Creando la semilla aleatoria */
  seed = getpid();
  srand(seed);

  /* Creando el numero aleatorio */
  ttslp = 1 + (rand() % atoi(argv[1]));

  printf("Proceso %d duerme %d segundos\n",getpid(),ttslp);

  /* Duerme n segundos */
  sleep(ttslp);
  printf("%d -- finaliza\n",getpid());

  return EXIT_SUCCESS;
}
