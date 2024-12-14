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
vector<XoY> a, a2;
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
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1)+
                (y2-y1)*(y2-y1));
}
double get_mean_dist() {
    double sum = 0.0;
    int count = 0;
    for (int i=0; i<a2.size(); ++i) {
        for (int j=i+1; j<a2.size(); ++j) {
            sum+=distance(a2[i].xP, a2[i].yP, 
                          a2[j].xP, a2[j].yP);
            ++count;
        }
    }
    return sum/double(count);
}
int pMOD(int a, int b)
{
    return (a%b<0 ? a+b : a)%b;
}
void p2()
{
    n=101, m=103;
    XoY tmp;
    while (scanf("p=%d,%d v=%d,%d\n", &tmp.xP, &tmp.yP, &tmp.xV, &tmp.yV) != EOF){
        a.push_back(tmp);
        a2.push_back(tmp);
        //printf("%d %d %d %d\n", tmp.xP, tmp.yP, tmp.xV, tmp.yV);
    }
    int sec=0;
    double d1, d2=get_mean_dist();
    do {
        //fout<<d1<<" "<<d2<<endl;
        d1=d2;
        //cout<<sec<<endl;
        ++sec;
        for(int i=0; i<a.size(); ++i){
            a2[i].xP=pMOD((a[i].xP + a[i].xV * sec), n);
            a2[i].yP=pMOD((a[i].yP + a[i].yV * sec), m);
        }
        d2=get_mean_dist();
    } while (d2>d1*0.6);
    fout<<sec;
}
int main()
{
    freopen("date.in", "r", stdin);
    //freopen("date.out", "w", stdout);
    //p1();
    p2();
}