#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <omp.h>
constexpr auto TAM = 1000000;

int main()
{
	time_t secs;
	float media, soma = 0, *v;
	int i = 0, r;
	v = (float*)malloc(sizeof(float) * TAM);
	if (v == NULL)
	{
		printf_s("Nao foi possivel alocar memoria!\n");
		r = _getch();
		exit(1);
	}
	for (i = 0; i < TAM; i++)
	{
		secs = time(NULL);
		v[i] = rand() % secs;
	}

	#pragma parallel num_threads(4)
	{
		for (i = 0; i < TAM; i++)
			soma += v[i];
	}
	free(v);
	media = double(soma / TAM);
	printf_s("A media e %.1f\n", media);
	r = _getch();
}







