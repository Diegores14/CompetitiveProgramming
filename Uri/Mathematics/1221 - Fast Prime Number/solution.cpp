#include <bits/stdc++.h>
using namespace std;
                                 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	unsigned x;
	int n;
	cin >> n;
	while(n--){
	 	cin >> x;
		int a = sqrt(x);
		bool res=true;
		for(int i=2; i<=a; i++)if(x%i==0){res=false;break;} 
		cout << ((res)? "Prime\n" : "Not Prime\n");
	}
 	return 0;
}