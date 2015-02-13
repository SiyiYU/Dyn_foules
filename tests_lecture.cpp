#include <iostream>
#include <fstream>
#include"lecture.h"

using namespace std;

int main()
{
    //sommet som = sommet(1,2,0); //test pour le constructeur de la classe sommet -> ok
    //som.print_sommet();

    //arete a = arete(1,2,3); //test pour le constructeur de la classe arete -> ok
    //a.print();

    //int* tailles;
    //tailles = lecture_mesh_tailles("simple_geo.mesh"); //test pour lecture des tailles -> ok
    //cout<<tailles[0]<<" "<<tailles[1]<<" "<<endl; //affichage pour test

    int* tailles_back;
    tailles_back = lecture_back_mesh_tailles("simple_geo.back.mesh"); //test pour lecture des tailles du fond -> ok
    //cout<<tailles_back[0]<<" "<<tailles_back[1]<<" "<<tailles_back[2]<<endl; //affichage pour test

    //float ** Sol = lecture_sol("simple_geo.dist_wall.sol"); //test pour la lecture du fichier de distance au sol -> ok

    //sommet* Sommets = new sommet[tailles[0]];
    //arete* Aretes = new arete[tailles[1]];
    //lecture_mesh("simple_geo.mesh",Sommets,Aretes); //test lecture du maillage -> ok
    //for(int i=0;i<tailles[0];i++) {Sommets[i].print_sommet();}
    //for(int i=0;i<tailles[1];i++) {Aretes[i].print();}

    sommet* Sommets = new sommet[tailles_back[0]];
    arete* Aretes = new arete[tailles_back[1]];
    triangle* Triangles = new triangle[tailles_back[2]];
    lecture_back_mesh("simple_geo.back.mesh",Sommets,Aretes,Triangles); //test lecture du maillage -> ok
    for(int i=0;i<tailles_back[2];i++) {Triangles[i].print();}

    return 0;
}
