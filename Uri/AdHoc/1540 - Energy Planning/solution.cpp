#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, a, b, c, d;
	cin >> t;
	cout << fixed << setprecision(2);
	while(t--){
	        cin >> a >> b >> c >> d;
	        string s = to_string(double(b-d)/(a-c));
	        bool res = false;
	        int j=0;
	        for(int i=0; i<(int)s.size() && j<2; i++){
		        if(res) j++;
	        	if(s[i]=='.'){res=true;cout << ',';}	         	
			else cout << s[i];
		}
		if(!res) cout << ".00";
		if(res && j<2)
			for(; j<2; j++)cout << "0";
		cout << '\n';
	}	
	return 0;
}