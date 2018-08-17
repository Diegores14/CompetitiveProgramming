#include <bits/stdc++.h>
using namespace std;

struct node{
  	int a, b, c, i;
  	node(){a=0; b=0; c=0; i=0;}  	
};

bool operator <(node x, node y){
	if(x.a<y.a) return true;
	else{
	 	if(x.a==y.a){
			if(x.b<y.b) return true;
			else{
				if(x.b==y.b) return x.c < y.c;
				else return false;
			}
	 	}else return false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m,aux;
	cin >> n >> m;
	vector<node> v(n);
	for(int i=0; i<m; i++){
	 	for(int j=0; j<n; j++){
	 		v[j].i=j+1;
	 	  	cin >> aux;
	 	  	v[j].a+=aux;
	 	  	if(v[j].b<=aux){v[j].b=aux;v[j].c=i*n+j;}	 	  	
	 	}	 		
	}
	sort(v.begin(), v.end());
	cout << v[v.size()-1].i << '\n';
	return 0;
}