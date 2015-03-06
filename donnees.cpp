#include "lecture.h"
#include "sommet2.h"
#include "triangle.h"
#include "donnees.h"
#include "barycent.h"

float* barycent(float x,float y,triangle A, donnees tableaux)//A B C sont 3 sommets des triangles
{
    sommet pt_a = tableaux.sommets_bk()[A.sommet1()-1];
    sommet pt_b = tableaux.sommets_bk()[A.sommet2()-1];
    sommet pt_c = tableaux.sommets_bk()[A.sommet3()-1];
    float x_a = pt_a.x();
    float x_b = pt_b.x();
    float x_c = pt_c.x();
    float y_a = pt_a.y();
    float y_b = pt_b.y();
    float y_c = pt_c.y();
    float aire_abc = x_b*y_c-x_c*y_b +x_c*y_a-x_a*y_c +x_a*y_b-x_b*y_a;
    T aire_pbc = x_b*y_c-x_c*y_b +x_c*y-x*y_c     +x*y_b-x_b*y;
    float aire_pca = x*y_c-x_c*y     +x_c*y_a-x_a*y_c +x_a*y-x*y_a;
    float aire_pab = x_b*y-x*y_b     +x*y_a-x_a*y     +x_a*y_b-x_b*y_a;
    float lambda_A = aire_pbc/aire_abc;
    float lambda_B = aire_pca/aire_abc;
    float lambda_C = aire_pab/aire_abc;
    float lambda[3];
    lambda[0] = lambda_A;
    lambda[1] = lambda_B;
    lambda[2] = lambda_C;
    return lambda;//return un tableau de 3 elements
}
