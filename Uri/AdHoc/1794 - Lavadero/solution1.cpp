#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	if(n < a || n > b || n < c || n > d)
	        printf("impossivel\n");
	else
        	printf("possivel\n");
	return 0;
}