#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void p1()
{
    string s;
    int tot=0;
    while (fin>>s){
        int i1=0, i2=s.size()-1;
        while (!isdigit(s[i1]))++i1;
        while (!isdigit(s[i2]))--i2;
        tot+=10*(s[i1]-'0')+s[i2]-'0';
    }
    fout<<tot;
}
void p2()
{
    string s;
    int tot=0;
    map<int, string>num;
    num[1]="one";
    num[2]="two";
    num[3]="three";
    num[4]="four";
    num[5]="five";
    num[6]="six";
    num[7]="seven";
    num[8]="eight";
    num[9]="nine";
    s+="[[[[[]]]]]";
    while (fin>>s){
        for (int i=0; i<s.size(); ++i){
            if (isdigit(s[i])){
                tot+=10*(s[i]-'0');
                cout<<s[i];
                break;
            } else {
                for (int n=1; n<10; ++n){
                    if (s.substr(i, num[n].size())==num[n]){
                        tot+=10*n;
                        cout<<n;
                        i=s.size();
                        break;
                    }
                }
            }
        }
        for (int i=s.size()-1; i>=0; --i){
            if (isdigit(s[i])){
                tot+=(s[i]-'0');
                cout<<s[i];
                break;
            } else {
                for (int n=1; n<10; ++n){
                    if (s.substr(i, num[n].size())==num[n]){
                        tot+=n;
                        cout<<n;
                        i=-1;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    fout<<tot;
}
int main()
{
    //p1();
    p2();
}