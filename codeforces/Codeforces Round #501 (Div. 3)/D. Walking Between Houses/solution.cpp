#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, s;
	cin >> n >> k >> s;
	if((n-1)*k >= s){
		cout << "YES\n";
		int i=1;
		while(s){
		 	if(s>n-1 && i==1){ i=n; cout << i << ' '; s-=(n-1);}
		 	if(s>n-1 && i==n){ i=1; cout << i << ' '; s-=(n-1);}
		 	if(s<=n-1 && i==1){ i+=s; cout << i << '\n'; break;}
			if(s<=n-1 && i==n){ i-=s; cout << i << '\n'; break;}
		}
	}else cout << "NO\n";
 	return 0;
}