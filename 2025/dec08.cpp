#include"lib.h"

#define int size_t
struct coord{
    int x,y,z;
    friend istream&operator>>(istream&in,coord&co){
        char c;
        in>>co.x>>c>>co.y>>c>>co.z;
        return in;
    }
    friend ostream&operator<<(ostream&out,coord&co){
        out<<co.x<<","<<co.y<<","<<co.z;
        return out;
    }
};
vector<pair<int,int>>pq;
vector<coord>v;
vector<int>root,rang;
set<pair<int,int>>s;
int p2(int x){
    return x*x;
}
long double dist(int i,int j){
    return sqrt(p2(v[i].x-v[j].x)+p2(v[i].y-v[j].y)+p2(v[i].z-v[j].z));
}
int get_root(int x){
    if(x==root[x])return x;
    root[x]=get_root(root[x]);
    return root[x];
}
void join(int x,int y){
    x=get_root(x);
    y=get_root(y);
    if(x==y)return;
    if(rang[x]>rang[y]){
        root[y]=x;
    }else if(rang[x]!=rang[y]){
        root[x]=y;
    }else{
        root[y]=x;
        ++rang[x];
    }
}
bool joined(int x,int y){
    return get_root(x)==get_root(y);
}
void print_root(const vector<int>&r){
    for(auto it:r){
        cerr<<get_root(it)<<" ";
    }
    cerr<<endl;
}
void print(const vector<int>&r){
    for(auto it:r){
        cerr<<it<<" ";
    }
    cerr<<endl;
}
void p1(void){
    coord c;
    v.push_back({0,0,0});
    while(cin>>c){
        v.push_back(c);
    }
    int n=v.size()-1,fixed_size=1000;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(i==j)continue;
            pq.push_back({i,j});
        }
    }
    root.resize(n+1);
    rang.resize(n+1);
    for(int i=1;i<=n;++i){
        root[i]=i;
        rang[i]=0;
    }
    sort(pq.begin(),pq.end(),[](pair<int,int>p1,pair<int,int>p2){
        return dist(p1.first,p1.second)<dist(p2.first,p2.second);
    });
    for(int i=0;fixed_size;++i,--fixed_size){
        int x=pq[i].first,y=pq[i].second;
        join(x,y);
    }
    for(int i=1;i<=n;++i){
        int cnt=0,x=get_root(i);
        for(int j=1;j<=n;++j){
            if(x==get_root(j))++cnt;
        }
        s.insert({cnt,x});
    }
    int trei=3;
    size_t prod=1;
    for(auto it=s.rbegin();it!=s.rend();++it){
        if(!trei)break;
        prod*=it->first;
        --trei;
    }
    cout<<prod; // sol: 54600
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    p1();
    return 0;
}