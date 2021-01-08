// Con reales.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0





//void copiar_array(int V[], int V2[], int N);

/*-------------------------------------------------------------------------------
* Módulo que aplica la ordenación por sacudida.
*
* PARÁMETROS:
* 	V: Vector que se va a ordenar
*	N: Número de elementos dentro del vector
* --------------------------------------------------------------------------------*/
void ordenacion_sacudida(int V[], int N)
{		
	int IZQ = 0;
	int DER = N;
	int AUX;

	
	while(IZQ != DER)
	{
		//Pasada de izquierda a derecha. Se van colocando los valores mayores a la derecha del array
		for(unsigned int i = IZQ; i < DER-1; i++)	
		{			
			// En el caso de que el valor anterior sea menor que al actual, cambiamos sus posiciones.			
			if(V[i] > V[i+1])	
			{
				AUX = V[i];
				V[i] = V[i+1];
				V[i+1] = AUX;
			}
		}

		// Reducimos en 1 la posición de lectura, pues los últimos valores del array han quedado fijados.
		DER--;	
		
		if(IZQ != DER)
		{
			//Pasada de derecha a izquierda. Se van colocando los valores menores a la izquierda del array.
			for(unsigned int i = DER-1; i > IZQ; i--)
			{			
				// En el caso de que el valor anterior sea mayor que al actual, cambiamos sus posiciones.		
				if(V[i-1]>V[i])	
				{
					AUX = V[i-1];
					V[i-1] = V[i];
					V[i] = AUX;
				}
			}

			// Sumamos en 1 la posición de inicio, pues los primeros valores del array han quedado fijados.
			IZQ++;	
		}
	}
}

/*-------------------------------------------------------------------------------
* Módulo que aplica la ordenación por sacudida con salto.
* Tomamos los límites IZQ y DER del último intercambio realizado, así si el 
* vector está semiordenado, evitaremos realizar ls iteraciones de esas partes 
* ya ordenadas.
*
* PARÁMETROS:
* 	V: Vector que se va a ordenar
*	N: Número de elementos dentro del vector
* --------------------------------------------------------------------------------*/
void ordenacion_sacudida_salto(int V[], int N)
{		
	int IZQ = 0;
	int DER = N;
	int AUX;
	int K = 0;
	
	while(IZQ < DER)
	{
		//Recorrido de izquierda a derecha. Dejamos los valores más altos a la derecha del vector
		for(unsigned int i = IZQ; i < DER-1; i++)	
		{					
			// En el caso de que el siguiente sea menor, cambiamos sus posiciones.
			if(V[i] > V[i+1])	
			{
				AUX = V[i];
				V[i] = V[i+1];
				V[i+1] = AUX;
				K = i+1;		//En el caso de que haya un cambio, cogemos la siguiente posición de i. Si no hay cambio es que ya está ordenada esa parte
			}
		}

		//Aquí no restamos 1 porque trabajaremos con DER-1 en el for de abajo.
		DER = K; 
		
		if(IZQ < DER)
		{
			//Recorrido de derecha a izquierda.Dejamos los valores mas bajos a la izquierda del vector
			for(unsigned int i = DER-1; i > IZQ; i--) 
			{			
				// En el caso de que el valor anterior sea mayor que al actual, cambiamos sus posiciones.		
				if(V[i-1]>V[i])	
				{
					AUX = V[i-1];
					V[i-1] = V[i];
					V[i] = AUX;
					K = i-1;		//Tomamos el valor de la posición i-1, siempre que se produzca un cambio, si no se produce un cambio es que esa parte ya está ordenada
				}
			}

			//Sumamos 1 a lo adquirido en K, esto es debido a que si i = 0; K = -1; Por lo que nos saldríamos el bucle.
			IZQ = K + 1;	
		}

	}
}

