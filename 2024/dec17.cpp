#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("date.out");
#define fin cin


int A, B, C, i;
int dv(int val, int p2)
{
    return val/(1<<p2);
}
vector<int> v;
void registerOperation(int opr, int ope)
{
    switch (opr){
    case 0:
        if (ope<=3){
            //cout<<"here\n";
            A=dv(A, ope);
            //cout<<"done\n";
        } else {
            if (ope==4){
                A=dv(A, A);
            } else if (ope==5){
                A=dv(A, B);
            } else if (ope==6){
                A=dv(A, C);
            }
        }
        break;
    case 1:
        B=(B^ope);
        break;
    case 2:
        if (ope<=3){
            B=ope%8;
        } else {
            if (ope==4){
                B=A%8;
            } else if (ope==5){
                B=B%8;
            } else if (ope==6){
                B=C%8;
            }
        }
        break;
    case 3:
        if (A!=0){
            i=ope-1;
        }
        break;
    case 4:
        B=(B^C);
        break;
    case 5:
        if (ope<=3){
            fout<<ope%8<<",";
        } else {
            if (ope==4){
                fout<<A%8<<",";
            } else if (ope==5){
                fout<<B%8<<",";
            } else if (ope==6){
                fout<<C%8<<",";
            }
        }
        break;
    case 6:
        if (ope<=3){
            B=dv(A, ope);
        } else {
            if (ope==4){
                B=dv(A, A);
            } else if (ope==5){
                B=dv(A, B);
            } else if (ope==6){
                B=dv(A, C);
            }
        }
        break;
    case 7:
        if (ope<=3){
            C=dv(A, ope);
        } else {
            if (ope==4){
                C=dv(A, A);
            } else if (ope==5){
                C=dv(A, B);
            } else if (ope==6){
                C=dv(A, C);
            }
        }
        break;
    }
}
void p1()
{
    int opr, ope;
    scanf("Register A: %d\n", &A);
    scanf("Register B: %d\n", &B);
    scanf("Register C: %d\n", &C);
    cin.get();
    scanf("Program: ");
    string str;
    getline(cin, str);
    //cout<<str<<endl;
    char c;
    reverse(str.begin(), str.end());
    while (str.back()!=' ')str.pop_back();
    str.pop_back();
    reverse(str.begin(), str.end());
    stringstream sin(str);
    while (sin>>c){
        if (c==',')continue;
        v.push_back(c-'0');
    }
    for (i=0; i<v.size(); ++i){
        //cout<<i<<endl;
        opr=v[i++];
        ope=v[i];
        registerOperation(opr, ope);
    }
}
int main()
{
    freopen("date.in", "r", stdin);
    p1();
    return 0;
}