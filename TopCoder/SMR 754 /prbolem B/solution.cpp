#include <bits/stdc++.h>
using namespace std;

class SeventhPowers {
    public:
    string reconstructA(int B) {
        string ans;
        int a[9] = {4782969, 2097152, 823543, 279936, 78125, 16384, 2187, 128, 1};
        int pos = 0, mmin = 1000000000;
        for(int k=1; k<(1<<9); k++) {
            int temp = B;
            int acc = 0;
            for(int i = 0; i<9; i++) {
                if((k>>i)&1){
                    acc += temp/a[i];
                    temp %= a[i];
                }
            }
            if(acc < mmin && temp == 0) {
                pos = k;
                mmin = acc;
            }
        }
        for(int i = 0; i<9; i++) {
            if((pos>>i)&1){
                for(int j=0; j<B/a[i]; j++) {
                    ans.push_back('0'+9-i);
                }
                B %= a[i];
            }
        }
        return ans;
    }
};

int main() {
    SeventhPowers x;
    cout << x.reconstructA(10000000) << '\n';
    return 0;
}