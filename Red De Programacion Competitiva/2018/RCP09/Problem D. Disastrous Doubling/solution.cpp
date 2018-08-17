#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	long long r=1, aux;
	bool sol=false;
	cin >> n;
	while(n-- && r>=0){
		r<<=1;
		cin >> aux;
		if(sol || r >= (1LL<<62)){
			sol=true;
		        r=(r-aux)%1000000007;
		        while(r<0)r=(r+1000000007)%1000000007;
		}else{     
			r-=aux;       
		} 
	}
	if(r<0)cout << "error\n";
	else cout << r%1000000007 << '\n';
	return 0;
}