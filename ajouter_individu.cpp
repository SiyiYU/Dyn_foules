#include <iostream>
#include <fstream>
#include"lecture.h"
#include"ecriture.h"

void ajouter_individu(float x,float y,struct donnees & D ){
    D.tailles_fr[0]++;
    sommet * S=new sommet[D.tailles_fr[0]];
    for (int i=0; i<(D.tailles_fr[0] -1); i++){
      S[i]=D.Sommets_fr[i];
    }
    S[D.tailles_fr[0] -1].changer(x,y,0);
    sommet * tmp=D.Sommets_fr;
    D.Sommets_fr=S;
    delete [] tmp;

}
