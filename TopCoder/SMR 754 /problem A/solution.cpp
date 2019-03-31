#include <bits/stdc++.h>
using namespace std;

class MissingDwarf {
    public:
    int getHeight(vector<int> otherHeights) {
        int mmax = 0;
        for(int &i: otherHeights) {
            mmax = max(mmax, i);
        }
        while(true) {
        	mmax++;
        	if(mmax%7 == 0) {
        		break;
        	}
        }
        return mmax;
    }
};

int main() {
    MissingDwarf x;
    cout << x.getHeight({1,2,3,4,5,7}) << '\n';
    return 0;
}