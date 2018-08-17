#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	if(n==0) cout << "E\n";
	if(1<= n && n <=35) cout << "D\n";
	if(36<= n && n <=60) cout << "C\n";
	if(61<= n && n <=85) cout << "B\n";
	if(86<= n && n <=100) cout << "A\n";
 	return 0;
}