#ifndef MATE_H_INCLUDED
#define MATE_H_INCLUDED
#include <iostream>
#include "lectures/triangle.h"
#include "sommet.h"
#include "lectures/lecture.h"
#include <map>
using namespace std;
typedef float T; // define T as float

//////// On met le maillage au font et triangle les global

extern donnees Donnees;

T* barycent(float x,float y,triangle A, donnees tableaux)//A B C sont 3 sommets des triangles
{
    //cout<<"In the barycent"<<endl;
    sommet pt_a = tableaux.sommets_bk()[A.sommet1()-1];
    //pt_a.print_sommet();
    sommet pt_b = tableaux.sommets_bk()[A.sommet2()-1];
    //pt_b.print_sommet();
    sommet pt_c = tableaux.sommets_bk()[A.sommet3()-1];
    //pt_c.print_sommet();

    T x_a = pt_a.x();
    T x_b = pt_b.x();
    T x_c = pt_c.x();
    T y_a = pt_a.y();
    T y_b = pt_b.y();
    T y_c = pt_c.y();
    T aire_abc = (x_b-x_c)*(y_c-y_a)-(x_c-x_a)*(y_b-y_c);
    T aire_pbc = (y_b-y_c)*(x-x_c)-(x_b-x_c)*(y-y_c);
    T aire_pca = (y_c-y_a)*(x-x_a)-(x_c-x_a)*(y-y_a);
    T aire_pab = (y_a-y_b)*(x-x_b)-(x_a-x_b)*(y-y_b);
    T lambda_A = aire_pbc/aire_abc;
    T lambda_B = aire_pca/aire_abc;
    T lambda_C = aire_pab/aire_abc;
    T* lambda = new float[3];
    lambda[0] = lambda_A;
    lambda[1] = lambda_B;
    lambda[2] = lambda_C;
    //cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
    return lambda;//return un tableau de 3 elements
    //delete []lambda;Ne détuit pas
}

int mate(T x, T y,map<int,int*> map_voisinT,int N_T, triangle* Tri,arete* A, int N_A, int depart = 0)
//entré x,y; sortie num triangle; donné le depart, par défaut 0, N_T le taille des triangles
//ici on met normalmant depart le triangle dans t eme temp
{
    //int N_T = Donnees.tailles_bk()[2];//The size of triangles
    //triangle* Tri = Donnees.triangles_bk();
    cout<<"In the function mate:"<<endl;
    if(depart>N_T){cerr<<"Start with a number surpass the size."<<endl;return -1;}
    else if (depart<0){cerr<<"Start with a number inferier to 0."<<endl;return -1;}
    int now = depart;// int now means now I am in triangle[now]
    triangle Tri_now = Tri[now];
    T* lambda = barycent(x,y,Tri_now,Donnees);//appel barycent
//    arete bord1(Tri_now.sommet2(),Tri_now.sommet3(),3);
//    cout<<"The calcul barycentry of "<<endl;
//    bord1.print();
//    cout<<"Is "<<lambda[0]<<endl;
//    arete bord2(Tri_now.sommet3(),Tri_now.sommet1(),3);
//    cout<<"The calcul barycentry of "<<endl;
//    bord2.print();
//    cout<<"Is "<<lambda[1]<<endl;
//    arete bord3(Tri_now.sommet1(),Tri_now.sommet2(),3);
//    cout<<"The calcul barycentry of "<<endl;
//    bord1.print();
//    cout<<"Is "<<lambda[2]<<endl;
    int num_in_table;// in this period the most important is to find the num_in_table
    map<int,int*>::iterator it;//with constructor 3
    while ((lambda[0]<0)||(lambda[1]<0)||(lambda[2]<0)) //When the point is not in the triangle
    {
        cout<<"Now I am in the "<<now<<"th triangle"<<endl;
        //cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
        //////////////for finding the direction////////////////
        if(lambda[0]<0)//Test bord 1
        {
            //cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
            arete bord1(Tri_now.sommet2(),Tri_now.sommet3(),3);
            num_in_table = find_arete(bord1, A, N_A);
            cout<<"The direction is the 1st bord of triangle, and it's the "<<num_in_table<<"th"<<endl;
            //bord1.print();
            it = map_voisinT.find(num_in_table);
            int* array = it->second;
            cout<<"The bord1 has 2 voisins"<<array[0]<<" "<<array[1]<<endl;
            if(array[0]==now) now=array[1];
            else now = array[0];
            Tri_now = Tri[now];
            lambda = barycent(x,y,Tri_now,Donnees);
            cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
        }

        else if(lambda[1]<0)
        {
            //cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
            triangle Tri_now = Tri[now];
            arete bord2(Tri_now.sommet3(),Tri_now.sommet1(),3);
            num_in_table = find_arete(bord2, A, N_A);
            cout<<"The direction is the 2ed bord of triangle "<<endl;
            it = map_voisinT.find(num_in_table);
            int* array = it->second;
            cout<<"The bord2 has 2 voisins"<<array[0]<<" "<<array[1]<<endl;
            if(array[0]==now) now=array[1];
            else now = array[0];
            lambda = barycent(x,y,Tri_now,Donnees);
            cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
        }
        else//cest frocement(lambda[2]<0)
        {
            //cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
            triangle Tri_now = Tri[now];
            arete bord3(Tri_now.sommet1(),Tri_now.sommet2(),3);
            num_in_table = find_arete(bord3, A, N_A);
            cout<<"The direction is the 3rd bord of triangle "<<endl;
            it = map_voisinT.find(num_in_table);
            int* array = it->second;
            cout<<"The bord3 has 2 voisins"<<array[0]<<" "<<array[1]<<endl;
            if(array[0]==now) now=array[1];
            else now = array[0];
            lambda = barycent(x,y,Tri_now,Donnees);
            cout<<lambda[0]<<" "<<lambda[1]<<" "<<lambda[2]<<" "<<endl;
        }
        if(now == -1) {cerr<<"error:: the triangle arrives out of the edge."<<endl;break;}
        Tri_now = Tri[now];
        //T* lambda = barycent(x,y,Tri_now,Donnees);
        //cout<<"The right position is in the "<<now<<"th triangle"<<endl<<endl;
    }
    cout<<"The point is in the "<<now<<" th triangle"<<endl;
    return now;
}



#endif // MATE_H_INCLUDED
