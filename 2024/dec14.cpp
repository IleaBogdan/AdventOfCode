#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

ofstream fout("date.out");

struct XoY{
    int xP, yP;
    int xV, yV;
};
vector<XoY> a;
int mat[111][111], n, m;
const int iter=100;
bool inMat(int i, int j)
{
    return i>=0 && j>=0 && i<n && j<m;
}
void p1()
{
    n=101, m=103;
    XoY tmp;
    while (scanf("p=%d,%d v=%d,%d\n", &tmp.xP, &tmp.yP, &tmp.xV, &tmp.yV) != EOF){
        a.push_back(tmp);
        //printf("%d %d %d %d\n", tmp.xP, tmp.yP, tmp.xV, tmp.yV);
    }
    int h=0;
    for (auto it:a){
        XoY rob=it;
        cout<<h<<endl;
        printf("%d %d %d %d\n", rob.xP, rob.yP, rob.xV, rob.yV);
        ++h;
        rob.xP=(rob.xP+rob.xV*iter+n*iter)%n;
        rob.yP=(rob.yP+rob.yV*iter+m*iter)%m;
        printf("%d %d %d %d\n", rob.xP, rob.yP, rob.xV, rob.yV);
        ++mat[rob.xP][rob.yP];
    }
    cout<<"stuck";
    long long tot=0, s1=0;
    for (int i=0; i<n/2; ++i){
        for (int j=0; j<m/2; ++j){
            s1+=mat[i][j];
        }
    }
    tot=s1; 
    s1=0;
    for (int i=n/2+1; i<n; ++i){
        for (int j=0; j<m/2; ++j){
            s1+=mat[i][j];
        }
    }
    tot*=s1;
    s1=0;
    for (int i=0; i<n/2; ++i){
        for (int j=m/2+1; j<m; ++j){
            s1+=mat[i][j];
        }
    }
    tot*=s1;
    s1=0;
    for (int i=n/2+1; i<n; ++i){
        for (int j=m/2+1; j<m; ++j){
            s1+=mat[i][j];
        }
    }
    tot*=s1;
    fout<<tot;
}

void p2()
{
    n=101, m=103;
    XoY tmp;
    while (scanf("p=%d,%d v=%d,%d\n", &tmp.xP, &tmp.yP, &tmp.xV, &tmp.yV) != EOF){
        a.push_back(tmp);
        //printf("%d %d %d %d\n", tmp.xP, tmp.yP, tmp.xV, tmp.yV);
    }
    int minSec=0, minim=INT_MAX;
    for (int sec=0; sec<=n*m; ++sec){
        int cadLimX=n/2, cadLimY=m/2;
        int cad[4]={0, 0, 0, 0};
        for (int i=0; i<a.size(); ++i){
            int x=(a[i].xP+a[i].xV*sec+n*sec)%n, 
                y=(a[i].yP+a[i].yV*sec+m*sec)%m;
            if (x<=cadLimX){
                if (y<=cadLimY){
                    ++cad[0];
                } else {
                    ++cad[1];
                }
            } else if (y<=cadLimY){
                ++cad[2];
            } else {
                ++cad[3];
            }
        }
        int prod=cad[0]*cad[1]*cad[2]*cad[3];
        if (minim>prod){
            minim=prod;
            minSec=sec;
        }
    }
    fout<<minSec;
}
int main()
{
    freopen("date.in", "r", stdin);
    //freopen("date.out", "w", stdout);
    //p1();
    p2();
}