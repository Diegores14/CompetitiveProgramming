#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f;

bool val() {
    if(a == 0 && b && c && d) return true;
    if(c == 0 && d) return true;
    if(e == 0 && f && a && b && c && d) return true;
    if(a && c && e && (b*d*f+a*c*e-1)/(a*c*e) > 1 ) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    if(val()) {
            cout << "Ron\n";
    } else {
        cout << "Hermione\n";
    }
    return 0;
}