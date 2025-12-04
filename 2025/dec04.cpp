#include"lib.h"

int di[]={-1,-1,-1,0,1,1,1,0},dj[]={-1,0,1,1,1,0,-1,-1};
bool check(const int&i, const int&j,const vector<string>&mat){
    if(mat[i][j]=='.')return false;
    int cnt=0;
    for(int k=0;k<8;++k){
        int ni=i+di[k],nj=j+dj[k];
        cnt+=bool(mat[ni][nj]=='@');
    }
    return cnt<4;
}
void p1(void){
    vector<string>matrix;
    string s;
    bool f=true;
    while(cin>>s){
        if(f){
            f=false;
            string dot="..";
            for(int i=0;i<s.size();++i){
                dot+=".";
            }
            matrix.push_back(dot);
        }
        s="."+s+".";
        matrix.push_back(s);
    }
    for(int i=0;i<s.size();++i){
        s[i]='.';
    }
    matrix.push_back(s);
    int cnt=0;
    for(int i=1;i<matrix.size()-1;++i){
        for(int j=1;j<matrix[i].size()-1;++j){
            cnt+=check(i,j,matrix);
        }
    }
    cout<<cnt;
}
int main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    p1();
    return 0;
}