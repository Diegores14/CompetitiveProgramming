#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    int temp = 0;
    while(cin >> k, k){
        if(temp)
            cout << '\n';
        temp++;
        vector<int> v(k);
        for(int &i : v){
            cin >> i;
        }
        for(int a=0; a<k-5; a++){
            for(int b=a+1; b<k-4; b++){
                for(int c=b+1; c<k-3; c++){
                    for(int d=c+1; d<k-2; d++){
                        for(int e=d+1; e<k-1; e++){
                            for(int f=e+1; f<k; f++){
                                cout << v[a] << ' ' << v[b] << ' ' << v[c] << ' ' << v[d] << ' ' << v[e] << ' ' << v[f] << '\n';
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}