/*-------------------------------------------------------------------------------
* Módulo que aplica la ordenación por sacudida con test.
* Comprobamos si los elementos ya están ordenados, utilizando SEGUIR.
* Si ya están ordenados, no es necesario continuar.
*
* PARÁMETROS:
* 	V: Vector que se va a ordenar
*	N: Número de elementos dentro del vector
* --------------------------------------------------------------------------------*/
void sacudida_test(int V[], int N)
{		
	int IZQ = 0;
	int DER = N;
	int AUX;
	int SEGUIR = VERDADERO;
	
	while(IZQ != DER && (SEGUIR == VERDADERO))
	{
		SEGUIR = FALSO;
		//Recorrido de izquierda a derecha. Los valores mas altos quedan a la derecha del vector
		for(unsigned int i = IZQ; i < DER-1; i++)	
		{				
			// En el caso de que el siguiente sea menor, cambiamos sus posiciones.	
			if(V[i] > V[i+1])	
			{
				AUX = V[i];
				V[i] = V[i+1];
				V[i+1] = AUX;
				SEGUIR = VERDADERO;	// En el caso que nunca se cumpla el if, será falso y terminaremos.
			}
		}

		// Reducimos en 1 la posición de lectura, pues los últimos valores del array han quedado fijados.
		DER--;	
		
		if(IZQ != DER && (SEGUIR == VERDADERO))
		{
			SEGUIR = FALSO;
			//Pasada de derecha a izquierda. Dejamos los valores mas bajos a la izquierda del vector.
			for(unsigned int i = DER-1; i > IZQ; i--)
			{				
				// En el caso de que el valor anterior sea mayor que al actual, cambiamos sus posiciones.	
				if(V[i-1]>V[i])	
				{
					AUX = V[i-1];
					V[i-1] = V[i];
					V[i] = AUX;
					SEGUIR = VERDADERO;	// En el caso que nunca se cumpla el if, será falso y terminaremos.
				}
			}

			// Sumamos en 1 la posición de inicio, pues los primeros valores del array han quedado fijados.
			IZQ++;	
		}
	}
}


/*-------------------------------------------------------------------------------
* Módulo que escribe el vector.
*
* PARÁMETROS:
* 	V: Vector que se va a escribir
*	N: Número de elementos dentro del vector
* --------------------------------------------------------------------------------*/
void escribir_el_vector(int V[], int N)
{
	printf("Vector ordenado: ");
	for(unsigned int itr = 0; itr < N; itr++)
	{
		printf("%d ", V[itr]);
	}
	printf("\n");
}

/*-------------------------------------------------------------------------------
* Módulo que copia el array en otro array.
*
* PARÁMETROS:
* 	V: Vector que se va a copiar
	V2: Vector en el  que se copia V
*	N: Número de elementos dentro del vector
* --------------------------------------------------------------------------------*/
void copiar_array(int V[], int V2[], int N)
{
	for(unsigned int itr = 0; itr < N; itr++)
	{
		V2[itr] = V[itr];
	}
}


void main()
{
	int V[50]; // Array de enteros
	int V2[50]; // Para prueba TEST
	int V3[50];	// PARA prueba en salto.

	char str[105];
	printf("Inserte el array de enteros separados por espacios: ");	
	fgets(str, 105, stdin); // Obtenemos los primeros 105 caracteres escritos.


	 char * pch; // Puntero de dirección a caracter.
  
	 pch = strtok (str," ,"); // strtok corta el char[] si encuentra un espacio o una coma.
				  // Devolverá el puntero del primer dato.

	int numero_datos = 0;

	// Vamos partiendo por espacios y comas hasta que pch sea nulo, es decir
	// hasta que no encuetre más ' ' ó ',' y los va transformando a int y colocandolos en el vector.
	for (numero_datos = 0; pch != NULL; numero_datos++)
	  {
	    V[numero_datos] = atoi(pch); // Atoi convierte array de char en entero.
	    pch = strtok (NULL, " ,");
	  }

	copiar_array(V,V2, 50);
	copiar_array(V,V3, 50);

	//Aplicamos la ordenación por sacudida
	ordenacion_sacudida(V, numero_datos);
	printf("\nSacudida: \n");
	escribir_el_vector(V, numero_datos);

	//Aplicamos la ordenación por sacudida con test
	sacudida_test(V2, numero_datos);
	printf("\nsacudida_test: \n");
	escribir_el_vector(V2, numero_datos);

	//Aplicamos la ordenación por sacudida con salto
	ordenacion_sacudida_salto(V3, numero_datos);
	printf("\nordenacion_sacudida_salto: \n");
	escribir_el_vector(V3, numero_datos);
}
