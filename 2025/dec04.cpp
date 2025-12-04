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
    cout<<cnt; // sol 1409
}
ofstream fout("date1.out");
void print(const vector<string>&s){
    for(const string&it:s){
        fout<<it<<endl;
    }
    fout<<endl<<endl;
}
void p2(void){
    vector<string>matrix,nmat;
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
            nmat.push_back(dot);
        }
        s="."+s+".";
        matrix.push_back(s);
        nmat.push_back(s);
    }
    for(int i=0;i<s.size();++i){
        s[i]='.';
    }
    matrix.push_back(s);
    nmat.push_back(s);
    bool chg=true;
    int cnt=0;
    while(chg){
        chg=false;
        print(matrix);
        for(int i=1;i<matrix.size()-1;++i){
            for(int j=1;j<matrix[i].size()-1;++j){
                if(check(i,j,matrix)){
                    nmat[i][j]='.';
                    chg=true;
                    ++cnt;
                }else{
                    nmat[i][j]=matrix[i][j];
                }
            }
        }
        matrix=nmat;
    }
    cout<<cnt; // sol: 8366
}
int main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    //p1();
    p2();
    return 0;
}