#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// me trae el codigo hash 
int hash(char *palabra);
// retorna la potencia de un numero
int potencia(int cant,int sobre);
//busca una palabra en el texto, retorna un puntero de la direccion de memoria de la posicion del array
char *buscar(char *palabra,char * texto );
char *creafichero(int cont);
int main(void) {
  FILE *fp; 
  fp = fopen("input.txt", "r");
  char linea[5000];
  char text[5000];
  int i=0;
  int val=0;
  char *palabra;
  char *chares;
  int cont=48;
  char *arra;
  FILE* fichero;
  while ( fgets (linea, 1000, fp) != NULL ) { // Lee el archivo linea por linea
    linea[strcspn(linea, "\r\n")] = 0; // elimina el salto de linea de la palabra
    printf("%d\n",val);
    if (val==0 && i==0 ){
      int con=0;
      chares=malloc(1000);
      strcpy(chares, linea);

      i++;
    }
    else if (val !=0){
      char delim[] = " "; // define como delimitador el espacio para separar cada palabra}
      char *palabra = strtok(linea, delim); // separa linea por delimitador (palabra por palabra) una vez
      while(palabra != NULL){   // recorre palabra a palabra
        if(strcmp(palabra, linea)==0){
          int code=hash(palabra);// retorna el hash de la palbara
          printf("%s %d ", palabra,code);
          fprintf (fichero,"%s %d ",palabra,code);
          char *res=buscar(chares, palabra);
          if(res!= NULL){
            for(int i=0;i<30;i++){
              fprintf (fichero,"%c",res[i]);
              printf("%c",res[i]);
            }
          }
          fputs("...\n",fichero);
          printf("...\n");
        }
        palabra = strtok(NULL, delim);
      }
      printf("while");
      val--;
    }
    else if(*linea <= 57 && *linea >= 48 ){
      val = *linea-48;
      i=0;
      arra=creafichero(cont);
      fichero = fopen ( arra, "wt" );
      cont++;
    }
  }
  free(arra);
  fclose(fichero); // cierra el archivo de entrada 
  fclose(fp); // cierra el archivo de entrada 
  return 0;
}
int hash(char *palabra){
  long int suma=0;
  int contador=0;
  while(palabra[contador]!=0){
    int letra=palabra[contador];
    long int pot=potencia(10,contador+1);
    suma=suma+letra*pot;
    contador++;
  }
  if (suma>= 65536){
    suma= suma % 65536,0;
  }
  return suma;
}
int potencia(int cant,int sobre){
  int num=1;
  for(int i =0;i<sobre-1;i++){
    num=cant*num;
  }
  return num;
}
char *buscar(char *palabra,char *texto ){
  int largo = strlen(palabra);
  int largo2 = strlen(texto);
  char c = texto[0];
  int d = texto[0];
  int len= 0;
  while (largo>=0){
    int acci=palabra[len];
    int conta= 0;
    if(d==acci){
      if (strncmp(&palabra[len],texto,largo2)==0){
        return &palabra[len];
      }
    }
    len++;
    largo--;
  }
  return NULL;
}
char *creafichero(int cont){
  char nom[6]="output";
  char txt[4]=".txt";
  char *ou= &nom[0];
  char *t= &txt[0];
  char *arr= malloc(11);
  for(int i =0; i<11; i++){
    if (i<strlen(nom)){
      arr[i]=*ou; // lleno hasta que esriba output
      ou++;
      printf("%c\n",*ou);

    }else{
      arr[i]=*t;
      t++;
    }
  }
  return arr;
}
