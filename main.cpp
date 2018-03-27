#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct no{
	unsigned long long int id;
	unsigned long long int prox;
	unsigned long long int ant;
}tNo;

int main() {
	tNo ptr1, ptr2;
	tNo *atual = (tNo *) malloc(sizeof(tNo));
	int cont = 0;
	int flag;

	unsigned long long int id, ant, prox;

	while(scanf("%llx %llx %llx", &id, &ant, &prox) == 3) {
		cont++;
		atual = (tNo *) realloc(atual, cont * sizeof(tNo));

		atual[cont-1].id = id;
		atual[cont-1].ant = ant;
		atual[cont-1].prox = prox;

		if(cont == 1)
			ptr1 = atual[cont-1];
		else if(cont == 2)
			ptr2 = atual[cont-1];
	}

	for(tNo aux = ptr1; aux.id != ptr2.id;) {
		flag = 0;
		for(int i = 0; i < cont; i++) {
			//Verifica se o anterior do próximo é igual ao atual.
			if(aux.prox == atual[i].id && atual[i].ant == aux.id) {
				aux = atual[i];
				flag = 1;
				break;
			}
		}
		if(!flag) //Se flag continuar 0, a lista é de fato insana.
			break;
	}
	if(flag)
		printf("sana\n");
	else
		printf("insana\n");

	return 0;
}
