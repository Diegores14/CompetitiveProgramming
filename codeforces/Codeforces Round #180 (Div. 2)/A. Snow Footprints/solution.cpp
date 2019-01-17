 #include <bits/stdc++.h>
 using namespace std;

 int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int Lmin = n, Lmax = -1, Rmin = n, Rmax = -1;
    for(int i=0; i<n; i++) {
        if(s[i] == 'L') {
            Lmin = min(Lmin, i);
            Lmax = i;
        }
        if(s[i] == 'R') {
            Rmin = min(Rmin, i);
            Rmax = i;
        }
    }
    if(Lmin != n && Rmin != n) {
        cout << Rmin + 1 << ' ' << Lmin << '\n'; 
    } else {
        if(Lmin != n) {
            cout << Lmax + 1 << ' ' << Lmin << '\n';
        } else {
            cout << Rmin + 1 << ' ' << Rmax + 2 << '\n';
        }
    }
    return 0;

 }