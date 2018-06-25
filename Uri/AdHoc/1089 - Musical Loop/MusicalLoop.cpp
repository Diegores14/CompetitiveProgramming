#include <bits/stdc++.h>
using namespace std;

int main(){
 	int n;
	while(cin >> n, n){
	 	vector<int> v(n);
		int cont = 0;
		for(int i=0; i < n; i++)cin >> v[i];
		int pendiente=0;
		for(int i=0; i < n-1; i++){
		 	if(pendiente == 0 && (v[i+1]-v[i])!=0){pendiente=(v[i+1]-v[i]);continue;}
			if(pendiente < 0 && (v[i+1]-v[i])>0){pendiente=1;cont++;continue;}
			if(pendiente > 0 && (v[i+1]-v[i])<0){pendiente=-1;cont++;}
		}
		if(pendiente < 0 && (v[0]-v[v.size()-1])>0)cont++;
		if(pendiente > 0 && (v[0]-v[v.size()-1])<0)cont++;
		if((v[0]-v[v.size()-1])>0 && (v[1]-v[0])<0)cont++;
		if((v[0]-v[v.size()-1])<0 && (v[1]-v[0])>0)cont++;
		cout << cont << '\n';
		
	}
	return 0;
}