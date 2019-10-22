#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t Ticks[2];
    Ticks[0] = clock();
  int TAM;
  scanf("%d", &TAM);
  int vetor[TAM], x, aux = 0, i, j, min;      
  printf("Coloque aqui seu array: \n");
  for( x = 0; x < TAM; x++ ) 
  {
    scanf("%d",&aux);
    vetor[x] = aux;
  }  
  for (i = 0; i < (TAM-1); i++) 
  {
     min = i;
     for (j = (i+1); j < TAM; j++) {
       if(vetor[j] < vetor[min]) 
         min = j;
     }
     if (vetor[i] != vetor[min]) {
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
     }
  }
  for(int x = 0; x < TAM; x++ )
  {
    printf("%d ",vetor[x]); 
  }  
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
    getchar();
    return 0;
}