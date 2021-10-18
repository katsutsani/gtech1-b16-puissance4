#include <stdio.h>
#define NBL 6
#define NBC 7

// Variables globales:
char tab[NBL][NBC]; // OK pour le compilateur car *tout est déterminé* au moment de compiler
int joueur;         // Joueur 1: =joueur = 0;= et Joueur 1: =joueur = 1;=



int init(void)
{
  // Texte de bienvenue

  printf("Bienvenue");
}


int main(void) // Boucle principale
{
  // Initialisation de la table du jeu
  int table(void){
    int l,c;
    // Affichage du plateau
    for(l=0;l<NBL;l++){
      printf("\n");
      for(c=0;c<NBC;c++){
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

// Affichage invité (prompteur) pour le joueur courant

// Saisie du numéro de colonne joué par le joueur courant

// Actualisation de la table du jeu

// [ Optionel: Test du vainqueur ]

// Changement de joueur (c'est le tour de l'autre joueur)
