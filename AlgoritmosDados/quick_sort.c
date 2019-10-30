#include <stdio.h>
#include <time.h>

void quicksort(int *vetor, int TAM) {
	int a = 1, b = (TAM - 1), aux01, x = vetor[0];

	if (TAM <= 1) {
		return;
	}

	while (1) {
		while ((a < TAM) && (vetor[a] <= x)) {
			a++;
		}

		while (vetor[b] > x) {
			b--;
		}

		if (a <= b) {
			aux01 = vetor[a];
			vetor[a] = vetor[b];
			vetor[b] = aux01;
			a++;
			b--;
		}

		if (a > b) {
			break;
		}
	}

	vetor[0] = vetor[b];
	vetor[b] = x;

	quicksort(vetor,b);
	quicksort(&vetor[a],(TAM - a));
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
  quicksort(vetor,TAM);

  for (i = 0; i < TAM; i++) {
    printf("%d ", vetor[i]);
  }
  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("\nTempo gasto: %g ms.\n", Tempo);
  getchar();

  return(0);
}
