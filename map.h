#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <map>
#include "arete.h"
#include "triangle.h"

//void ajouter_entree(arete, triangle*, int*, std::map<arete,triangle*>);
std::map<arete,triangle*> construit_map(arete* A,triangle*T, const int T_arete, const int T_tri);
void construit2_map(arete* A,triangle*T, const int T_arete, const int T_tri);
//std::map<arete, triangle*> create_map(arete*, triangle*, int*);

#endif // MAP_H_INCLUDED
