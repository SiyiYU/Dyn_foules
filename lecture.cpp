#include"lecture.h" //tout ce qu'il faut est inclus dans le .h

using namespace std;

int* lecture_mesh_tailles(const char* file)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture
    int* tailles = new int[2];

    if(fichier) //s'il y a bien ouverture
    {
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="Vertices") {getline(fichier,ligne);} //on cherche le mot-clé Vertices

        fichier >> tailles[0]; //on récupère en lecture la taille du tableau
        //cout<<tailles[0]<<endl; //on l'affiche pour tester

        while(ligne!="Edges") {getline(fichier,ligne);} //on cherche le mot-clé Edges

        fichier >> tailles[1];
        //cout<<tailles[1]<<endl; //on l'affiche pour tester

        return(tailles);
        delete [] tailles;

        fichier.close(); //on ferme le fichier
    }
    else //s'il y a eu un problème à l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

int* lecture_back_mesh_tailles(const char* file)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture
    int* tailles = new int[3];

    if(fichier) //s'il y a bien ouverture
    {
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="Vertices") {getline(fichier,ligne);} //on cherche le mot-clé Vertices

        fichier >> tailles[0]; //on récupère en lecture le nombre de sommets
        //cout<<tailles[0]<<endl; //on l'affiche pour tester

        while(ligne!="Edges") {getline(fichier,ligne);} //on cherche le mot-clé Edges

        fichier >> tailles[1]; //on récupère le nombre d'aretes
        //cout<<tailles[1]<<endl; //on l'affiche pour tester

        while(ligne!="Triangles") {getline(fichier,ligne);} //on cherche le mot-clé Triangles

        fichier >> tailles[2]; //on récupère le nombre de triangles
        cout<<tailles[2]<<endl; //affichage pour test

        return(tailles);
        delete [] tailles;

        fichier.close(); //on ferme le fichier
    }
    else //s'il y a eu un problème à l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

void lecture_mesh(const char* file, sommet* Vertices, arete* Edges)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture

    if(fichier) //s'il y a bien ouverture
    {
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="Vertices"){getline(fichier,ligne);} //on cherche le mot-clé Vertices

        int taille_vertices; //on initialise la taille du tableau des points
        fichier >> taille_vertices; //on récupère en lecture la taille du tableau
        //cout<<taille_vertices<<endl; //on l'affiche pour tester
        float x, y;
        int ref;
        for(int i=0;i<taille_vertices;i++)
        {
            fichier >> x >> y >> ref; //on récupère les valeurs dans le fichier
            //cout<<x<<" "<<y<<" "<<ref<<endl; //affichage pour test
            Vertices[i] = sommet(x,y,ref); //on construit les sommets avec valeurs
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
        }

        fichier.close(); //on ferme le fichier
    }
    else //s'il y a eu un problème à l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

void lecture_back_mesh(const char* file, sommet* Vertices, arete* Edges, triangle* Triangles)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture

    if(fichier) //s'il y a bien ouverture
    {
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="Vertices"){getline(fichier,ligne);} //on cherche le mot-clé Vertices

        int taille_vertices; //on initialise la taille du tableau des points
        fichier >> taille_vertices; //on récupère en lecture la taille du tableau
        //cout<<taille_vertices<<endl; //on l'affiche pour tester
        float x, y;
        int ref;
        for(int i=0;i<taille_vertices;i++)
        {
            fichier >> x >> y >> ref; //on récupère les valeurs dans le fichier
            //cout<<x<<" "<<y<<" "<<ref<<endl; //affichage pour test
            Vertices[i] = sommet(x,y,ref); //on construit les sommets avec valeurs
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
        }

        fichier.close(); //on ferme le fichier
    }
    else //s'il y a eu un problème à l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

float** lecture_sol(const char* file)
{
    ifstream fichier(file, ios::in); //ouverture du fichier en mode lecture

    if(fichier) //s'il y a bien ouverture
    {
        string ligne; //chaine de caractere pour stocker les lignes

        while(ligne!="SolAtVertices"){getline(fichier,ligne);} //on cherche le mot-clé SolAtVertices

        int taille_sol; //on initialise la taille du tableau
        fichier >> taille_sol; //on la récupère depuis le fichier

        getline(fichier,ligne);
        getline(fichier,ligne);

        float ** Sol = new float*[taille_sol]; //on crée une matrice avec taille_sol lignes et 2 colonnes
        for(int i=0;i<taille_sol;i++)
        {
            Sol[i] = new float[2];
            fichier >> Sol[i][1] >> Sol[i][2]; //on récupère les données depuis le fichier
            cout<< Sol[i][1] << " "<< Sol[i][2]<<endl;
        }

        fichier.close(); //on ferme le fichier
        return(Sol); //on renvoie la matrice
        delete [] Sol; //on supprime la matrice
    }
    else //s'il y a eu un problème à l'ouverture du fichier
    cerr<< "Impossible d'ouvrir le fichier"<< endl; //message d'erreur
}

