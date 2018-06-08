#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N){
        cout<<'1';
        for(int i=2; i<=N; i++)
            cout<<' '<<i;
        cout<<'\n';
        cin>>N;
    }
}
