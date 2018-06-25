#include <bits/stdc++.h>
using namespace std;

struct mergeSort{
	int cont=0;
	mergeSort(vector<int> &v){
		merge(v, 0,(int)v.size()/2,(int)v.size()-1);
	}
	
	void merge(vector<int> &v, int p,int q,int r){
	 	int a=p,b=q+1;
		if(p==r)return;
		merge(v, p,(p+q)/2,q);
		merge(v, q+1,(q+1+r)/2,r);
		int i=0, n = r-p+1;
		vector<int> aux(n);
		while(i<n){
		 	if(a>q){aux[i]=v[b++];i++;continue;}
			if(b>r){aux[i]=v[a++];i++;continue;}
			if(v[a]<v[b])aux[i]=v[a++];
			else {aux[i]=v[b++];cont+=q-a+1;}
			i++;
		}
		for(int i=0;i<n;i++)v[i+p]=aux[i];
	}
};


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n, n){
		vector<int> v(n);
		for(int i=0; i<n;i++)cin >> v[i];
		mergeSort a(v);
		cout << ((a.cont%2)? "Marcelo" : "Carlos") << '\n';
	}
 	return 0;
}