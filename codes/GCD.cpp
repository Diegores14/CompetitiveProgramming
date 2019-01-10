#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	return b? GCD(b, a%b) : a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << GCD(a,b);
        return 0;
}	