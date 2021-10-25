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
int choix_joueur = 0;
int egalite = 0;
int column_full = 0;

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
  egalite +=1;
  for (l=0;l<NBL;l++){
    for(c=0;c<NBC;c++){
      if(tab[l][c] == tab[l+1][c] && tab[l+1][c] == tab[l+2][c] && tab[l+2][c] == tab[l+3][c] && tab[l][c] != '.' && l<4)
        {
          printf("Congratulations player %d, you have won the game !",(joueur+1));
          victory = 1;
	  break;
        }
      else if(tab[l][c] == tab[l][c+1] && tab[l][c+1] == tab[l][c+2] && tab[l][c+2] == tab[l][c+3] && tab[l][c] != '.' && c<3){
        printf("Congratulations player %d, you have won the game !",(joueur+1));
        victory = 1;
	break;
      }
      else  if(c<3 && l<4 && tab[l][c] == tab[l+1][c+1] && tab[l][c] != '.'){
          if(tab[l][c] == tab[l+1][c+1] && tab[l+1][c+1] == tab[l+2][c+2] && tab[l+2][c+2] == tab[l+3][c+3]){
	    printf("Congratulations player %d, you have won the game !",(joueur+1));
	    victory = 1;
	    break;
	  }
      }
      else if(c>3 && l>4 && tab[l][c] == tab[l-1][c-1] && tab[l][c] != '.'){
          if(tab[l][c] == tab[l-1][c-1]&& tab[l-1][c-1] == tab[l-2][c-2] && tab[l-2][c-2] == tab[l-3][c-3]){
	    printf("Congratulations player %d, you have won the game !",(joueur+1));
	    victory = 1;
	    break;
	  }
        }
      else if(c<3 && l>4 && tab[l][c] == tab[l-1][c+1] && tab[l][c] != '.'){
	if(tab[l][c] == tab[l-1][c+1] && tab[l-1][c+1] == tab[l-2][c+2] && tab[l-2][c+2] == tab[l-3][c+3]){
	  printf("Congratulations player %d, you have won the game !",(joueur+1));
	  victory = 1;
	  break;
	}
      }
      else if(c>3 && l<4 && tab[l][c] == tab[l+1][c-1] && tab[l][c] != '.'){
	if(tab[l][c] == tab[l+1][c-1]&& tab[l-1][c-1] == tab[l+2][c-2] && tab[l+2][c-2] == tab[l+3][c-3]){
	  printf("Congratulations player %d, you have won the game !",(joueur+1));
	  victory = 1;
	  break;
	}
      }
      else if (c==3 && tab[l][c] == tab[l+1][c+1] && tab[l][c] != '.' || c==3 && tab[l][c] == tab[l-1][c-1] && tab[l][c] != '.'|| c==3 && tab[l][c] == tab[l+1][c-1] && tab[l][c] != '.'|| c==3 && tab[l][c] == tab[l-1][c+1] && tab[l][c] != '.'){
	if (l>4 && tab[l][c] == tab[l-1][c-1]&& tab[l-1][c-1] == tab[l-2][c-2] && tab[l-2][c-2] == tab[l-3][c-3]){
	  printf("Congratulations player %d, you have won the game !",(joueur+1));
	  victory = 1;
	  break;
	}
	else if (l<4 && tab[l][c] == tab[l+1][c+1] && tab[l+1][c+1] == tab[l+2][c+2] && tab[l+2][c+2] == tab[l+3][c+3]){
	  printf("Congratulations player %d, you have won the game !",(joueur+1));
	  victory = 1;
	  break;
	}
	else if(l>4 && tab[l][c] == tab[l+1][c-1]&& tab[l+1][c-1] == tab[l+2][c-2] && tab[l+2][c-2] == tab[l+3][c-3]){
	  printf("Congratulations player %d, you have won the game !",(joueur+1));
	  victory = 1;
	  break;
	}
	else if(l<4 && tab[l][c] == tab[l-1][c+1] && tab[l-1][c+1] == tab[l-2][c+2] && tab[l-2][c+2] == tab[l-3][c+3]){
	  printf("Congratulations player %d, you have won the game !",(joueur+1));
	  victory = 1;
	  break;
	}
      }
    }
  }
  if(egalite == 42){
    victory =2;
  }
  choix_joueur = 0;
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
    printf("%s\n-------------\n1 2 3 4 5 6 7\n\n",KNRM);
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
      while(choix_joueur<1 || choix_joueur>7)
	{
	  printf("Your turn player number %d, enter the column number :\n\n", (joueur+1));
	  scanf("%d",&choix_joueur);
	}
      if(choix_joueur){
	column_full = 0;
	for(l=0;l<NBL;l++){
	  if(tab[l][choix_joueur-1] == 'x' || tab[l][choix_joueur-1] == 'o'){
	    column_full +=1;
	  }
	}
	if(column_full == 6){
	  printf("The column selected is already full, please select another one\n");
	  column_full = 0;
	  choix_joueur = 0;
	}
	else{
	  change_table(choix_joueur);
	  cond_victoire();
	  if (victory == 2){
	    printf("Equality \n");
	    break;
	  }
	  else{
	    joueur = !joueur;
	  }
	}
      }     
      else{
	break;
      }
    }
}
