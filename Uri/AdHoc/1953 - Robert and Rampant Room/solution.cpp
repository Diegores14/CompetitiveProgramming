#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s1, s2;
	while(cin >> n){
		int ans1=0, ans2=0, ans3=0;
	 	while(n--){
	 		cin >> s1 >> s2;
		 	if(s2=="EPR")ans1++;
		 	else{
		 		if(s2=="EHD")ans2++;
		 		else ans3++;
			}
		}
		cout << "EPR: " << ans1 << "\nEHD: " << ans2 << "\nINTRUSOS: " << ans3 << '\n';
	}
	return 0;
}