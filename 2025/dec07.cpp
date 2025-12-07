#include"lib.h"

#define NMAX 150

vector<string>mat;
vector<bitset<150>>b;
size_t dp[NMAX][NMAX];
queue<pair<int,int>>q;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void p1(void){
    string s;
    while(cin>>s){
        mat.push_back(s);
        b.push_back(0);
    }
    int si=-1,sj=-1;
    for(int i=0;i<mat.size()&&si==-1;++i){
        for(int j=0;j<mat[i].size();++j){
            if(mat[i][j]=='S'){
                si=i;
                sj=j;
                break;
            }
        }
    }
    int n=mat.size(),m=mat[0].size(),cnt=0;
    q.push({si,sj});
    b[si][sj]=true;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i+1>=n)continue;
        if(mat[i+1][j]=='^'){
            ++cnt;
            if(j+1<m&&!b[i+1][j+1]){
                q.push({i+1,j+1});
                b[i+1][j+1]=true;
            }
            if(j-1<m&&!b[i+1][j-1]){
                q.push({i+1,j-1});
                b[i+1][j-1]=true;
            }
        }else{
            if(!b[i+1][j]){
                q.push({i+1,j});
                b[i+1][j]=true;
            }
        }
    }
    cout<<cnt; // sol: 1590
}
void p2(void){
    string s;
    while(cin>>s){
        mat.push_back(s);
        b.push_back(0);
    }
    int si=-1,sj=-1;
    for(int i=0;i<mat.size()&&si==-1;++i){
        for(int j=0;j<mat[i].size();++j){
            if(mat[i][j]=='S'){
                si=i;
                sj=j;
                break;
            }
        }
    }
    int n=mat.size(),m=mat[0].size(),cnt=0;
    q.push({si,sj});
    dp[si][sj]=1;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i+1>=n){
            size_t sum=1;
            while(!q.empty()){
                int ni=q.front().first,nj=q.front().second;
                //cout<<ni<<" "<<nj<<" "<<dp[ni][nj]<<endl;
                sum+=dp[ni][nj];
                q.pop();
            }
            cout<<sum;
            break;
        }
        if(mat[i+1][j]=='^'){
            ++cnt;
            if(j+1<m){
                dp[i+1][j+1]+=dp[i][j];
                if(!b[i+1][j+1]){
                    b[i+1][j+1]=true;
                    q.push({i+1,j+1});
                }
            }
            if(j-1>=0){
                dp[i+1][j-1]+=dp[i][j];
                if(!b[i+1][j-1]){
                    b[i+1][j-1]=true;
                    q.push({i+1,j-1});
                }
            }
        }else{
            dp[i+1][j]+=dp[i][j];
            if(!b[i+1][j]){
                b[i+1][j]=true;
                q.push({i+1,j});
            }
        }
    }
    // sol: 20571740188555
}
int main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    //p1();
    p2();
    return 0;
}