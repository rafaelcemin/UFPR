/* 

 * Arquivo de implementação para TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"



/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
	return rand() % (max - min + 1) + min; 
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
  int temp;
  while (b != 0) {
    a %= b;
    temp = a;
    a = b;
    b = temp;
  }
  if (a > 0)
  	return a;
  return (-1 * a);
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  return (a * b) / mdc (a, b);
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  int max_div;
  if (valido_r(r) == 0)
    	return r;
  max_div = mdc(r.num, r.den);
  r.num /= max_div;
  r.den /= max_div;
  if (r.den < 0) {
    r.num *= -1;
    r.den *= -1;
  }
  return r;
}

/* implemente as demais funções aqui */

struct racional cria_r (long numerador, long denominador) {
	struct racional r;
	r.num = numerador;
	r.den = denominador;
	return r;
}

int valido_r (struct racional r) {
	if (r.den == 0)
		return 0;
	return 1;
}

struct racional sorteia_r (long min, long max) {
	struct racional r;
	r.num = aleat(min, max);
	r.den = aleat(min, max);
	simplifica_r(r);
	return r;
}

void imprime_r (struct racional r) {
	r = simplifica_r(r);
	if (valido_r(r) == 0) {
		printf("INVALIDO");
		return;
	}
	if (r.num == 0) {
		printf("0");
		return;
	}
	if (r.den == 1) {
		printf("%ld", r.num);
		return;
	}
	printf("%ld/%ld", r.num, r.den); 
	//3
}

struct racional soma_r (struct racional r1, struct racional r2) {
	struct racional r;
	r.num = r1.num * r2.den + r2.num * r1.den;
	r.den = r1.den * r2.den;
	return r;
}


struct racional subtrai_r (struct racional r1, struct racional r2) {
	struct racional r;
	r.num = r1.num * r2.den - r2.num * r1.den;
	r.den = r1.den * r2.den;	
	return r;
}

struct racional multiplica_r (struct racional r1, struct racional r2) {
	struct racional r;
	r.num = r1.num * r2.num;
	r.den = r1.den * r2.den;
	return r;
}


struct racional divide_r (struct racional r1, struct racional r2) {
	struct racional r;
	r.num = r1.num * r2.den;
	r.den = r1.den * r2.num;
	return r;
}
