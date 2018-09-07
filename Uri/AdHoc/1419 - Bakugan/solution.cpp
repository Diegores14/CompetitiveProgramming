#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n, n){
	 	vector<int> v1(n+3, -1), v2(n+3, -1);
	 	int ans1=0, ans2=0;
	 	bool r=true;
	 	for(int i=0; i<n; i++) cin >> v1[i];
	 	for(int i=0; i<n; i++) cin >> v2[i];
	 	for(int i=0; i<n; i++){
	 	 	ans1+=v1[i];
	 	 	ans2+=v2[i];
	 	 	if(r && ((v1[i]==v1[i+1] && v1[i+2]==v1[i]) || (v2[i]==v2[i+1] && v2[i+2]==v2[i]))){
	 	 	 	r=false;
	 	 	 	if((v1[i]==v1[i+1] && v1[i+2]==v1[i]) && (v2[i]==v2[i+1] && v2[i+2]==v2[i]))continue;
				if(v1[i]==v1[i+1] && v1[i+2]==v1[i]) ans1+=30;
				else ans2+=30;
	 	 	}
	 	}
	 	if(ans1==ans2){cout << "T\n"; continue;}
	 	if(ans1>ans2) cout << "M\n";
	 	else cout << "L\n";
	}
	return 0;
}