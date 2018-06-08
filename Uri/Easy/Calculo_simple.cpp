#include <bits/stdc++.h>
using namespace std;

int main(){
 	int a1, b1, a2, b2;
	float c1, c2;
	scanf("%d %d %f\n%d %d %f", &a1, &b1, &c1, &a2, &b2, &c2);
	printf("VALOR A PAGAR: R$ %.2f\n", b1*c1 + b2*c2); 
	return 0;
}