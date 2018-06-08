#include <bits/stdc++.h>
using namespace std;

int main(){
 	int v[20];
	for (int i = 0; i < 20; i++)cin >> v[i];
	for (int i = 19; i >= 0; i--) cout << "N[" << 19-i << "] = " << v[i] << '\n';
	return 0;
}