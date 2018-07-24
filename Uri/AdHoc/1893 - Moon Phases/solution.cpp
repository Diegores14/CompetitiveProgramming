#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	if(0<=b && b <=2) cout << "nova\n";
	if(3<=b && b <=96)cout << ((a<b)? "crescente\n" : "minguante\n");
	if(97<=b && b <=100) cout << "cheia\n";
 	return 0;
}