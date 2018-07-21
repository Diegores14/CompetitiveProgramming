#include <bits/stdc++.h>
using  namespace std;
typedef pair<int,int> pii;

vector<int> tim(70000);
                     
struct node{
  	int d, p, di;
  	node(int _d, int _p){d=_d;p=_p;di=p/d;}
  	node(){d=0; p=0;di=0;}
};

bool operator <(node a, node b){
 	return a.di>b.di;

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, t, k=1, d, p, total, sum, i, answer;
	while(cin >> n >> t, n){
		vector<node> v(n);
	 	for(i=0; i<n; i++){cin >> d >> p; v[i]=node(d,p);}
	 	sort(v.begin(), v.end());
		sum=total=answer=i=0;		
		while(i<n){			
		 	sum = total + v[i].d;
			if(sum<=t){
				answer+= v[i].p;
				total+= v[i].d;
			}else i++;
		}
		cout << "Instancia " << k++ << '\n' << answer << "\n\n";
	}
	return 0;
}