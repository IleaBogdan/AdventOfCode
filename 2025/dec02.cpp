#include"lib.h"

#define int size_t
bool valid1(size_t x){
    string s=to_string(x);
    if(s.size()%2)return true;
    string p1="",p2="";
    for(int i=0;i<s.size()/2;++i){
        p1.push_back(s[i]);
    }
    for(int i=s.size()/2;i<s.size();++i){
        p2.push_back(s[i]);
    }
    return p1!=p2;
}
void p1(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)if(s[i]==','||s[i]=='-')s[i]=' ';
    stringstream sin(s);
    size_t a,b;char c;
    size_t sum=0ull;
    while(sin>>a){
        sin>>b;
        for(auto i=a;i<=b;++i){
            if(!valid1(i)){
                sum+=i;
                cerr<<i<<" ";
            }
        }
        cerr<<endl;
    }
    cout<<sum; // sol: 9188031749
}
bool valid2(int x){
    string s=to_string(x);
    for(int i=1;i<s.size();){
        ++i;
        if(s.size()%i)continue;
        vector<string>p(i);
        for(int k=0;k<s.size()/i;++k){
            for(int j=0;j<i;++j){
                p[j].push_back(s[k+(s.size()/i)*j]);
            }
        }
        bool ok=true;
        for(int k=1;ok&&k<p.size();++k){
            ok=(p[0]==p[k]);
        }
        if(ok)return false;
    }
    return true;
}
void p2(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)if(s[i]==','||s[i]=='-')s[i]=' ';
    stringstream sin(s);
    size_t a,b;char c;
    size_t sum=0ull;
    while(sin>>a){
        sin>>b;
        for(auto i=a;i<=b;++i){
            if(!valid2(i)){
                sum+=i;
                //cerr<<i<<" ";
            }
        }
        //cerr<<endl;
    }
    cout<<sum; // sol: 11323661261
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    //p1();
    p2();
    return 0;
}