#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t Ticks[2];
    Ticks[0] = clock();
  int TAM;
  scanf("%d", &TAM);
  int vetor[TAM], x, y = 0, aux = 0;      
  printf("Coloque aqui seu array: \n");
  for( x = 0; x < TAM; x++ ) 
  {
    scanf("%d",&aux);
    vetor[x] = aux;
  }  
  for( x = 0; x < TAM; x++ )
  {
    for( y = x + 1; y < TAM; y++ )
    {
      if ( vetor[x] > vetor[y] )
      {
         aux = vetor[x];
         vetor[x] = vetor[y];
         vetor[y] = aux;
      }
    }
  }
  for( x = 0; x < TAM; x++ )
  {
    printf("%d ",vetor[x]); 
  }  
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
    getchar();
    return 0;
}