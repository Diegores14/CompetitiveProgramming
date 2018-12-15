#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("mixmilk.in","r",stdin);
	freopen("mixmilk.out","w",stdout);
    int c[3], m[3];
    for(int i=0; i<3; i++){
        cin >> c[i] >> m[i];
    }
    int k = 0;
    for(int i=0; i<100; i++, k++){
        if( k == 3){
            k = 0;
        }
        if(k == 2){
            int temp = (m[0]+m[2] > c[0])? (c[0]-m[0]) : m[2];
            m[0] += temp;
            m[2] -= temp;
        }else{
            int temp = (m[k+1]+m[k] > c[k+1])? (c[k+1]-m[k+1]) : m[k];
            m[k+1] += temp;
            m[k] -= temp;
        }
    }
    for(int i=0; i<3; i++){
        cout << m[i] << '\n';
    }
    return 0;
}