#include <bits/stdc++.h>
using namespace std;

int main(){
	int id, h;
	float sal;
	cin >> id >> h >> sal;                               
	float aux = h*sal;
	printf("NUMBER = %d\n", id);
	printf("SALARY = U$ %.2f\n", aux);
return 0;
}