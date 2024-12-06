#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int di[]={-1, 0, 1, 0}, dj[]={0, 1, 0, -1};
void p1()
{
    vector<string> v;
    string s;
    int i=0, j=0, keep_i=0;
    while (fin>>s){
        v.push_back(s);
        if (s.find('^')!=-1){
            j=s.find('^');
            keep_i=i;
        }
        ++i;
    }
    i=keep_i;
    int k=0;
    int dist_p=0;
    while (i>=0 && j>=0 && i<v.size() && j<v[0].size()){
        dist_p+=bool(v[i][j]!='.');
        cout<<i<<" "<<j<<endl;
        system("PAUSE");
        v[i][j]='X';
        if (v[i+di[k]][j+dj[k]]=='#'){
            k=(k+1)%4;
        }
    }
    fout<<dist_p;
}
vector<string> v;
bool inMat(int i, int j, int k)
{
    return i+di[k]>=0 && 
            i+di[k]<v.size() &&
            j+dj[k]>=0 &&
            j+dj[k]<v[0].size();
}
bool stuck(int i, int j)
{
    int k=0;
    int parc[140][140];
    for (int ii=0; ii<140; ++ii){
        for (int jj=0; jj<140; ++jj){
            parc[ii][jj]=0;
        }
    }
    while (inMat(i, j, k)){
        ++parc[i][j];;
        if (parc[i][j]>=10)return true;
        if (v[i+di[k]][j+dj[k]]=='#'){
            ++k;
            k%=4;
        }
        i+=di[k], j+=dj[k];
    }
    return false;
}
void p2()
{
    string s;
    int i=0, j=0, keep_i=0;
    while (fin>>s){
        v.push_back(s);
        if (s.find('^')!=-1){
            j=s.find('^');
            keep_i=i;
        }
        ++i;
    }
    i=keep_i;
    int cnt=0;
    char c;
    for (int ii=0; ii<v.size(); ++ii){
        for (int jj=0; jj<v[0].size(); ++jj){
            if (v[ii][jj]!='#'){
                c=v[ii][jj];
                v[ii][jj]='#';
                cnt+=stuck(i, j);
                //fout<<stuck(i, j)<<" "<<ii<<" - "<<jj<<endl;
                //system("PAUSE");
                v[ii][jj]=c;
            }
        }
    }
    fout<<cnt;
}
int main()
{
    //p1();
    p2();
}
