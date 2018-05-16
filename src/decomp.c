#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct{
  char carac;
  uint8_t length;
}table_long, *ptable_long;

ptable_long lire_fichier(const char* file_name){
  FILE* f = fopen(file_name, "r");
  if (!f) {
    printf("Ouverture du fichier impossible. Abandon.\n");
    exit(0);
  }
  
  int c;
  c=(fgetc(f))-'0';
  if (c==EOF){
    printf("Fichier vide. Abandon.\n");
    exit(0);
  }

  ptable_long t=malloc(c*sizeof(table_long)); // a faire quelque part, soit dans la fonction soit en dehors

  for(int h=0; h<c; h++){
      fscanf(f, "%c %hhi", &t[h].carac, &t[h].length);
  }

  int* table = malloc(256 * sizeof(int));

  fclose(f);

  return t;
}

int main(int argc, char const *argv[]){
  ptable_long y=lire_fichier(argv[1]);
  for(int i=0;i<5;i++){
    printf("%c %hhi \n", y[i].carac, y[i].length);
  }
}