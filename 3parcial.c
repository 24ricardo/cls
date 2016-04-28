#include "librerias.h"
#include <memory.h>
#include <stdlib.h>

typedef struct tCell

{
	int payload;
	struct tCell *next;
} Cell;
 
Cell* agregar_nodo(Cell *base, int entrada)
{
	Cell* nodo;
	nodo=malloc(sizeof(Cell));
    if (nodo == NULL) 
    {
        printf("nulo");
        return NULL;
    }
	nodo->payload=entrada;
    nodo->next = NULL;
	Cell* cursor = base;
	while(cursor->next !=NULL)
	{
		cursor=(Cell*)cursor->next;
	}
	cursor->next=nodo;
	return base;
}

void imprime(Cell *root)
{
	while(root->next !=NULL)
	{
		printf("%d ->",root->next->payload);
		root=root->next;
	}
}

void clear ()
{
	int veces;
	for(int j; j<30; j++)
	{
	printf("\n");
	}
}

Cell borra_nodo(Cell *root)
{
	if(root->next==NULL)
		{return *root;}
	Cell* cursor=root;
	while(((Cell*)cursor->next)->next !=NULL)
	{
		cursor=(Cell*)cursor->next;
	}
	free((void *)cursor->next);
	cursor->next=NULL;
	return *root;
}

Cell borra_todo(Cell *celda)
{
	while(celda->next!=NULL)
		borra_nodo(celda);
	return *celda;
}

Cell opciones(Cell *base)
{
	int opcion=0;
	bool evaluar=false;
	int num;
	while(evaluar == false){
		printf(" 0 - Agrega nodo\n 1 - Borra último nodo\n 2 - Imprime lista\n 3 - Salir\nDame una opción: \n ");
		scanf("%d", &opcion);
		clear ();
		if(opcion==0)
		{
			printf("Dame un numero\n ");
			scanf("%d", &num);	
			agregar_nodo(base, num);
			printf("\n");
		} 
		else if(opcion==1)
		{
			printf("Último elemento borrado\n");
			borra_nodo(base);
			printf("\n");
		} 
		else if(opcion==2)
		{
			printf("imprimiendo la lista\n");
			imprime(base);
			printf(" end?\n");
		} 
		else if(opcion==3)
		{
			borra_todo(base);
			evaluar=true;
			printf("\n");
		} 
		else 
		{
			printf("Error al poner numero, introdusca una opción válida\n");
			printf("\n");
		}
	}
	return *base;
}

int main(int argc, char* argv[]) 
{
	Cell *root;
	root = (Cell *)malloc(sizeof(Cell));
	root->payload = -1;
    root->next = NULL;
	opciones(root);
	return 0;
}