#include <iostream>
#include <fstream>
#include"ecriture.h"

using namespace std;

void create_text(struct donnees D,const char * fichiertxt){
  ofstream fichier(fichiertxt, ios::out | ios::trunc );
  if (fichier){

    fichier<<"MeshVersionFormatted 1"<<endl<<endl;
    fichier<<"Dimension"<<endl<<2<<endl<<endl;

    int N=D.tailles_fr[0];
    fichier<<"Vertices"<<endl<<N<<endl;
    for (int i=0; i<N; i++){
      fichier<<D.Sommets_fr[i].x()<<" "<<D.Sommets_fr[i].y()<<" "<<D.Sommets_fr[i].ref()<<endl;//revoir celon ce qui a été décidé dans la classe sommet
    }

    int M=D.tailles_fr[1];
    fichier<<endl<<"Edges"<<endl<<M<<endl;
    for (int i=0; i<M; i++){
      fichier<<D.Aretes_fr[i].sommet1()<<" "<<D.Aretes_fr[i].sommet2()<<" "<<D.Aretes_fr[i].ref()<<endl;//revoir celon ce qui a été décidé dans la classe arrete
    }

    /*O=D.tailles_bk[2];
    fichier<<endl<<"Triangles"<<endl<<O<<endl;
    for (int i=0; i<O; i++){
      fichier<<D.Triangles_bk[i].sommet1()<<" "<<D.Triangles_bk[i].sommet2()<<" "<<D.Triangles_bk[i].sommet3()<<" "<<D.Triangles_bk[i].ref()<<endl;//revoir celon ce qui a été décidé dans la classe triangle
    }*/

    fichier<<endl<<"End"<<endl;

    fichier.close();
  }
  else{
    cout<<"le fichier n'a pas pu être ouvert, rien n'a été écrit"<<endl;
  }
}
