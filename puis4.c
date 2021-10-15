#include <stdio.h>

int main(void){
  int tab[7][6];
  int table(void){
    int nbl=6, nbc=7;
    int l,c;
    for(l=0;l<nbl;l++){
      printf("\n");
      for(c=0;c<nbc;c++){
	tab[l][c] = '.';
	printf("%s",tab);
      }
    }
    printf("\n");
    return 0;
  }
  table();
  return 0;
}
