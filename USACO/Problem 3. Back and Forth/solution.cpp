#include<bits/stdc++.h>
using namespace std;
set<int> s;

void solution(int g1, int g2, vector<int> bucket1, vector<int> bucket2, int idx){
    if(idx == 5){
        //cout << "debug " << g1 << '\n';
        s.insert(g1);
        return;
    }
    vector<int> aux1 = bucket1, aux2 = bucket2;
    if(idx%2){
        for(int i = 0; i<20; i++){
            if(bucket1[i] != -1){
                aux1[i] = -1;
                aux2[10 + idx] = bucket1[i]; 
                solution(g1 - bucket1[i], g2 + bucket1[i], aux1, aux2, idx+1);
                aux1[i] = bucket1[i];
                aux2[10 + idx] = -1; 
            }
        }
    }else{
        for(int i = 0; i<20; i++){
            if(bucket2[i] != -1){
                aux2[i] = -1;
                aux1[10 + idx] = bucket2[i]; 
                solution(g1 + bucket2[i], g2 - bucket2[i], aux1, aux2, idx+1);
                aux2[i] = bucket2[i];
                aux1[10 + idx] = -1; 
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("backforth.in","r",stdin);
	freopen("backforth.out","w",stdout);
    int temp;
    vector<int> v1(20, -1), v2(20, -1);
    for(int i=0; i<10; i++){
        cin >> v1[i];
    }
    for(int i=0; i<10; i++){
        cin >> v2[i];
    }
    solution(1000, 1000, v1, v2, 1);
    cout << s.size() << '\n';
    return 0;
}