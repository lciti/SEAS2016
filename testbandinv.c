#include <stdlib.h>
#include "bandinverse.h"

int main (void) {

  float rho = 0.7;

  int i, j, k, M = 2, N = 3;

  //double U[6] = {0.0, rho, rho, 1.0, 1.0, 1.0 };
  double U[6] = {0,1.0,rho,1.0,rho,1.0};

  double *P = (double *) malloc( ( (M+1)*N ) * sizeof(double) );

  // Print out matrix contents

  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j ++)

      //printf("%d %d \n",i,j);
      printf("%f ",U[j*M + i]);

    printf("\n");

    }

  printf("\n");

  // Test out Luca's function
  bandinverse(P,U,M,N);

  for(i = 0; i < M + 1; i++) {
    for (j = 0; j < N; j++)
      printf("%f ", P[j*(M+1) + i]);

    printf("\n");

  }



  // Clean-up

  free(P);

  return;

}
