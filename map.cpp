#include "map.h"
#include <iostream>

using namespace std;

/*void ajouter_entree(arete a, triangle* Triangles, int* tailles, map<arete,triangle*> reper)
{
    triangle* val = new triangle[2]; //tableau pour stocker les triangles qui iront dans la map
    int nb = 0; //nombre de fois qu'on trouve un triangle possedant l'arete
    for (int j=0;j<tailles[2];j++) //boucle sur les triangles
    {
        if (Triangles[j].have_edge(a)==true) //si le triangle possede bien l'arete
        {
            val[nb] = Triangles[j]; //on stocke le triangle dans val dans la case associee
            nb = nb+1; //on prend en compte le fait qu'on a vu un triangle
        } //fin du if
    } // for j
    //cout<<"on rentre val"<<" "<<i<<endl;
    cout<<"arete cle"<<endl;
    a.print();
    reper[a] = val;
    cout<<"1er triangle mis dans la map"<<endl;
    reper[a][0].print();
    delete [] val;
}

map<arete,triangle*> create_map(arete* Aretes, triangle* Triangles, int* tailles) //constructeur de la map pour reperer les individus
{
    map<arete,triangle*> reperage; //creation de la map vide
    for (int i=0;i<3/*<tailles[1];i++) //boucle sur les aretes
    {
        ajouter_entree(Aretes[i],Triangles,tailles,reperage);
    }
    cout<<"arete cle"<<endl;
    Aretes[0].print();
    cout<<"1er triangle de la liste precedente"<<endl;
    //reperage[Aretes[0]][0].print();
    return(reperage);
}*/

/*map<arete,triangle*> create_map(arete* Aretes, triangle* Triangles, int* tailles) //constructeur de la map pour reperer les individus
{
    map<arete,triangle*> reperage; //creation de la map vide

    for (int i=0;i<3/*tailles[1];i++) //boucle sur les aretes
    {
        triangle* val = new triangle[2]; //tableau pour stocker les triangles qui iront dans la map
        int nb = 0; //nombre de fois qu'on trouve un triangle possedant l'arete
        for (int j=0;j<tailles[2];j++) //boucle sur les triangles
        {
            if (Triangles[j].have_edge(Aretes[i])==true) //si le triangle possede bien l'arete
            {
                val[nb] = Triangles[j]; //on stocke le triangle dans val dans la case associee
                nb = nb+1; //on prend en compte le fait qu'on a vu un triangle
            } //fin du if
        } // for j
        //cout<<"on rentre val"<<" "<<i<<endl;
        cout<<"arete cle"<<endl;
        Aretes[i].print();
        reperage[Aretes[i]] = val;
        cout<<"1er triangle mis dans la map"<<endl;
        reperage[Aretes[i]][0].print();
        delete [] val; //on desalloue le tableau dynamique
        //val[0].print();
        //val[1].print();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            reperage[Aretes[i]] = val; //pour chaque arete, on rentre la paire de triangles correspondante
    } //for i
    cout<<"arete cle"<<endl;
    Aretes[0].print();
    cout<<"1er triangle de la liste precedente"<<endl;
    reperage[Aretes[0]][0].print();
    return(reperage); //on renvoie la map

} //fin de la fonction*/

map<arete,triangle*> construit_map(arete* A,triangle*T, const int T_arete, const int T_tri)
{
    //cout<<"In the function construit_map."<<endl;
    map<arete,triangle*> map_voisinT;//the cle is the number of 2 sommets, return int* the number of 2 triangle
    triangle* array = new triangle[2]; //allocation dynamique d'un array.

    for(int i=0;i<T_arete;i++)
    {

        triangle* array = new triangle[2]; //allocation dynamique d'un array.
        //array[1] = -1;//give some strange int, because folloing some arete have only one tri
        int k = 0; //means the number of tri in the array.
        for(int j=0;j<T_tri;j++)
        {
            //cout<<"The "<<i<<" th arete is the edge of "<<j<<" th triangle?"<<T[j].have_edge(A[i])<<endl;
            if(T[j].have_edge(A[i])) //if the arete i is the edge of A
            {
                array[k] = T[j];
                k++;
            }
        }
        triangle* t = array;
        map_voisinT[A[i]]=t;
        //cout<<"Arete "<<endl;
        //A[i].print();
        //cout<<" have the triangles "<<endl;
        //map_voisinT[A[i]][0].print();
        //map_voisinT[A[i]][1].print();


     }//fin de la routine;

    //cout<<"Arete "<<endl;
    //A[0].print();
    //cout<<" have the triangles "<<endl;
    //map_voisinT[A[0]][0].print();
    //map_voisinT[A[0]][1].print();
    return(map_voisinT);
    delete []array;//delocaliser le tableau
}

void construit2_map(arete* A,triangle*T, const int T_arete, const int T_tri)
{
    cout<<"In the function construit_map."<<endl;
    map<arete,int*> map_voisinT;//the cle is the number of 2 sommets, return int* the number of 2 triangle
    int* array = new int[2]; //allocation dynamique d'un array.
    for(int i=0;i<T_arete;i++)
    {

        int* array = new int[2]; //allocation dynamique d'un array.
        array[1] = -1;//give some strange int, because folloing some arete have only one tri
        int k = 0; //means the number of tri in the array.
        for(int j=0;j<T_tri;j++)
        {
            //cout<<"The "<<i<<" th arete is the edge of "<<j<<" th triangle?"<<T[j].have_edge(A[i])<<endl;
            if(T[j].have_edge(A[i])) //if the arete i is the edge of A
            {
                array[k] = j;
                k++;
            }
        }
        int* a = array;
        map_voisinT[A[i]]=a;
        cout<<"Arete "<<endl;
        A[i].print();
        cout<<" have the triangles "<<array[0]<<" "<<array[1]<<endl;

    }//fin de la routine;
    cout<<"Arete "<<0<<" have the triangles "<<map_voisinT[A[0]][0]<<" "<<map_voisinT[A[0]][1]<<endl;
    cout<<"Arete "<<2<<" have the triangles "<<map_voisinT[A[2]][0]<<" "<<map_voisinT[A[2]][1]<<endl;

    delete []array;//delocaliser le tableau
}
