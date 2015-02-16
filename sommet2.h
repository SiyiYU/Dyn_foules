#ifndef MAILLAGE_DYN_H_INCLUDED
#define MAILLAGE_DYN_H_INCLUDED
#include <iostream>
#include <list> //LIST des indiciduals

using namespace std;
typedef float T; // define T as float

class sommet // means the dynamic mesh
{

    protected:
        int ref;
        float x,y;

    public:
        sommet(); // non init par défaut
        void print_sommet();
        sommet(T abs, T ord, int refer){x = abs; y = ord; ref=refer;}//Interface!!!besoin une fonction ext dans lecture à lire les possition
};

class individual:public sommet
{
    protected:
        int ref = 1;
        T m,r,f_max,g;
//        T v_x,v_y,x_x,x_y;// À calculer
//        T vd_x,vd_y; // is the disire velosity, à calculer aussi

        sommet* voisins; //the table of pointer of voisins

    // on calcul rho dans les maillage.
    public:
        individual(T x, T y, int ref):sommet(x,y,ref){};
        //voisin();// it calcul les voisins dans maillage dynamique
        void allou_individual(T a,T b,T c,T d=9.8){m=a;r=b;f_max=c;g=d;cout<<"alloué"<<endl;};
        //T calcul_fmur(T* maillage_font,T* d_mur);//on trouve lindividual est ou dans le m_font donc sais d_mur
        //void operator ++();// returns arry of pointers of indi nearby
        void print_individual();
        //~individual(){delete voisins[];}
};
#endif// MAILLAGE_DYN_H_INCLUDED
#ifndef SOMMET2_H_INCLUDED
#define SOMMET2_H_INCLUDED



#endif // SOMMET2_H_INCLUDED
