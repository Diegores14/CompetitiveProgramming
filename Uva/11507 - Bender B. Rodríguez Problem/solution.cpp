#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n, n){
		string ans = "+x";
		string bend;
	 	for(int i=1; i<n; i++){
	 		cin >> bend;
	 		if(bend == "No")
	 			continue;
	 		if(bend == "+y"){
	 		 	if(ans == "+x"){
	 		 		ans = "+y";
	 		 		continue;
				}
	 		 	if(ans == "-x"){
	 		 		ans = "-y";
	 		 		continue;
				}
	 		 	if(ans == "+y"){
	 		 		ans = "-x";
	 		 		continue;
				}
	 		 	if(ans == "-y"){
	 		 		ans = "+x";
	 		 		continue;
				}
	 		}
	 		if(bend == "-y"){
	 		 	if(ans == "+x"){
	 		 		ans = "-y";
	 		 		continue;
				}
	 		 	if(ans == "-x"){
	 		 		ans = "+y";
	 		 		continue;
				}
	 		 	if(ans == "+y"){
	 		 		ans = "+x";
	 		 		continue;
				}
	 		 	if(ans == "-y"){
	 		 		ans = "-x";
	 		 		continue;
				}
	 		}
	 		if(bend == "+z"){
	 		 	if(ans == "+x"){
	 		 		ans = "+z";
	 		 		continue;
				}
	 		 	if(ans == "-x"){
	 		 		ans = "-z";
	 		 		continue;
				}
	 		 	if(ans == "+z"){
	 		 		ans = "-x";
	 		 		continue;
				}
	 		 	if(ans == "-z"){
	 		 		ans = "+x";
	 		 		continue;
				}
	 		}
	 		if(bend == "-z"){
	 		 	if(ans == "+x"){
	 		 		ans = "-z";
	 		 		continue;
				}
	 		 	if(ans == "-x"){
	 		 		ans = "+z";
	 		 		continue;
				}
	 		 	if(ans == "+z"){
	 		 		ans = "+x";
	 		 		continue;
				}
	 		 	if(ans == "-z"){
	 		 		ans = "-x";
	 		 		continue;
				}
	 		}
	 	}
	 	cout << ans << '\n';
	}
	return 0;
}