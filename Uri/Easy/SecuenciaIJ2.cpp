#include <bits/stdc++.h>
using namespace std;

int main(){
 	int i=1,j=7;
	while(i<10){
	 	cout << "I=" << i << " J=" << j << '\n';
		if(j==5){i+=2;j=8;}
		j--; 
	}
	return 0;
}