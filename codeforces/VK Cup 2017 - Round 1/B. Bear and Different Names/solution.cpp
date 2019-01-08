#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector< string > v({"A","B","C","D","E","F","G","H","I","J",
                        "Aa","Ba","Ca","Da","Ea","Fa","Ga","Ha","Ia","Ja",
                        "Ab","Bb","Cb","Db","Eb","Fb","Gb","Hb","Ib","Jb",
                        "Ac","Bc","Cc","Dc","Ec","Fc","Gc","Hc","Ic","Jc",
                        "Ad","Bd","Cd","Dd","Ed","Fd","Gd","Hd","Id","Jd"});
    int n, k;
    cin >> n >> k;
    string temp;
    for(int i=0; i < n-k+1; i++){
        cin >> temp;
        if ( temp == "NO" )
            v[i+k-1] = v[i]; 
    }
    for(int i=0; i<n; i++){
        cout << v[i] << (i==n-1? '\n' : ' ');
    }
    return 0;
}