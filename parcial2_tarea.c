# include <stdio.h>
# include <math.h>
# include <iso646.h>
# include <stdbool.h>

const int kNumerador = 4;
 
double fracciones_p()  // n ova ; por que es el nombre, varible de dominador para suma de fracciones en la operacion
{
double numeros_positivos[17];

	for (int i=1; i<17; ++i)
		{
		numeros_positivos[i]= kNumerador/i;
		}

	double total_positivos= 0 ; 
	for (int i=0; i<16; ++i)
	{
		total_positivos += numeros_positivos[i];// i es donde esta las posiciones
	}
	return total_positivos;
}

double fracciones_n() // varible dominador para resta de fracciones en la operacion
{
double numeros_negativos[16];

	for (int i=0; i<16; ++i)
		{
		numeros_negativos[i]= kNumerador/i;
		}

	double total_negativos= 0 ; 
	for (int i=0; i<15; ++i)
	{
		total_negativos += numeros_negativos[i];// i es donde esta las posiciones
	}
		return total_negativos;
}

int main (int argc, char*argv[])
	{
	double pi;
	double total_positivos= fracciones_p();
	double total_negativos= fracciones_n();
	
	pi= fracciones_p - fracciones_n;
	
	printf("el valor de pi es: ,%lf", pi);

	return 0;
	}

