#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	int match1[2],match2[2];
	char c;
	cin >> n;
	while(n--){
		cin >> match1[0] >> c >> match1[1];
		cin >> match2[0] >> c >> match2[1];
		if(match1[0]+match2[1]>match2[0]+match1[1])cout << "Time 1\n";
		if(match1[0]+match2[1]<match2[0]+match1[1])cout << "Time 2\n";
		if(match1[0]+match2[1]==match2[0]+match1[1]){
		 	if(match2[1]>match1[1])cout << "Time 1\n";
		 	if(match2[1]<match1[1])cout << "Time 2\n";
		 	if(match2[1]==match1[1])cout << "Penaltis\n";
		}
	}
 	return 0;
}