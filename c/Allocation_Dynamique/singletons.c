#include <stdlib.h>
#include <stdio.h>

/**
 * Programme qui reçoit une liste de réels et affiche uniquement les valeurs présentes un seule fois dans la liste
*/

int main(void){

    /* Initialisation de la variable qui contiendra la taille de mon tableau */
    double nb_reel = 0;
    /**
     * Initialisation du tableau qui va contenir les réels que je rentre au clavier un par un 
    */
    double *tableau = NULL;
    /**
     * Initialisation de la variable qui va compter les éventuels doublons
    */
    int doublons = 0;

    printf("Combien de réels souhaitez-vous rentrer ?\n");
    scanf("%le",&nb_reel);
    /* Allocation d'un tableau de taille 'nb_reel' qui la taille que je rentre au clavier 
        calloc est un variante à malloc qui initialise toutes les cases à 0
    */
    tableau = (double*) calloc(nb_reel,sizeof(double));

    /**
     * Vérification si le tableau à bien été alloué
    */
    if(tableau){
        int i;
        /* Boucle qui rempli le tableau avec les réels que je rentre un par un */
        for(i = 0; i < nb_reel; i++){
            printf("Entrez un reel : ");
            scanf("%le",&tableau[i]);
        }
        
        int j;
        /**
         * Boucle qui affiche les éléments du tableau qui ne sont présent qu'une fois 
        */
        for(i = 0; i < nb_reel; i++){
            for(j = 0; j < nb_reel; j++){
                if(tableau[i] == tableau[j]){
                    doublons++;
                }
            }
            /**
             * Si le réel actuel n'a pas de doublons, alors on l'affiche
             * Sinon on ne l'affiche pas, on réinitialise la variable doublons à 0
            */
            if(doublons == 1){
                printf("%.2f ",tableau[i]);
            }

            doublons = 0;
        }

        putchar('\n');
        free(tableau);
        return EXIT_SUCCESS;
    }else{
        /**
         * Message d'erreur si le tableau n'a pas bien été alloué
        */
        puts("Espace memoire insuffisant !");
        return EXIT_FAILURE;
    }
}