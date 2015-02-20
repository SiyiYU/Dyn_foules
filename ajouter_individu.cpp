#include <iostream>
#include <fstream>
#include "lecture.h"
//#include "ecriture.h"

void ajouter_individu(float x,float y, struct donnees & D,float objx, float objy, float m, float gw)
{
    D.tailles_fr[0]++;
    sommet * S=new sommet[D.tailles_fr[0]];

    for (int i=0; i<(D.tailles_fr[0] -1); i++){
      S[i]=D.Sommets_fr[i];
    }

    S[D.tailles_fr[0] -1].changer(x,y,0,0,0);//les individus sont insérés à vitesse nulle v(0)=0
    S[D.tailles_fr[0] -1].g(gw);
    S[D.tailles_fr[0] -1].masse(m);
    S[D.tailles_fr[0] -1].objectif(objx, objy);


    sommet * tmp=D.Sommets_fr;
    D.Sommets_fr=S;
    delete [] tmp;
}


