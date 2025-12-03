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
int main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    p1();
    return 0;
}