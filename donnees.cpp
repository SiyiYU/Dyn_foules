#include "donnees.h"
#include "lecture.h"
#include<iostream>

using namespace std;
donnees::donnees(const char* mesh, const char* back_mesh, const char* sol)
{
  Tailles_fr = lecture_mesh_tailles(mesh);
  Sommets_fr = new sommet[Tailles_fr[0]];
  Aretes_fr = new arete[Tailles_fr[1]];
  Triangles_fr = new triangle[Tailles_fr[2]];
  lecture_mesh(mesh, Sommets_fr, Aretes_fr, Triangles_fr);
  //cout<<" Initialisation du maillage back "<<endl;
  Tailles_bk = lecture_mesh_tailles(back_mesh);
  //cout<<" lecture tailles "<<Tailles_bk[0] << " "<<Tailles_bk[1] << " " <<Tailles_bk[2]<<endl;
  Sommets_bk = new sommet[Tailles_bk [0]];
  //cout<< " alloc sommet back ok "<<endl;
  Aretes_bk = new arete[Tailles_bk [1]];
  //cout<< " alloc aretes back ok "<<endl;
  Triangles_bk = new triangle[Tailles_bk [2]];
  //cout<< " alloc triangles back ok "<<endl;
  lecture_mesh(back_mesh, Sommets_bk , Aretes_bk, Triangles_bk);
  /*cout<< " lecture mesh back ok "<<endl;
  cout<< " premier sommet "<<endl;
  cout<< " dernier sommet "<<endl;
  cout<< " premiere arete "<<endl;
  cout<< " derniere arete "<<endl;
  cout<< " premier triangle "<<endl;
  cout<< " dernier triangle "<<endl;*/
  Sol = lecture_sol(sol);
  //cout<<" **** FIN CONSTRUCTEUR DONNEES PB "<<endl;
}

void donnees::ajouter_sommet(float x, float y)
{
    Tailles_fr[0]++;
    sommet * S = new sommet[Tailles_fr[0]];

    for (int i=0; i<(Tailles_fr[0] -1); i++)
    {
    S[i]=Sommets_fr[i];
    }

    S[Tailles_fr[0] -1].changer(x,y,0);
    sommet * tmp = Sommets_fr;
    Sommets_fr = S;
    delete [] tmp;
}

void donnees::ajouter_individu(float x,float y, struct donnees & D,float objx, float objy, float m, float gw){
    Tailles_fr[0]++;
    sommet * S = new sommet[Tailles_fr[0]];

    for (int i=0; i<(Tailles_fr[0] -1); i++)
    {
    S[i]=Sommets_fr[i];
    }

    S[Tailles_fr[0] -1]=new individual;
    S[Tailles_fr[0] -1].changer(x,y,0,0,0);
    S[Tailles_fr[0] -1].objectif(objx,objy);
    S[Tailles_fr[0] -1].g(gw);
    S[Tailles_fr[0] -1].masse(m);
    sommet * tmp = Sommets_fr;
    Sommets_fr = S;
    delete [] tmp;
}


sommet donnees::sommets_fr(int i){
  return Sommets_fr[i];
}
void donnees::sommets_fr(sommet * s){
  Sommets_fr=s;
}

void donnees::ajouter_arete(arete a)
{
    Tailles_fr[1]++;
    arete * A = new arete[Tailles_fr[1]];

    for (int i=0; i<(Tailles_fr[1] -1); i++)
    {
    A[i]=Aretes_fr[i];
    }

    A[Tailles_fr[1]] = a;
    arete * tmp = Aretes_fr;
    Aretes_fr = A;
    delete [] tmp;
}

void donnees::tailles_fr(int a){
    Tailles_fr[0]=a;
}


void donnees::ajouter_arete(arete a)
{
  Tailles_fr[1]++;
  arete * A = new arete[Tailles_fr[1]];
  for (int i=0; i<(Tailles_fr[1] -1); i++)
  {
    A[i]=Aretes_fr[i];
  }
  A[Tailles_fr[1]] = a;
  arete * tmp = Aretes_fr;
  Aretes_fr = A;
  delete [] tmp;
}


void donnees::ajouter_triangle(triangle t)
{
  Tailles_fr[2]++;
  triangle * T = new triangle[Tailles_fr[2]];
  for (int i=0; i<(Tailles_fr[2] -1); i++)
  {
    T[i]=Triangles_fr[i];
  }
  T[Tailles_fr[2]] = t;
  triangle * tmp = Triangles_fr;
  Triangles_fr = T;
  delete [] tmp;
}


void donnees::ajouter_sommet(float x, float y)
{
    Tailles_fr[0]++;
    sommet * S = new sommet[Tailles_fr[0]];

    for (int i=0; i<(Tailles_fr[0] -1); i++)
    {
    S[i]=Sommets_fr[i];
    }

    S[Tailles_fr[0] -1].changer(x,y,0);
    sommet * tmp = Sommets_fr;
    Sommets_fr = S;
    delete [] tmp;
}

void donnees::ajouter_individu(float x,float y, struct donnees & D,float objx, float objy, float m, float gw){
    Tailles_fr[0]++;
    sommet * S = new sommet[Tailles_fr[0]];

    for (int i=0; i<(Tailles_fr[0] -1); i++)
    {
    S[i]=Sommets_fr[i];
    }

    S[Tailles_fr[0] -1]=new individual;
    S[Tailles_fr[0] -1].changer(x,y,0,0,0);
    S[Tailles_fr[0] -1].objectif(objx,objy);
    S[Tailles_fr[0] -1].g(gw);
    S[Tailles_fr[0] -1].masse(m);
    sommet * tmp = Sommets_fr;
    Sommets_fr = S;
    delete [] tmp;
}


sommet donnees::sommets_fr(int i){
  return Sommets_fr[i];
}
void donnees::sommets_fr(sommet * s){
  Sommets_fr=s;
}

void donnees::ajouter_arete(arete a)
{
    Tailles_fr[1]++;
    arete * A = new arete[Tailles_fr[1]];

    for (int i=0; i<(Tailles_fr[1] -1); i++)
    {
    A[i]=Aretes_fr[i];
    }

    A[Tailles_fr[1]] = a;
    arete * tmp = Aretes_fr;
    Aretes_fr = A;
    delete [] tmp;
}

void donnees::tailles_fr(int a){
    Tailles_fr[0]=a;
}

