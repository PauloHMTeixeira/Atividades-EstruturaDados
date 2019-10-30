#include <stdio.h>
#include <time.h>

void quicksort(int *vet, int n) {
	int a = 1, b = (n - 1), temp, x = vet[0];

	if (n <= 1) {
		return;
	}

	while (1) {
		while ((a < n) && (vet[a] <= x)) {
			a++;
		}

		while (vet[b] > x) {
			b--;
		}

		if (a <= b) {
			temp = vet[a];
			vet[a] = vet[b];
			vet[b] = temp;
			a++;
			b--;
		}

		if (a > b) {
			break;
		}
	}

	vet[0] = vet[b];
	vet[b] = x;

	quicksort(vet,b);
	quicksort(&vet[a],(n - a));
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