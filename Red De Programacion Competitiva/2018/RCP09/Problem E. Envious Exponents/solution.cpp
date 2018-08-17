#include <bits/stdc++.h>
using namespace std;

unsigned int howManyBits(unsigned long long n){
	int cont=0;
	while(n){if(n&1)cont++; n>>=1;}
	return cont;
}

unsigned long long change(unsigned long long n){
 	int cont=0;
 	for(int i=0; i<63; i++){
 	 	if((n>>i)&1 && ((n>>(i+1))&1)==0){
 	 		n^=(3ULL<<i);
 	 		unsigned long long mask = (1ULL<<i)-1;
 	 		n&=(~mask);
 	 		n|=(1ULL<<cont)-1;
 	 		break;
		}
 	 	if((n>>i)&1) cont++;
 	}
 	return n;
}

unsigned long long answer(unsigned long long n, int k){
	unsigned long long ans=0;
 	for(int i=63; i>=0 && k; i--){
 		if(n&(1ULL<<i))k--;
 		ans|=(n&(1ULL<<i));
	}
//	cout << ans <<'\n';
	return change(ans);
}

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	unsigned int bits;
 	unsigned long long n, k; 
 	cin >> n >> k;
	bits=howManyBits(n);
	if(k>bits){
		k-=bits;
	  	for(int i=0; k; i++)if(!(n&(1ULL<<i))){n|=(1ULL<<i);k--;}
	}else{
		n = answer(n, k);
	}
 	cout << n <<'\n';
 	return 0;
}