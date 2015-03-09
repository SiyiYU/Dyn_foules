#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED
#include "sommet.h"
#include "arete.h"
#include "triangle.h"
#include "lecture.h"
#include <map>

class donnees
{
    private:

    int* Tailles_fr;
    sommet* Sommets_fr;
    arete* Aretes_fr;
    triangle* Triangles_fr;
    int* Tailles_bk;
    sommet* Sommets_bk;
    arete* Aretes_bk;
    triangle* Triangles_bk;
    float** Sol;
    map<arete, triangle*> Reper_fr;
    map<arete, triangle*> Reper_bk;

    public:
    //map<int,int*> map_voisinT_fr=construit3_map(Aretes_fr,Triangles_fr, Tailles_fr[1], Tailles_fr[2]);
    map<int,int*> map_voisinT_bk;
    //constructeur
    donnees(const char*, const char*, const char*);

    //accesseurs
    int* tailles_fr() {return(Tailles_fr);}
    sommet* sommets_fr() {return(Sommets_fr);}
    arete* aretes_fr() {return(Aretes_fr);}
    triangle* triangles_fr() {return(Triangles_fr);}
    int* tailles_bk() {return(Tailles_bk);}
    sommet* sommets_bk() {return(Sommets_bk);}
    arete* aretes_bk() {return(Aretes_bk);}
    triangle* triangles_bk() {return(Triangles_bk);}
    float** sol() {return(Sol);}
    map<arete, triangle*> reper_fr() {return(Reper_fr);}
    map<arete, triangle*> reper_bk() {return(Reper_bk);}

    //fonctions de modification
    void ajouter_sommet(float, float);
    void ajouter_arete_fr(arete a);
    void ajouter_arete_bk(arete a);
    void ajouter_triangle(triangle);
    void enlever_triangle(int);
    void update_map(map<arete, triangle*>);

    void inner_aretes_fr();
    void inner_aretes_bk();
    //fonctions d'impression
    void print_map_fr();

};



#endif // DONNEES_H_INCLUDED
