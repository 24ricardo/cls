#include "librerias.h"

int kSize=13;

void imprimir_arreglo(int* arreglo, int size) { //recibe el arreglo, su tamaño e imprime
	for(int i=0; i<size; ++i) {
		printf("%d     ", arreglo[i]);
	}
	printf("\n");
	printf("\n");
}


void swap(int* a, int* b){ //cambia los valores,en este void t es temporal tomando que *b es menor que a*
	double t;
	t=*a;
	*a=*b;
	*b=t;
}
int hoare(int a[], int p, int r) { // recibe un arreglo de enteros, y dos enteros con p (inicio) y r(fin)
	int x=a[p]; //entero x se iguala al valor del arreglo a[] posición p
	int i=p-1; //i = p (posición - 1)
	int j=r; //r es tu final de arreglo osea comienza en 13
	while (1) { //si j es = a r
		do j--; 
		while (a[j]>x); //mientras a[] en la posición j es mayor que x
		do i++; //se le incrementa i + 1
		while (a[i]<x); //si a[] en la posición i es menor que x entra a condicionales
		if (i<j) { // si i es menor que j entra a la función swap 
			swap(&a[i], &a[j]); //entra a swap
		} else { 
			return j+1; //j va a ir incrementando para que se acerque al valor de Ksize 
		}
	}
}

void pivote(int a[],int size, int inicio, int fin) { // inicia en  0, son 13 numeros dentro del arreglo, el arreglo esta abajo, es recursiva. 
	int q;
	if (fin-inicio<2) return; // se llama a si misma hasta que el resultado sea 0 o 1 para terminar y empezar a realizar las operaciones correspondientes almacenadas
	q=hoare(a, inicio, fin); //realiza hoare dando el arreglo, 0 y 13
	pivote(a,kSize, inicio, q); //manda a pivote dando arreglo, tamaño total del arreglo, 0 y un entero (**inicio a q**)
	imprimir_arreglo(a, kSize);
	pivote(a,kSize, q, fin); //manda a pivote dando como args arreglo, tamaño total del arreglo, entero y el final (**q al final**)
	imprimir_arreglo(a, kSize); 
}

int main(int argc, char* argv[]) { // main recibe entero, char* []
	int arreglo[] = {8,11,-17,31,8,72,2,13,2,1,12,3,0}; //arreglo
//constructor
	imprimir_arreglo(arreglo, kSize); 
	pivote(arreglo, kSize, 0, kSize);
	imprimir_arreglo(arreglo, kSize);

return 0;
}