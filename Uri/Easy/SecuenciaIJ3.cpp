#include <bits/stdc++.h>
using namespace std;

int main(){
	int i=1, j=7, aux = 1;
	while(i<10){                
		cout << "I=" << i << " J=" << j << '\n';
		j--;
		if(aux%3==0)aux=0;
		if(aux==0){ i+=2; j+=5;}
		aux++;
	}
	return 0;
}	