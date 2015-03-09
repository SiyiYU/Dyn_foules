#include <iostream>
#include <cmath>
#include <cstdlib>
#include "sommet.h"
using namespace std;
typedef float T;
sommet::sommet(){xx=0;yy=0;reff=0;}
void sommet::print_sommet()
{
    cout<<"Point Number: "<<num<<endl;
    cout<<"Position: ("<<xx<<","<<yy<<")"<<endl;
    //cout<<"Reference: "<<reff<<endl;
}
void individual::print_individual()
{
    cout<<"m,r,f_max,g:"<<endl;
    cout<<m<<"\t"<<r<<"\t"<<f_max<<"\t"<<gg<<endl;
    cout<<"ref = "<<reff<<endl;
}
sommet & sommet::operator=(const sommet & S)
{
    xx=S.x();
    yy=S.y();
    reff=S.ref();
    return *this;
}

void sommet::changer(float x,float y,int r)
{
    xx=x;
    yy=y;
    reff=r;
}

void sommet::changer(float x,float y, float vx, float vy, int r)
{
    xx=x;
    yy=y;
    reff=r;
}

void sommet::masse(float ma)
{
}
void sommet::g(float gw)
{
}
void sommet::objectif(float x, float y)
{
}

void individual::masse(float ma)
{
    m=ma;
}
void individual::g(float gw)
{
    gg=gw;
}
void individual::objectif(float x, float y)
{
    obj_x=x;
    obj_y=y;
}
void individual::changer(float x, float y, float vx, float vy, int reff)
{
    xx=x;
    yy=y;
    v_x=vx;
    v_y=vy;
    reff=r;
}
