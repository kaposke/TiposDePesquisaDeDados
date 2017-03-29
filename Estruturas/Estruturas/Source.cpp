#include <iostream>
#include <fstream>

#define tam 1000

using namespace std;

int buscaSequencial(int vet[], int tamanho, int num)
{
	int tentativas = 0;
	for (int i = 0; i < tamanho; i++)
	{
		tentativas++;
		if (vet[i] == num)
			return tentativas;
	}
}

int buscaBinaria(int vet[], int tamanho, int num)
{
	int tentativas = 0;
	int min = 0; 
	int max = tamanho - 1;
	int meio;
	while (min <= max)
	{
		tentativas++;
		meio = (min + max) / 2;
		if (num == vet[meio])
			return tentativas;
		if (num < vet[meio])
			max = meio - 1;
		else
			min = meio + 1;
	}
	return -1;
}

int main()
{
	int vetor[tam];

	for (int i = 0; i < tam; i++)
	{
		vetor[i] = i;
	}
	ofstream resultados;
	resultados.open("resultados.txt");

	resultados << "s b" << endl;

	for (int i = 0; i < tam; i++)
	{
		resultados << buscaSequencial(vetor, tam, i) << " " << buscaBinaria(vetor, tam, i) << endl;
	}
	
	resultados.close();

	system ("PAUSE");
	return 0;
}