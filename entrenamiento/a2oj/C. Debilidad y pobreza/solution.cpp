#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	long long sum=0;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++){cin >> v[i];sum+=v[i];}
	double x = (double)sum/n;
	sort(v.begin(), v.end());
	
	return 0;
}