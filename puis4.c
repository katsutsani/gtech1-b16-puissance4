#include <stdio.h>
#include <time.h>
#define NBL 6
#define NBC 7

// Déclaration variables globales:
char tab[NBL][NBC]; // OK pour le compilateur car *tout est déterminé* au moment de compiler
int joueur; // Joueur 1: =joueur = 0;= et Joueur 1: =joueur = 1;=
int l,c;
int start_game;


// INITIALISATION

//int init(void)



// BOUCLE PRINCIPALE

int main(void)
{
  {
    while (start_game != 'y')
      {
	printf("Welcome to the game of the CONNECT 4\n\nLes dimensions du plateau du jeu sous la forme "<nblignes>x<nbcolonnes>"Start Game ?\n\n[y] - Yes\n[n] - No\n\n"); // Texte de bienvenue + condition de start
	scanf("%c", &start_game);
      }
  }

  // Initialisation de la table du jeu

  int table(void)
  {

    // Affichage du plateau

    for(l=0;l<NBL;l++)
      {
	printf("\n");
	for(c=0;c<NBC;c++)
	  {
	    tab[l][c] = '.';
	    printf("%.1s",tab);
	  }
      }
    printf("\n");
    return 0;
  }
  table();
  return 0;
}
// Affichage invité (prompteur) pour le joueur courant

// Saisie du numéro de colonne joué par le joueur courant

// Actualisation de la table du jeu

// [ Optionel: Test du vainqueur ]
