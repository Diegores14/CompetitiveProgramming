#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
 	int n;
	map<int, string> m;
	m[1]="January\n";
	m[2]="February\n";
	m[3]="March\n";
	m[4]="April\n";
	m[5]="May\n";
	m[6]="June\n";
	m[7]="July\n";
	m[8]="August\n";
	m[9]="September\n";
	m[10]="October\n";
	m[11]="November\n";
	m[12]="December\n";
	cin >> n;
	cout << m[n];
	return 0;
}