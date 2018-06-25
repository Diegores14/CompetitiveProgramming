#include <bits/stdc++.h>
using namespace std;

struct node{
  	int x;
	node(int a):x(a){}
	node(){}
};


bool operator <(node a, node b){
 	if(b.x%2==0){
 	 	if(a.x%2)return false;
		else return a.x<b.x;
	}else{
	 	if(a.x%2)return b.x<a.x;
		else return true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,aux;
	cin >> n;
	vector<node> v(n);
	for(int i=0; i<n; i++){
		cin >> aux;
		v[i] = node(aux);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++)cout << v[i].x << '\n';
 	return 0;
}