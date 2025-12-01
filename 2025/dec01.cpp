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
    cout<<cnt0; // output: 1141
}
void p2(void){
    char d;
    int num,start=50,cnt0=0;
    while(cin>>d){
        cin>>num;
        if(num>99){ // the case when num is friking 942
            cnt0+=num/100;
            num%=100;
        }
        // cout<<d<<" "<<num<<endl;
        if(d=='L')num=-num;
        auto old_start=start;
        start=(100+start-num)%100;
        if(old_start>start&&d=='L'&&old_start){
            ++cnt0;
            //cout<<-num<<endl;
        }else if(old_start<start&&d=='R'&&old_start){
            ++cnt0;
            //cout<<num<<endl;
        }else cnt0+=(!start);
    }
    cout<<cnt0; // 6634
}
int main(...){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    // p1();
    p2();
    return 0;
}