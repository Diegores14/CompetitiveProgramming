#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long n, answer=0, sum1=0,sum2=0;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)cin >> v[i];
	int i=-1, j=n;
	while(j-i!=1){
	 	if(sum1>sum2)sum2+=v[--j];
	 	else sum1+=v[++i];
	 	if(sum1==sum2) answer=sum1;
	}
	cout << answer << '\n';
	
	return 0;
}