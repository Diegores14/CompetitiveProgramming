#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, answer=1, aux;
	cin >> n;
	vector<int> high(n,1);
	vector<int> v(n);
	for(int i=0; i<n; i++)cin >> v[i];
	for(int i=1; i<n-1 && answer<n-i; i++){
		aux=high[i-1]+1;
		int j;
	        for(j=i; aux>0 && j<n; j++, aux--){
	         	if(aux>v[j])break;
	        }         	
	        if(j==n)j--;
	        high[i]=(aux)? v[j]+j-i : high[i-1]+1;
	        answer = max(answer, high[i]);
        }
        cout << answer << '\n';
 	return 0;
}