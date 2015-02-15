#ifndef LECTURE_H_INCLUDED
#define LECTURE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "arete.h"
#include "triangle.h"
#include "sommet2.h"

using namespace std;

struct donnees
{
    int* tailles_fr;
    sommet* Sommets_fr;
    arete* Aretes_fr;

    int* tailles_bk;
    sommet* Sommets_bk;
    arete* Aretes_bk;
    triangle* Triangles_bk;

    float** Sol;
};

int* lecture_mesh_tailles(const char* file); //renvoie un tableau avec le nombre de sommets, le nombre d'arÃªtes
int* lecture_back_mesh_tailles(const char* file); //renvoie un tableau avec le nombre de sommets, le nombre d'arÃªtes et le nombre de triangles
void lecture_mesh(const char* file, sommet* Vertices, arete* Edges); //permet d'avoir le tableau des sommets et celui des aretes pour le maillage de devant
void lecture_back_mesh(const char* file, sommet* Vertices, arete* Edges, triangle* Triangles); //permet d'avoir le tableau des sommets, celui des aretes et celui des triangles pour le maillage de fond
float** lecture_sol(const char* file); //renvoie le tableau avec les distances au sol

struct donnees lecture(const char* mesh, const char* back_mesh, const char* sol);

#endif // LECTURE_H_INCLUDED
