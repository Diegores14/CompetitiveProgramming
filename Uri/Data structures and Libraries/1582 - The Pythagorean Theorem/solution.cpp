#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
        if(b==0) return a;
	return gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int v[3];
	while(cin >> v[0] >> v[1] >> v[2]){
	 	sort(v,v+3);
		if((v[0]*v[0]+v[1]*v[1])==v[2]*v[2]){
			v[1]=gcd(v[2],v[1]);
			if(v[0]>v[1])swap(v[0],v[1]);
			if(gcd(v[1],v[0])==1)cout << "tripla pitagorica primitiva\n";
			else cout << "tripla pitagorica\n";
		}else cout << "tripla\n";
	}
 	return 0;
}