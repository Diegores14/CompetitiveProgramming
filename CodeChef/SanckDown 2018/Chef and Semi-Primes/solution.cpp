#include <bits/stdc++.h>
using namespace std;

bool factorPrime(int n){
	set<int> s;
        while(n%2==0){
		if(s.count(2))return false;
		s.insert(2);
         	n/=2;
	}
	for(int i=3; i*i<=n; i+=2){
		while(n%i==0){
			if(s.count(i))return false;
			s.insert(i);
	         	n/=i;
		}
	}
	if(n>2)s.insert(n);
	return s.size()==2;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
		bool ans=false;
	 	cin >> n;
		for(int i=6; i<n; i++){
			if(factorPrime(i) && factorPrime(n-i)){
			 	ans=true;
				break;
			}
		}
		if(ans){
		 	cout << "YES\n";
		}else{
		 	cout << "NO\n";
		}
	}
	return 0;
}