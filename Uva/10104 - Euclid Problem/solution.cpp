#include <bits/stdc++.h>
using namespace std;

long long int x, y, d;
void extendedEuclid(long long int a, long long int b){
    if(b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    long long int x1, y1;
    x1 = y;
    y1 = x - a/b*y;
    x = x1;
    y = y1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long a,b;
	while(cin >> a >> b){
	 	extendedEuclid(a,b);
		cout << x << ' ' << y << ' ' << d << '\n';
	}
        return 0;
}	