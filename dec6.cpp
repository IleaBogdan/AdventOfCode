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
int main()
{
    p1();
}
