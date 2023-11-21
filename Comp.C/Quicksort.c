#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 


void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}


int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	
	troca(vet, pivo_indice, fim);
	
	
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	

	troca(vet, pivo_indice, fim);
	
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}


int main (void) {

  clock_t t;
  int tam1 = 100000;
  int vet[tam1],i;

  for(i=0;i<tam1;i++)
    vet[i]=(rand() %10) + 1;

  t = clock();
  quick_sort(vet, 0, tam1 - 1);
  t = clock()-t;
  double tempo = ((double)t)/CLOCKS_PER_SEC;
  printf("%f segundos se passaram!", tempo);
  }
   

