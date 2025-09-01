/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 24/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"


/* coloque aqui as funções auxiliares que precisar neste arquivo */
void merge(int left, int right, int h, struct racional v[]) {
	//create l[] r[]
	int i, j, t, l_size, r_size;

	l_size = h-left+1;
	r_size = right-h;
	struct racional l[l_size+1], r[r_size+1];

	for (i = 0; i < l_size; i++) 
		l[i] = v[i+left];

	for (i = 0; i < r_size; i++)
		r[i] = v[i+h+1];
	
	l[l_size] = cria_r(10000, 1);
	r[r_size] = cria_r(10000, 1);

	//merge
	i = 0;
	j = 0;
	for (t = left; t <= right; t++) {
		//l[i] < r[j]
		if (compara_r(l[i], r[j]) == -1) {
			v[t] = l[i];
			i++;
		}
		else {
			v[t] = r[j];
			j++;
		}
	}
}

void merge_sort(int left, int right, struct racional v[]) {
	if (left >= right)
		return;
	merge_sort(left, (left + right) / 2, v);
	merge_sort((left + right) / 2 + 1, right, v);
	merge(left, right, (left + right) / 2, v);
}

struct racional soma(int size, struct racional v[]) {

}

/* programa principal */
int main ()
{
  /* a completar! */
	int n, i, max = 100;
	struct racional v[max];
	scanf("%d", &n);
	i = n;
	while(i--) {
		long a, b;
		scanf("%ld %ld", &a, &b);
		v[i] = cria_r(a, b);
	}
	printf("VETOR= ");
	i = n;
	while(i--){
		imprime_r(v[i]);
		printf("  ");
	}
	i = n;
	while(i--){
		if (!valido_r(v[i])) {
			v[i] = v[n - 1];
			n--;
		}
	}
	i = n;
	printf("\nVETOR= ");
	while(i--){
		imprime_r(v[i]);
		printf(" ");
		
	}
	merge_sort(0, n-1, v);
	printf("\nVETOR= ");
	i = n;
	while(i--){
		imprime_r(v[i]);
		printf(" ");
	} 
	printf("\nSOMA=");
	//imprime_r(soma(n, v));
	printf("\n");
    return (0);
}
