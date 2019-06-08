#include <bits/stdc++.h>
using namespace std;
const int tam = 2e6;
unsigned long long inv = 0;
unsigned long long a[tam];

void Merge(int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int left[n1+1], right[n2+1];
    for(int i = 0; i < n1; i++) {
        left[i] = a[l+i];
    }
    for(int i = 0; i < n2; i++) {
        right[i] = a[mid+i+1];
    }
    left[n1] = 1e9;
    right[n2] = 1e9;
    int i = 0;
    int j = 0;
    for(int k = l; k <= r; k++) {
        if(left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
            inv += n1 - i;
        }
    }
} 

void MergeSort(int l, int r) {
    if( l < r ) {
        int mid = (l+r)>>1;
        MergeSort(l, mid);
        MergeSort(mid+1, r);
        Merge(l, mid, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n, n) {
        inv = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        MergeSort(0, n-1);
        cout << inv << '\n';
    }
    return 0;
}