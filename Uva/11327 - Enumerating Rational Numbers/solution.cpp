#include <bits/stdc++.h>
using namespace std;

vector<long long> v(200003);

int gcd(int a, int b){
 	return (b)? gcd(b, a%b) : a;
}



int totient(int n){
	int result=n;
	for(int i=2; i*i<=n; i++){
	       	if(n%i==0){ while(n%i==0) n/=i;
		result-=result/i;
		}
	}
 	if(n>1) result-=result/n;
	return result;
}




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	v[0]=0;v[1]=1;v[2]=2;
	for(int i=2; i<200002; i++){v[i+1]=v[i]+totient(i);}
	long long n;
	while(cin >> n, n){
		if(n==1)cout << "0/1\n";
		else if(n==1)cout << "1/1\n";
		else{                    
			int denominator = lower_bound(v.begin(), v.end(), n)-v.begin()-1;
			n -= v[denominator];
			int i;
			for(i=1; n; i++){                                
			 	if(gcd(denominator, i)==1)n--;
			}
			cout << i-1 << '/' << denominator << '\n';
		}
	}
 	return 0;
}