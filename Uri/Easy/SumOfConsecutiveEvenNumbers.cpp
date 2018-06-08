#include <bits/stdc++.h>
using namespace std;


int main(){
        int x, cont, sum=0;
	cin >> x;
	while(x){
		cont = 0; sum=0;
	 	while(cont != 5){
	         	if(x%2==0){sum+=x; cont++;}
			x++;
		}
		cout << sum << '\n';
		cin >> x;
	}
 	return 0;
}