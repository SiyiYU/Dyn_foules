#include "triangle.h"
#include <iostream>

using namespace std;

triangle::triangle()
{
    nb1 = 0;
    nb2 = 0;
    nb3 = 0;
    reference = 0;
}

triangle::triangle(int sommet1, int sommet2, int sommet3, int refer)
{
    nb1 = sommet1;
    nb2 = sommet2;
    nb3 = sommet3;
    reference = refer;
}

void triangle::print()
{
    cout<<nb1<<" "<<nb2<<" "<<nb3<<" "<<reference<<endl;
}
