#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, m, a, b, sum1=0, sum2=0; 
	cin >> n >> m;
	vector<int> v(n); 
	for(int i=0; i<n; i++){cin >> a >> b; sum1+=a; sum2+=b; v[i]=a-b;}
	if(sum2<=m){
		sort(v.begin(), v.end(), greater<int>());
		int answer=0;
		for(int i=0; i<n && sum1>m; i++, answer++)sum1-=v[i];
		cout << answer << '\n';
	}else cout << "-1\n";
 	return 0;
}