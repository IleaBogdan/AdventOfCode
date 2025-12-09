#include"lib.h"

vector<pair<int,int>>plist;
size_t calc_area(pair<int,int>p1,pair<int,int>p2){
    size_t l=abs(p2.first-p1.first)+1,L=abs(p2.second-p1.second)+1;
    return l*L;
}
void part1(void){
    int x,y;
    char c;
    while(cin>>x>>c>>y){
        // cerr<<x<<" "<<y<<endl;
        plist.push_back({x,y});
    }
    size_t max_area=0;
    for(int i=0;i<plist.size();++i){
        for(int j=i+1;j<plist.size();++j){
            auto narea=calc_area(plist[i],plist[j]);
            if(narea>max_area){
                //cerr<<plist[i].first<<" "<<plist[i].second<<" -- "<<plist[j].first<<" "<<plist[j].second<<" --- "<<narea<<endl;
                max_area=narea;
            }
        }
    }
    cout<<max_area; // sol: 4761736832
}
int main(...){
    open_file();
    part1();
    return 0;
}