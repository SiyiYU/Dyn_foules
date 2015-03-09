#ifndef MAILLAGE_DYN_H_INCLUDED
#define MAILLAGE_DYN_H_INCLUDED
#include <iostream>
#include <list> //LIST des indiciduals

using namespace std;
typedef float T; // define T as float

class sommet // means the dynamic mesh
{
    protected:
    int reff;
    float xx,yy;
    int num = -1;

    public:
    void Num(int number){num = number;}
    int Num()const{return num;}
    sommet();
    void print_sommet();
    sommet(T abs, T ord, int refer){xx = abs; yy = ord; reff=refer;}; //Interface!!!besoin une fonction ext dans lecture à lire les possition
    float x()const{return xx;};
    float y()const{return yy;};
    int ref()const{return reff;};
    void changer(float x,float y,int r);
    virtual void changer(float x,float y, float vx, float vy, int r);
    virtual void masse(float);
    virtual void g(float);
    virtual void objectif(float, float);
    sommet & operator=(const sommet & S);
};


class individual:public sommet
{
    protected:
    int reff;//0 pour les individu
    T m,r,f_max,gg;
    T v_x,v_y,xx,xy;// À calculer
    T obj_x, obj_y; // vd=obj-position
    sommet* voisins; //the table of pointer of voisins
    // on calcul rho dans les maillage.
    public:
    void print_individual();
    //~individual(){delete voisins[];}
    //accesseur
    T vx()const{return v_x;};
    T vy()const{return v_y;};
    T objx()const{return obj_x;};
    T objy()const{return obj_y;};
    T masse()const{return m;};
    T gw()const{return gg;};
    //operateurs/initialiseurs
    void masse(float);
    void g(float);
    void objectif(float, float);
    void changer(float, float, float, float, int);//position vitesse ref
};


#endif// MAILLAGE_DYN_H_INCLUDED
#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#endif // SOMMET2_H_INCLUDED
