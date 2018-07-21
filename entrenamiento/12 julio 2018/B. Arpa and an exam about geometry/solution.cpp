#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >>  by >> cx >> cy;
	unsigned long long a = sqrt((using long long)(ax-bx)*(ax-bx)+(using long long)(ay-by)*(ay-by)),
				 b = sqrt((using long long)(bx-cx)*(bx-cx)+(using long long)(by-cy)*(by-cy)),
				 c = sqrt((using long long)(ax-cx)*(ax-cx)+(using long long)(ay-cy)*(ay-cy));
	cout << ((a==b && c < a + b)? "Yes\n" : "No\n");
	//cout << a << b << c;
 	return 0;
}