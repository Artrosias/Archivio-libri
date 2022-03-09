#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 300+1

struct libro{
  char titolo[40];
  int anno_pubblicazione;
  int codice;
}typedef struttura;

int conta(FILE*);
void sort(int, struttura*);
void print (struttura*, int, int, char);
void carica (FILE* , struttura*);
void inverti(int, struttura*);
void sort_data(int, struttura*);

int main(void){
  FILE* fp;
  struttura* libro;
  fp = fopen("libri.txt", "r");
  char scelta = '2';
  int dim;
  int anno_inserito = 0;


  if(fp == NULL){
    printf("errore nella lettura del file\n");
    return 1;
  }

dim = conta(fp);
libro = malloc(dim * sizeof(struttura*));
carica (fp, libro);
fclose(fp);


sort(dim, libro);
print(libro, anno_inserito, dim, scelta);

  do{
    printf("scegliere una delle opzioni seguenti:\n");
    printf("1.visualizza i 2 libri piu' prossimi in base ad un anno a scelta\n");
    printf("2.visualizza elenco invertito\n");
    printf("3.esci\n");
    scanf("%s", &scelta);

    switch(scelta){
      case '1':
        printf("inserire l'anno desiderato\n");
        scanf("%d", &anno_inserito);
        sort_data(dim, libro);
        print(libro, anno_inserito, dim, scelta);
        break;


      case '2':
        inverti(dim, libro);
        print(libro, anno_inserito, dim, scelta);
        break;


      case '3':
        break;


      default:
        printf("scelta non valida");
        break;


    }

  }while(scelta != '3');




  return 0;
}




int conta (FILE* fp) {

    char temp[BUFFERSIZE];
    int i = 0;

    while (!feof(fp)) {

        fgets (temp , BUFFERSIZE , fp);
        i++;
    }


    rewind (fp);
    return (i);
}


void swap (struttura* libro , int j) {

    struttura temp = libro[j];
    libro[j] = libro[j+1];
    libro[j+1] = temp;

}





void sort(int dim , struttura* libro) {

    int flag=1 , i=0;

    while (flag==1) {

        flag=0;
        for (int j = 0; j < dim; j++) {
            if (libro[j].codice > libro[j+1].codice) {
                swap (libro , j);
                flag = 1;

        }
        i++;
    }
  }
}

void print (struttura* libro , int anno_inserito, int dim, char scelta) {
    int c = 0;
    if(scelta == '1'){
      for (int i = 0; i <= dim; i++) {
        if (libro[i].anno_pubblicazione >= anno_inserito) {

            printf("%s %d %d\n\n" , libro[i].titolo, libro[i].anno_pubblicazione,libro[i].codice);
            c++;
        }
        if (c == 2){
          break;
        }
      }
    }
    if(scelta == '2'){
      for(int i = 0; i <= dim; i++){
        printf("%s %d %d\n\n", libro[i].titolo, libro[i].anno_pubblicazione,
            libro[i].codice);

      }
    }

}

void carica (FILE* fp , struttura*libro) {

    int i = 0;
    while (!feof (fp)) {

        fscanf (fp , "%s %d %d" , libro[i].titolo, &libro[i].anno_pubblicazione,
        &libro[i].codice);
        i++;
    }
}

void inverti(int dim, struttura* libro){
    int flag=1 , i=0;

    while (flag==1) {

        flag=0;
        for (int j = 0; j < dim; j++) {
            if (libro[j].codice < libro[j+1].codice) {
                swap (libro , j);
                flag = 1;

        }
        i++;
    }
  }


}


void sort_data(int dim , struttura* libro) {

    int flag=1 , i=0;

    while (flag==1) {

        flag=0;
        for (int j = 0; j < dim; j++) {
            if (libro[j].anno_pubblicazione > libro[j+1].anno_pubblicazione) {
                swap (libro , j);
                flag = 1;

        }
        i++;
    }
  }
}
