#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100
//creo un array di numeri in ordine causale di tanti numeri quanti sono le parole

typedef
	struct {
		char *str[MAX+1];
} string;

string *stringa_finale;

int *array_ordine_casuale ( int parole){

	int *result = malloc(parole*sizeof(int));
	 if(result == NULL){
	        printf("\nmalloc error!\n");
	        exit(2);
	    }

	int r;
	for(int i = 0; i<parole; i++){
		r=((rand()%parole));
		result[i] = r;

		//controllo che il numero non sia già presente all'interno dell'array
		for (int j=0; j < parole; j++){
			if (result[i]==result[j] && i!=j){
				i--;
				j = parole;
			}
		}
	}
	return result;
}


int main(int argc, char *argv[]) {


	char stringa[] = "hello world mi chiamo pino sono date delle stringhe";
	printf("La string iniziale è:\n%s\n", stringa);

	//ora riempio l'array di stringhe che poi stampo in ordine casuale
	char s[] = " ";
	char *token;
	stringa_finale = malloc(MAX * sizeof(char));
	token = strtok(stringa, s);
	stringa_finale->str[0]= token;
	int parole = 1;
	while (token != NULL ) {
			token = strtok(NULL, s);
				if(token != NULL){
					stringa_finale->str[parole]= token;
					parole++;
				}
	}

	//creo l'array che mi serve per l'ordine casuale
	int *ordine;
	ordine = malloc(parole*sizeof(int));
	ordine = array_ordine_casuale(parole);

	printf("La stringa in ricombinata è: \n ");
	int stampa;
	for(int i = 0; i<parole; i++){
		stampa = ordine[i];
		printf("%s ",stringa_finale->str[stampa]);
	}

}

