#include "arete.h"
#include <iostream>

using namespace std;

arete::arete()
{
    nb1 = 0;
    nb2 = 0;
    reference = 0;
}

arete::arete(int sommet1, int sommet2, int refer)
{
    nb1 = sommet1;
    nb2 = sommet2;
    reference = refer;
}

void arete::print()
{
    cout<<nb1<<" "<<nb2<<" "<<reference<<endl;
}
