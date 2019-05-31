#ifndef GERADOR_H
#define GERADOR_H

#include <iostream>
#include <string>

char v[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'};


char *gerador_aleatorio(int tam, int variedade){
	char *vetor = new char[tam + 1];
	for (int i = 0; i < tam; i++){
		vetor[i] = v[rand() % variedade];
	}
	vetor[tam] = '\0';
	return vetor;
}

char *gerador_pior_caso_1(int tam){
	char *vetor = new char[tam + 1];
	for (int i = 0; i < tam - 1; i++){
		vetor[i] = v[0];
	}
	vetor[tam - 1] = v[1];
	vetor[tam] = '\0';
	return vetor;
}

char *gerador_pior_caso_2(int tam){
	char *vetor = new char[tam + 1];
	for (int i = 0; i < tam; i++){
		vetor[i] = v[0];
	}
	vetor[tam] = '\0';
	return vetor;
}

#endif