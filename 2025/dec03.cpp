#include"lib.h"

void p1(void){
    string s;
    long long sun=0;
    while(cin>>s){
        int mnum=0;
        for(int i=0;i<s.size();++i){
            for(int j=i+1;j<s.size();++j){
                int num=10*(s[i]-'0')+(s[j]-'0');
                mnum=max(mnum,num);
            }
        }
        sun+=mnum;
    }
    cout<<sun; // sol: 17074
}
void p2__backtrack(void){
    string s;
    unsigned long long sun=0;
    while(cin>>s){
        long long mnum=0;
        for(long long i=0;i<(1<<s.size());++i){
            if(__builtin_popcountll(i)!=12)continue;
            long long p10=100000000000ll,num=0;
            for(int bit=0;bit<s.size();++bit){
                if((1<<bit)&i){
                    num+=p10*(s[bit]-'0');
                    p10/=10;
                }
            }
            mnum=max(mnum,num);
        }
        //cout<<mnum<<endl;
        sun+=mnum;
    }
    cout<<sun;
}
vector<int>v;
int search_max(int start,int stop){
    int ret=start;
    for(int i=start+1;i<stop;++i){
        if(v[ret]<v[i]){
            ret=i;
        }
    }
    return ret;
}
void p2(void){
    // pe scurt: sunt idiot ca nu m-am gandit la asta pana acum
    // pe lung: cautam cea mai mare cifra din s intre 0 si s.size()-12
    //          dupa continuam sa repetam de la index+1 s.size()-11
    //          si tot asa de 12 ori pana avem tot numarul 
    string s;
    size_t sun=0ull;
    while(cin>>s){
        v.clear();
        for(auto it:s){
            v.push_back(it-'0');
        }
        int times=12,index=-1;
        size_t num=0;
        for(;times;--times){
            int min_index=search_max(index+1,v.size()-times+1);
            index=min_index;
            num*=10;
            num+=v[index];
        }
        // cerr<<num<<endl;
        sun+=num;
    }
    cout<<sun; // sol: 169512729575727
}
signed main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    //p1();
    p2();
    return 0;
}