#include <stdio.h>
#include <time.h>
#define KNRM "\x1B[0m"
#define KYEL "\x1B[33m"
#define KRED "\x1B[31m"
#define NBL 6
#define NBC 7

// Déclaration variables globales:
char tab[NBL][NBC]; // OK pour le compilateur car *tout est déterminé* au moment de compiler
int joueur= 0;// Joueur 1: =joueur = 0;= et Joueur 1: =joueur = 1;=
int l,c;
int start_game;
char token[] = "ox"; // -> token[joueur];
int victory = 0;
int diago = 0;
int choix_joueur = 1;

// INITIALISATION

int init(void){
  printf("\n\n-------------\n");
  for(l=0;l<NBL;l++) {
    for(c=0;c<NBC;c++)   {
      tab[l][c] = '.';
      printf("%c ",tab[l][c]);
    }
    printf("\n");
  }
  printf("\n-------------\n1 2 3 4 5 6 7\n\n");
  return 0;
}

int cond_victoire(void){
  int egalite =0;
  for (l=0;l<NBL;l++){
    for(c=0;c<NBC;c++){
      if(tab[l][c] == tab[l+1][c] && tab[l+1][c] == tab[l+2][c] && tab[l+2][c] == tab[l+3][c] && tab[l][c] != '.' && l<4)
        {
          printf("Félicitation le joueur %d à gagné la partie",(joueur+1));
          victory = 1;
	  choix_joueur=0;
        }
      else if(tab[l][c] == tab[l][c+1] && tab[l][c+1] == tab[l][c+2] && tab[l][c+2] == tab[l][c+3] && tab[l][c] != '.' && c<3){
        printf("Félicitaion le joueur %d à gagné la partie",(joueur+1));
        victory = 1;
	choix_joueur = 0;
      }
      else  if(l<3 && tab[l][c] == tab[l+1][c+1] && tab[l][c] != '.'){
        for(int i=0;i<3;i++){
          if(tab[l][c] == tab[l+i][c+i]){
            diago += 1;
          }
        }
        if (diago ==3){
          printf("Victoire");
	  victory = 1;
	  choix_joueur=0;
        }
      }
      else if(l>3 && tab[l][c] == tab[l-1][c-1] && tab[l][c] != '.'){
        for(int i=0;i<3;i++){
          if(tab[l][c] == tab[l-i][c-i]){
            diago += 1;
          }
        }
        if(diago == 3){
          printf("Victoire");
	  victory = 1;
	  choix_joueur=0;
        }
        else if (l==4 && tab[l][c] == tab[l+1][c+1] && tab[l][c] != '.' || l==4 && tab[l][c] == tab[l-1][c-1] && tab[l][c] != '.'){
          int diago_g = 0;
          int diago_d = 0;
          for (int i=0;i<3;i++){
            if (tab[l][c] == tab[l-i][c-i]){
              diago_g += 1;
            }
            else if (tab[l][c] == tab[l+i][c+i]){
              diago_d +=1;
            }
          }
          if (diago_g == 3 || diago_d ==3){
            printf("victoire");
	    victory = 1;
	    choix_joueur = 0;
          }
        }
        else if(tab[l][c] != '.' && victory == 0){
	  egalite += 1;
	  if(egalite = 42){
	    victory = 2;
	    choix_joueur = 0;
	  }
        }
      }
    }
  }
}


int main(void)   // Boucle principale
{
  while (start_game != 'y')
    {
      printf("Welcome to the game of the CONNECT 4\n\nLes dimensions du plateau du jeu sous la forme : 6x7\n\nStart Game ?\n\n[y] - Yes\n[n] - No\n\n"); // Texte de bienvenue + condition de start
      scanf("%c", &start_game);
    }
  
  // Initialisation de la table du jeu
  
  int table(void)
  {
    // Affichage du plateau
    printf("\n\n-------------\n");
    for(l=0;l<NBL;l++)
      {
	printf("\n");
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
      }
    printf("\n-------------\n1 2 3 4 5 6 7\n\n");
    return 0;
  }
  void change_table(int colonne)
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
		colonne = 10;
	      }
	  }
      }
    table();
  }

  /* boucle de changement de joueur */
  init();
  while(victory != 1)
    {
      if (victory == 2)
	{
	  printf("Egalité \n");
	  break;
	}
      else
	{
	  while(choix_joueur>=1&&choix_joueur<=7)
	    {
	      printf("En avant joueur %d\n", (joueur+1));
	      printf("Saisir le numéro de la colonne\n");
	      scanf("%d",&choix_joueur);
	      change_table(choix_joueur);
	      cond_victoire();
	      joueur = !joueur;
	    }
	}
    }
}
