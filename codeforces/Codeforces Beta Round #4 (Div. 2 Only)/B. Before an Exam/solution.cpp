#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int d, sumTime, sumMin=0, sumMax=0;
	vector<int> minTime(d), maxTime(d);
	cin >> d >> sumTime; 
	for(int i=0; i<d; i++){
		cin >> minTime[i] >> maxTime[i];
		sumMin+=minTime[i];
		sumMax+=maxTime[i];
	}
	if(sumTime<sumMin || sumMax<sumTime)cout << "NO\n";
	else{
	 	cout << "YES\n";
		for(int i=0; i<d; i++){
			sumMin-=minTime[i];
			if(sumMin<=sumTime-maxTime[i]){
			 	cout << maxTime[i];
				sumTime-=maxTime[i];
			}else{
			 	cout << sumTime-sumMin;
				sumTime-= (sumTime-sumMin);
			}
			cout << ((i==d-1)? '\n' : ' ');
		}
	}
	return 0;
}