#include"lib.h"

void p1(void){
    char d;
    int num,start=50,cnt0=0;
    while(cin>>d){
        cin>>num;
        // cout<<d<<" "<<num<<endl;
        if(d=='L')num=-num;
        start=(100+start-num)%100;
        cnt0+=(!start);
    }
    cout<<cnt0;
}
int main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    p1();
    return 0;
}