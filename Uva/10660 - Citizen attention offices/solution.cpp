#include <bits/stdc++.h>
using namespace std;
struct node{
    int first, second, value;
    node(){}
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long mmin;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<node> v(n);
        for(node &i: v){
            cin >> i.first >> i.second >> i.value;
        }
        mmin = 1LL<<62;
        int ans[5], aux[5];
        for(int a=0; a<21; a++){
            aux[0] = a;
            for(int b=a+1; b<22; b++){
                aux[1] = b;
                for(int c=b+1; c<23; c++){
                    aux[2] = c;
                    for(int d=c+1; d<24; d++){
                        aux[3] = d;
                        for(int e=d+1; e<25; e++){
                            aux[4] = e;
                            long long temp = 0;                            
                            for(node i: v){
                                int temp1 = 1<<30;
                                for(int j=0; j<5; j++){
                                    int x = aux[j]%5, y = aux[j]/5;
                                    temp1 = min(temp1, i.value * ( abs(y - i.first) + abs(x - i.second)));
                                }
                                temp += temp1;
                            }
                            if(temp < mmin){
                                ans[0] = a;
                                ans[1] = b;
                                ans[2] = c;
                                ans[3] = d;
                                ans[4] = e;
                                mmin = temp;
                            }
                        }
                    }
                }
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << '\n';
    }
    return 0;
}