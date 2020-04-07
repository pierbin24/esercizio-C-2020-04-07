//in alcune esecuzioni mi entra in loop e non porta a terime il programma
//ho provato a individuare il problema anche con il debug ma non ci riesco



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100
//creo un array di numeri in ordine causale di tanti numeri quanti sono le parole
int *array_ordine_casuale ( int parole){

	int *result = calloc(parole, sizeof(int));

	 if(result == NULL){
	        printf("\ncalloc error!\n");
	        exit(2);
	    }

	int r;

	for(int i = 0; i<parole; i++){
		r=(rand()%parole);
		result[i] = r;

		//controllo che il numero non sia già presente all'interno dell'array
		for (int j=0; j < parole; j++){
			if (result[i]==result[j]){
				i--;
				break;
			}
		}
	}

	return result;
}

int main(int argc, char *argv[]) {

	char stringa[] = "hello world mi chiamo pino sono date delle stringhe";
	char s[] = " ";
	char *token;
	printf("%s\n", stringa);

	token = strtok(stringa, s);

	int parole = 0;
	char *lista[MAX];
	lista[0] = token;
	while (token != NULL ) {

			token = strtok(NULL, s);
			parole++;
			lista[parole]=token;
	   }

	//printf("Le parole all'interno della stringa sono: %d\n", parole);
	int *casuale = array_ordine_casuale(parole);
	for(int i = 0; i<parole; i++){
		int p = casuale[i];
		printf("%s ", lista[p]);
	}
}


