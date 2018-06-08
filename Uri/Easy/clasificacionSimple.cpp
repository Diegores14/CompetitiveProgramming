#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i < (int)n; ++i)
#define all(x) (x).begin(), (x).end()                

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	vector<int> v(3), aux(3);
	forn(i, 3)cin>>v[i];
	aux = v;
	sort(all(aux));
	forn(i,3)cout<<aux[i]<<'\n';
	cout<<'\n';
	forn(i,3)cout<<v[i]<<'\n';
	return 0;
}