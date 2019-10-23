#include <bits/stdc++.h>
using namespace std;
int h[3000001];

int main(){
	int n, p, temp;
	int v[211];
	scanf("%d", &n);
	while(n--){
	 	scanf("%d", &p);
		memset( v, 0, sizeof v );
		for(int i=0; i<p; i++) {
		 	scanf("%d", &temp);
			v[temp-20]++;
		}		 
		for( int i = 0, j = 0; i <= 210 && j < p; i++) {
			while( v[i]-- ) {
				h[j++] = i+20;
			}
		}
		for(int i=0; i<p-1; i++)printf("%d ", h[i]);
		printf("%d\n", h[p-1]);
	}
	return 0;
}	