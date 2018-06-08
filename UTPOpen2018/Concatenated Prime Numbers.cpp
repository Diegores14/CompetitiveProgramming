#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> criba(10000001,1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    criba[0]=0;criba[1]=0;
    for(int i = 2; i<=10000; i++){
        if(criba[i]==1){
            for(int j=i+i; j<=10000000; j+=i){
                criba[j]=0;
            }
        }
    }
    int k;
    string s;
    while(cin>>k>>s){
        bool respuesta=true;
        int aux;
        for(int i = 0; i<s.size(); i+=k){
            aux = atoi(s.substr(i,k).c_str());
            if(criba[aux]!=1){respuesta=false;break;}
        }
        cout<<((respuesta) ? ":)\n" : ":(\n");
    }
    return 0;
}
