#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,j, answer=0;
	cin >> n;
	j=n-1;
	vector<int> v1(n), v2(n);
	for(int i=0; i<n; i++) cin >> v1[i];
	for(int i=0; i<n; i++) cin >> v2[i];
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=n-1; i>=0 && j>=0; i--)
		for(; j>=0; j--)if(v1[j]<v2[i]){answer++; j--; break;}
	cout << answer << '\n';
	return 0;
}