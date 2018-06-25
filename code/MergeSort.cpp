#include <bits/stdc++.h>
using namespace std;

struct mergeSort{
	vector<int> g;
	mergeSort(vector<int> &v){
	 	g = v;
		merge(0,(int)g.size()/2,(int)g.size()-1);
		for(int to : g)cout << to << ' ';
	}
	void merge(int p,int q,int r){
	 	int a=p,b=q+1;
		if(p==r)return;
		merge(p,(p+q)/2,q);
		merge(q+1,(q+1+r)/2,r);
		int i=0, n = r-p+1;
		vector<int> aux(n);
		while(i<n){
		 	if(a>q){aux[i]=g[b++];i++;continue;}
			if(b>r){aux[i]=g[a++];i++;continue;}
			if(g[a]<g[b])aux[i]=g[a++];
			else aux[i]=g[b++];
			i++;
		}
		for(int i=0;i<n;i++)g[i+p]=aux[i];
	}
};

int main(){
	vector<int> v;
	for(int i=100; i>=0;i--)v.push_back(i);
	mergeSort a(v);                   
 	return 0;
}