#include <stdlib.h>
#include <stdio.h>

typedef struct Noeud Noeud;
struct Noeud
{
    int elt;
    Noeud *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Noeud *tete;
};

Liste* liste_vide(){
    Liste* res = (Liste*) malloc(sizeof(Liste));
    res->tete = NULL;
    return res;
}

void ajout_tete(int elt, Liste* liste){
    Noeud* n = (Noeud*) malloc(sizeof(Noeud));
    n->suivant = liste->tete;
    n->elt = elt;
    liste->tete = n;
}

void ajout_queue(int elt, Liste* liste){
    Noeud* cur;
    for(cur = liste->tete; cur->suivant != NULL; cur = cur->suivant);

    Noeud* n = (Noeud*) malloc(sizeof(Noeud));
    n->elt = elt;
    n->suivant = NULL;
    cur->suivant = n;
}

void affichage_liste(Liste* liste){
    Noeud* cur;
    for(cur = liste->tete; cur != NULL; cur = cur->suivant){
        printf("%d ",cur->elt);
    }
    putchar('\n');
}

unsigned short max_value(Liste* liste){
    unsigned short max = 0;

    Noeud* cur;
    for(cur = liste->tete; cur != NULL; cur = cur->suivant){
        if(max < cur->elt){
            max = cur->elt;
        }
    }

    return max;
}

int main(int argc, char const *argv[])
{
    
    Liste* liste = liste_vide();
    ajout_tete((unsigned short)rand()%100+1,liste);
    int i;
    for(i = 0; i < 9; i++){
        ajout_queue((unsigned short) rand()%100+1,liste);
    }
    affichage_liste(liste);
    printf("%u\n",max_value(liste));
    free(liste);
    return 0;
}
