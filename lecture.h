#ifndef LECTURE_H_INCLUDED
#define LECTURE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "arete.h"
#include "triangle.h"
#include "../sommet.h"
#include "donnees.h"
#include <map>

using namespace std;

int* lecture_mesh_tailles(const char* file); //renvoie un tableau avec le nombre de sommets, le nombre d'arÃªtes
void lecture_mesh(const char* file, sommet* Vertices, arete* Edges, triangle* Triangles); //permet d'avoir le tableau des sommets et celui des aretes pour le maillage de devant
float** lecture_sol(const char* file); //renvoie le tableau avec les distances au sol

//void inner_aretes(donnees Donnees,arete *A, triangle*T, int T_arete, int T_tri);
map<arete,triangle*> construit_map(arete* A,triangle*T, const int T_arete, const int T_tri);
map<arete,int*> construit2_map(arete* A,triangle*T, const int T_arete, const int T_tri);
map<int,int*> construit3_map(arete* A,triangle*T, const int T_arete, const int T_tri);
//construit le map pour les triangle voisins


#endif // LECTURE_H_INCLUDED
