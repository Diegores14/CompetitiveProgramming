#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long n, w, aux;
	long long sum=0, mx=0, mx1=0;
	cin >> n >> w;
	for(int i=0; i<n; i++){cin >> aux; sum+=aux; mx1=max(abs(sum),mx1); mx=max(mx,abs(aux));}
	if(mx>w || sum >w || mx1>w){cout << "0\n"; return 0;}
	cout << min(w-mx,w-mx1)+1 << '\n';	
        return 0;
}	