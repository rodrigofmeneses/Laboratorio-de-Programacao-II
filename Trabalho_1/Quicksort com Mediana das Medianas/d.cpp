#include <iostream>
#include <random>
using namespace std;

void troca(int *i, int *j)
{
	int aux;
	aux = *i;
	*i = *j;
	*j = aux;
}

int *particionamento(int *inicio, int *fim, int *pivo)
{
	troca(inicio, pivo);
	pivo = inicio;

	int *i = inicio;
	int *j = i + 1;

	for (; j != fim + 1; j++)
	{
		if (*j < *pivo)
		{
			i++;
			troca(i, j);
		}
	}

	troca(inicio, i);
	return i;
}

void quick_sort(int *inicio, int *fim){

	if(fim > inicio){
		int *pivo = particionamento(inicio, fim, fim);
		quick_sort(inicio, pivo - 1);
		quick_sort(pivo + 1, fim);
	}

}

// Quicksort Mediana -----------------------------------------------------------------

void tri_particionamento(int *inicio, int *fim, int *pivo, int **r, int **s)
{
    troca(inicio, pivo);
    pivo = inicio;

    int *m = inicio;
    int *i = inicio;
    int *j = i + 1;

    for (; j != fim + 1; j++)
    {
        if (*j == *pivo)
        {
            i++;
            troca(i, j);
        }
        if (*j < *pivo)
        {
            m++;
            i++;
            troca(i, j);
            troca(i, m);
        }
    }
    troca(pivo, m);

    *r = m;
    *s = i;
}

void selecao_linear_BFPRT(int *inicio, int *iesimo, int *fim)
{
	if(fim < inicio)
		return;
	
    int k = 0;
    int *segmento = inicio;
	// caso em que v[a...b] >= 5
    while(fim > segmento + 5){
		quick_sort(segmento, segmento + 4);
		troca(inicio + k, segmento + 2); 
		segmento = segmento + 5;
		k++;
	}
	// Caso base, se v[a...b] < 5;
	if(segmento < fim){
		quick_sort(segmento, fim);
		troca(inicio + k, segmento + (fim - segmento) / 2);
		k++;
	}

	selecao_linear_BFPRT(inicio, inicio + k / 2, inicio + k - 1);    

	int *Mediana = inicio;
    int *r = NULL;
    int *s = NULL;
    tri_particionamento(inicio, fim, Mediana, &r, &s);
	
    if (iesimo < r)
        selecao_linear_BFPRT(inicio, iesimo, r - 1);
    if (iesimo > s)
        selecao_linear_BFPRT(s + 1, iesimo, fim);
	
}

void quick_sort_med(int *inicio, int *fim){
	if(fim > inicio){
		selecao_linear_BFPRT(inicio, inicio + (fim - inicio) / 2, fim);
		quick_sort_med(inicio, inicio + (fim - inicio) / 2 - 1);
		quick_sort_med(inicio + (fim - inicio) / 2 + 1, fim);
	}
}


// Fim Quicksort Mediana -------------------------------------------------------------


void imprimir_vetor(int *v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (i % 5 == 0)
			cout << "|";
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Forneca o numero de elementos do vetor maior que 0" << endl;

	int n = -1;
	while (n < 1)
		cin >> n;
	int *v = new int[n];

	cout << "Forneca o intervalo desses" << endl;

	int li = 1, ls = 0;
	while (li > ls)
	{
		cout << "Limite inferior" << endl;
		cin >> li;
		cout << "Limite superior" << endl;
		cin >> ls;
	}

	random_device RD;
	mt19937 ger(RD());
	uniform_int_distribution<int> dis(li, ls);

	for (int i = 0; i < n; ++i)
		v[i] = dis(ger);


	cout << "Vetor inicialmente: ";
	imprimir_vetor(v, n);
	
	quick_sort_med(v, v + n - 1);

	cout << "Vetor apos QuickSort: ";
	imprimir_vetor(v, n);
}

//g++ -Wall -Wextra -std=c++17 -pedantic -o executavel_d d.cpp