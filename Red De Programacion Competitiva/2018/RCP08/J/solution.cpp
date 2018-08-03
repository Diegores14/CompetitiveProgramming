#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a;
	cin >> n;
	vector<long long> v1(n), v2(3,0);
	vector<long long> answer(3,0);
	for(int i=0; i<n; i++) cin >> v1[i];
	for(int i=0; i<n; i++){ cin >> a; v2[i%3]+=a;}
	for(int i=0; i<n; i++){
	 	for(int j=0; j<3; j++)answer[(j+i)%3] += v1[i]*v2[j];
	}
	cout << answer[1] << ' ' << answer[2] << ' ' << answer[0] << '\n';
	return 0;
}