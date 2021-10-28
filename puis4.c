#include <stdio.h>
#include <stdlib.h>
#define KNRM "\x1B[0m"
#define KYEL "\x1B[33m"
#define KRED "\x1B[31m"

// Déclaration variables globales:
char **tab = NULL;
int joueur= 0;// Joueur 1: =joueur = 0;= et Joueur 1: =joueur = 1;=
int l,c,NBL,NBC;
int start_game;
char token[] = "ox"; // -> token[joueur];
int victory = 0;
int diago = 0;
int choix_joueur = 0;
int egalite = 0;
int column_full = 0;

void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

char **tab_malloc() {
  char **tab_ = (char**)malloc(NBL * sizeof(char*));
  for (l = 0; l < NBL; l++)
    tab_[l] = (char*)malloc(NBC * sizeof(char));
  return tab_;
}

// INITIALISATION
int init(){
  for (c=0;c<NBC;c++){
    printf("_  ");
  }
  printf("\n");
  for(l=0;l<NBL;l++) {
    for(c=0;c<NBC;c++)   {
      tab[l][c] = '.';
      printf("%c  ",tab[l][c]);
    }
    printf("\n");
  }
  for (c=0;c<NBC;c++){
    printf("_  ");
  }
  printf("\n\n");
  for(c=0;c<NBC;c++){
    printf ("%02d ",(c+1));
  }
  printf("\n");
  return 0;
}

int table(void) //Affichage du plateau
{
  if(NBC>10){
    for (c=0;c<NBC;c++){
      printf("_  ");
    }
    printf("\n");
    for(l=0;l<NBL;l++)
      {
	for(c=0;c<NBC;c++)
	  {
	    if(tab[l][c] == 'x'){
	      printf("%s%c  ",KRED, tab[l][c]);
	    }
	    else if(tab[l][c] == 'o'){
	      printf("%s%c  ",KYEL,tab[l][c]);
	    }
	    else if(tab[l][c] == '.'){
	      printf("%s%c  ",KNRM,tab[l][c]);
	    }
	  }
	printf("\n");
      }
    for (c=0;c<NBC;c++){
      printf("%s_  ",KNRM);
    }
    printf("\n\n");
    for(c=0;c<NBC;c++){
      printf("%02d ",(c+1));
    }
    printf("\n");
  }
  else{
    for (c=0;c<NBC;c++){
      printf("_  ");
    }
    printf("\n");
    for(l=0;l<NBL;l++)
      {
	for(c=0;c<NBC;c++)
	  {
	    if(tab[l][c] == 'x'){
	      printf("%s%c ",KRED, tab[l][c]);
	    }
	    else if(tab[l][c] == 'o'){
	      printf("%s%c ",KYEL,tab[l][c]);
	    }
	    else if(tab[l][c] == '.'){
	      printf("%s%c ",KNRM,tab[l][c]);
	    }
	  }
	printf("\n");
      }
    for (c=0;c<NBC;c++){
      printf("%s_ ",KNRM);
    }
    printf("\n\n");

    for(c=0;c<NBC;c++){
      printf("%02d \n",(c+1));
    }
  }
}

void change_table(int colonne) //changer les tableau pour entrer le token
{
  for(l=(NBL-1);l>=0;l--)
    {
      for(c=0;c<NBC;c++)
	{
	  if(tab[l][c] == 'x' || tab[l][c] == 'o')
	    {
	      continue;
	    }
	  else if (tab[l][c] == '.' && c != (colonne-1))
	    {
	      tab[l][c] = '.';
	    }
	  else
	    {
	      tab[l][c] = token[joueur];
	      colonne = -1;
	    }
	}
    }
  table();
}

int cond_victoire(void){
  egalite +=1;
  for (l=0;l<(NBL-3);l++){
    for (c=0;c<NBC;c++){
      if (tab[l][c] != '.' && tab[l][c] == tab[l+1][c] && tab[l+1][c] == tab[l+2][c] && tab[l+2][c] == tab[l+3][c]){
	printf("Congratulations player %d, you have won the game !\n",(joueur+1));
	victory = 1;
      }
    }
  }
  for (l=0;l<(NBL-3);l++){
    for (c=0;c<(NBC-3);c++){
      if (tab[l][c] != '.' && tab[l][c] == tab[l+1][c+1] && tab[l+1][c+1] == tab[l+2][c+2] && tab[l+2][c+2] == tab[l+3][c+3]){
	printf("Congratulations player %d, you have won the game !\n",(joueur+1));
	victory = 1;
      }
    }
  }
  for (l=0;l<NBL;l++){
    for (c=0;c<NBC;c++){
      if (tab[l][c] != '.' && tab[l][c] == tab[l][c+1] && tab[l][c+1] == tab[l][c+2] && tab[l][c+2] == tab[l][c+3]){
	printf("Congratulations player %d, you have won the game !\n",(joueur+1));
	victory = 1;
      }
    }
  }
  if(egalite == (NBC*NBL)){
    victory=2;
  }
  choix_joueur = -1;
}


 int main(int argc, char *argv[])   // Boucle principale
{
  if (argc == 3){
    NBL = atoi(argv[1]);
    NBC = atoi(argv[2]);
  } else {
    NBL = 6;
    NBC = 7;
  }
  tab = tab_malloc();
  if(tab != NULL){
    while (start_game != 'y')
      {
	printf("Welcome to the game of the CONNECT 4\n\nLes dimensions du plateau du jeu sous la forme : %dx%d \n\nStart Game ?\n\n[y] - Yes\n[n] - No\n\n",NBL,NBC); // Texte de bienvenue + condition de start
	scanf("%c", &start_game);
      }
    
    // boucle de changement de joueur
    init();
    while(victory != 1)
      {
	while(choix_joueur<1 || choix_joueur>NBC)
	  {
	    printf("\nYour turn player number %d, your token is [%c], enter the column number :\n\n", (joueur+1),token[joueur]);
	    int retour_scanf = scanf("%d",&choix_joueur);
	    flushstdin();
	  }
	column_full = 0;
	for(l=0;l<NBL;l++){
	  if(tab[l][choix_joueur-1] == 'x' || tab[l][choix_joueur-1] == 'o'){
	    column_full +=1;
	  }
	}
	if(column_full == NBL){ //test si la colonne choisie est pleine
	  printf("\nThe column selected is already full, please select another one\n");
	  column_full = 0;
	  choix_joueur = 0;
	}
	else{
	  change_table(choix_joueur);
	  cond_victoire();
 	  if (victory == 2){
	    printf("\nEquality \n");
	    break;
	  }
	  else{
	    joueur = !joueur;
	  }
	}
      }
    free(tab);
    return 0;
  }
}
