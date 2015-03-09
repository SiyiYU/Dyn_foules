#include"lecture.h" //tout ce qu'il faut est inclus dans le .h
#include <map>

//using namespace std;


int* lecture_mesh_tailles(const char* file)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture
    int* tailles = new int[3];

    if(fichier) //s'il y a bien ouverture
    {
        //cout<<file<<" is opened"<<endl;
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="Vertices") {getline(fichier,ligne);} //on cherche le mot-clÃ© Vertices

        fichier >> tailles[0]; //on rÃ©cupÃ¨re en lecture la taille du tableau
        //cout<<tailles[0]<<endl; //on l'affiche pour tester

        while(ligne!="Edges") {getline(fichier,ligne);} //on cherche le mot-clÃ© Edges

        fichier >> tailles[1];
        //cout<<tailles[1]<<endl; //on l'affiche pour tester

        while(ligne!="Triangles") {getline(fichier,ligne);} //on cherche le mot-clÃ© Triangles

        fichier >> tailles[2]; //on rÃ©cupÃ¨re le nombre de triangles
        //cout<<tailles[2]<<endl; //affichage pour test

        return(tailles);
        delete [] tailles;

        fichier.close(); //on ferme le fichier
    }
    else //s'il y a eu un probleme a  l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

void lecture_mesh(const char* file, sommet* Vertices, arete* Edges, triangle* Triangles)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture

    if(fichier) //s'il y a bien ouverture
    {
        cout<<file<<" is  opened."<<endl;
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="Vertices"){getline(fichier,ligne);} //on cherche le mot-cle Vertices

        int taille_vertices; //on initialise la taille du tableau des points
        fichier >> taille_vertices; //on recupere en lecture la taille du tableau
        //cout<<taille_vertices<<endl; //on l'affiche pour tester
        float x, y;
        int ref;
        for(int i=0;i<taille_vertices;i++)
        {
            fichier >> x >> y >> ref; //on rÃ©cupÃ¨re les valeurs dans le fichier
            //cout<<x<<" "<<y<<" "<<ref<<endl; //affichage pour test
            Vertices[i] = sommet(x,y,ref); //on construit les sommets avec valeurs
            Vertices[i].Num(i);
            //Vertices[i].print_sommet();
        }

        while(ligne!="Edges"){getline(fichier,ligne);}

        int taille_edge;
        fichier >> taille_edge;
        //cout<<taille_edge<<endl; //on l'affiche pour tester
        int val1, val2, refere;
        for(int i=0;i<taille_edge;i++)
        {
            fichier >> val1 >> val2 >> refere;
            //cout<<val1<<" "<<val2<<" "<<refere<<endl; //affichage pour test
            Edges[i] = arete(val1,val2,refere);
            Edges[i].Num(i);
        }

        while(ligne!="Triangles"){getline(fichier,ligne);}

        int taille_tri;
        fichier >> taille_tri;
        //cout<<taille_tri<<endl; //on l'affiche pour tester
        int v1, v2, v3, r;
        for(int i=0;i<taille_tri;i++)
        {
            fichier >> v1 >> v2 >> v3 >> r;
            //cout<<val1<<" "<<val2<<" "<<val3<<" "<<refere<<endl; //affichage pour test
            Triangles[i] = triangle(v1,v2,v3,r);
            Triangles[i].Num(i);
        }

        fichier.close(); //on ferme le fichier
    }
    else //s'il y a eu un problÃ¨me Ã  l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

float** lecture_sol(const char* file)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture

    if(fichier) //s'il y a bien ouverture
    {
        cout<<file<<" is  opened."<<endl;
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="SolAtVertices"){getline(fichier,ligne);} //on cherche le mot-clÃ© SolAtVertices

        int taille_sol; //on initialise la taille du tableau
        fichier >> taille_sol; //on la rÃ©cupÃ¨re depuis le fichier

        getline(fichier,ligne);
        getline(fichier,ligne);

        float ** Sol = new float*[taille_sol]; //on crÃ©e une matrice avec taille_sol lignes et 2 colonnes
        for(int i=0;i<taille_sol;i++)
        {
            Sol[i] = new float[2];
            fichier >> Sol[i][1] >> Sol[i][2]; //on rÃ©cupÃ¨re les donnÃ©es depuis le fichier
            //cout<< Sol[i][1] << " "<< Sol[i][2]<<endl;
        }

        fichier.close(); //on ferme le fichier
        return(Sol); //on renvoie la matrice
        delete [] Sol; //on supprime la matrice
    }
    else //s'il y a eu un problÃ¨me Ã  l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

/////////////////////construit map map_voisinT//////////////////////////////
//typedef map<arete,int*>::iterator iter; //ce qui est renvoit est le numero de tableau


map<arete,triangle*> construit_map(arete* A,triangle*T, const int T_arete, const int T_tri)
{
    cout<<"In the function construit_map."<<endl;
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
        cout<<"Arete "<<endl;
        A[i].print();
        cout<<" have the triangles "<<endl;
        map_voisinT[A[i]][0].print();
        map_voisinT[A[i]][1].print();


     }//fin de la routine;

    cout<<"Arete "<<endl;
    A[0].print();
    cout<<" have the triangles "<<endl;
    map_voisinT[A[0]][0].print();
    map_voisinT[A[0]][1].print();
    return(map_voisinT);
    delete []array;//delocaliser le tableau
}

map<arete,int*> construit2_map(arete* A,triangle*T, const int T_arete, const int T_tri)
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

map<int,int*> construit3_map(arete* A,triangle*T, const int T_arete, const int T_tri)
{
    //cout<<"In the function construit_map."<<endl;
    map<int,int*> map_voisinT;//the cle is the number of 2 sommets, return int* the number of 2 triangle
    int* array = new int[2]; //allocation dynamique d'un array.
    //int* b = new int[2];
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
        //int* b = new int[2];

        map_voisinT[i]=a;
//        cout<<"Arete "<<endl;
//        A[i].print();
//        cout<<" have the triangles "<<map_voisinT[i][0]<<" "<<map_voisinT[i][1]<<endl;

    }//fin de la routine;
    //cout<<"Fin de la routine."<<endl;
    //cout<<b[0]<<" "<<b[1]<<endl;
    //cout<<"Arete "<<0<<" have the triangles "<<map_voisinT[0][0]<<" "<<map_voisinT[0][1]<<endl;
//    int c[2] = {A[2].sommet1(),A[2].sommet2()};
    //cout<<"Arete "<<2<<" have the triangles "<<map_voisinT[2][0]<<" "<<map_voisinT[2][1]<<endl;

    delete []array;//delocaliser le tableau
    //delete []b;
    return map_voisinT;
}

