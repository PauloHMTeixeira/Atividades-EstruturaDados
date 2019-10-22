#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t Ticks[2];
    Ticks[0] = clock();
  int TAM;
  scanf("%d", &TAM);
  int vetor[TAM], x, aux = 0, i, key, j;      
  printf("Coloque aqui seu array: \n");
  for( x = 0; x < TAM; x++ ) 
  {
    scanf("%d",&aux);
    vetor[x] = aux;
  }  
  for (i = 1; i < x; i++) { 
        key = vetor[i]; 
        j = i - 1; 
        while (j >= 0 && vetor[j] > key) { 
            vetor[j + 1] = vetor[j]; 
            j = j - 1; 
        } 
        vetor[j + 1] = key;
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