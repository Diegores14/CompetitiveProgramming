#include <bits/stdd++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    long long n, m, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> t;
    while(t--){
        long long aux = 0;
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        if(x1 <= x4){
            if(y1 <= y4)
                aux = (x4 - x1 + 1) * (y4 - y1 +1);
            if(y3 <= y2)
                aux = (x4 - x1 + 1) * (y3 - y2 +1);
        }
        if(x3 <= x2){
            if(y3 <= y2)
                aux = (x2 - x3 + 1) * (y2 - y3 +1);
            if(y1 <= y4)
                aux = (x2 - x3 + 1) * (y1 - y4 +1);
        }
        long cant = n * m;
        long long blancos = (cant>>1) + (cant&1);
        long long negros = (cant>>1);
        
    }
    return 0;
}