#include <bits/stdc++.h>
using namespace std;
long long cant = 0;

struct node {
    int s, a, b;
    int rank;
    node(){}
    void ranking(){
        rank = b-a;
        if(rank > 0) cant+=s;
    }
    bool operator <(node other) const {
        if(rank != other.rank){
            return rank > other.rank;
        }else{
            return s > other.s;
        }
    }
};

int main(){
    long long n, s;
    long long sum =0;
    cin >> n >> s;
    vector<node> v(n+1);
    for(int i=0; i < n; i++){
        cin >> v[i].s >> v[i].a >> v[i].b;
        sum += v[i].s;
        v[i].ranking();
    }
    long long pizzas = (sum + s -1) / s;
    v[n].s = pizzas * s -  sum;
    v[n].a = 0;
    v[n].b = 0;
    v[n].ranking();
    sort(v.begin(), v.end());
    sum = pizzas * s;
    long long limit1 = (cant/s) * s;
    long long limit2 = ((sum-cant)/s) * s;
    long long ans = 0;
    int i = -1, j = n+1;
    while(limit1 > 0){
        i++;
        ans += (long long)v[i].s * v[i].b;
        limit1 -= v[i].s;

    }
    long long temp1 = 0, temp2 = 0;
    if(i>=0 && i<n) {
        ans += limit1 * v[i].b;
        temp1 -= limit1 * v[i].a;
        temp2 -= limit1 * v[i].b;
    }
    while(limit2 > 0){
        j--;
        ans += (long long)v[j].s * v[j].a;
        limit2 -= v[j].s;
    }
    if(0 <= j && j<n) {
        ans += limit2 * v[j].a;
        temp1 -= limit2 * v[j].a;
        temp2 -= limit2 * v[j].b;
    }
    //cout << temp1 << ' ' << temp2 << '\n';
    i++;
    while(i < j){
        temp1 += (long long) v[i].s * v[i].a;
        temp2 += (long long) v[i].s * v[i].b;
        i++;
    }
    ans += max(temp1, temp2);
    cout << ans << '\n';
}