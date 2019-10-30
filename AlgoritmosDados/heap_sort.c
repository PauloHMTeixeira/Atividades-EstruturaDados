#include <stdio.h>
#include <time.h>

void peneira(int *vetor, int raiz, int fundo) {
  int rdy, filhoG, aux01;

  rdy = 0;
  while ((raiz*2 <= fundo) && (!rdy)) {
    if (raiz*2 == fundo) {
      filhoG = raiz * 2;
    }
    else if (vetor[raiz * 2] > vetor[raiz * 2 + 1]) {
      filhoG = raiz * 2;
    }
    else {
      filhoG = raiz * 2 + 1;
    }

  if (vetor[raiz] < vetor[filhoG]) {
    aux01 = vetor[raiz];
    vetor[raiz] = vetor[filhoG];
    vetor[filhoG] = aux01;
    raiz = filhoG;
    }
  else {
      rdy = 1;
  }
  }
}

void heapsort(int *vetor, int TAM) {
  int i, aux02;

  for (i = (TAM / 2); i >= 0; i--) {
    peneira(vetor, i, TAM - 1);
  }

  for (i = TAM-1; i >= 1; i--) {
    aux02 = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = aux02;
    peneira(vetor, 0, i-1);
  }
}


int main() {
  clock_t Ticks[2];
  Ticks[0] = clock();
  int TAM;
  scanf("%d", &TAM);
  int vetor[TAM], x, y = 0, aux = 0;
  for( x = 0; x < TAM; x++ ) 
  {
    scanf("%d",&aux);
    vetor[x] = aux;
  }  
  int i;
  heapsort(vetor,TAM);

  for (i = 0; i < TAM; i++) {
    printf("%d ", vetor[i]);
  }
  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto: %g ms.\n", Tempo);
  getchar();

  return(0);
}
