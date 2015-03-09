#ifndef AJOUTE_INDIVIDU_CALCU_FORCE_H_INCLUDED
#define AJOUTE_INDIVIDU_CALCU_FORCE_H_INCLUDED
#include <fstream>
#include <cmath>
#include "lectures/lecture.h"
#include "lectures/donnees.h"
#include "mate.h"
typedef float T;

void force_individu(class individual & , float );
T* distance_wall(T x, T y,int depart = 0);


#endif // AJOUTE_INDIVIDU_CALCU_FORCE_H_INCLUDED
