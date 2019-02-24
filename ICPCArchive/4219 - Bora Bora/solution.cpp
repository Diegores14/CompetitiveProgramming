#include <bits/stdc++.h>
using namespace std;
vector< pair<int, char> > deck(300);
pair<int, char> topmost;
vector<int> cards;
int var = 1, k = 0, turn = 0;


void rules(map< pair<int, char>, int > &hand) {
    if(topmost.first == 12) {
        var *= -1;
        return;
    }
    if(topmost.first == 7) {
        hand[deck[k++]]++;
        hand[deck[k++]]++;
        cards[turn] += 2;
        turn += var;
        return;
    }
    if(topmost.first == 1) {
        hand[deck[k++]]++;
        turn += var;
        cards[turn]++;
        return;
    }
    if(topmost.first == 11) {
        turn += var;
        return;
    }
}

void sol(map < pair<int, char> , int> &hand) {
    pair<int, char> temp = make_pair(-1, 'a');
    for(int i=13; i>=0; i--) {
        pair<int, char> aux = make_pair(i, topmost.second);
        if(hand[aux] != 0) {
            temp = aux;
            break;
        }
    }
    if( temp.first > topmost.first ) {
        hand[temp]--;
        cards[turn]--;
        topmost = temp;
        return;
    }
    for(char i: {'S', 'H', 'D', 'C'}) {
        pair<int, char> aux = make_pair(topmost.first, i);
        if(hand[aux] != 0) {
            temp = aux;
            break;
        }
    }
    if(temp.first != -1) {
        topmost = temp;
        hand[temp]--;
        cards[turn]--;
    } else {
        temp = deck[k++];
        if(temp.first == topmost.first || temp.second == topmost.second) {
            topmost = temp;
        } else {
            hand[temp]++;
            cards[turn]++;
        }
    }
}

bool isEmpty(map < pair<int, char> , int> &hand ) {
    for(auto &i: hand) {
        if(i.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, m, n;
    while(cin >> p >> m >> n, p || n || m) {
        k = 0; turn = 0, var = 1;
        cards.assign(p, m);
        map< pair<int, char>, int > hands[p];
        for(int i=0; i<n; i++) {
            cin >> deck[i].first >> deck[i].second;
        }
        for(int i=0; i<p; i++) {
            for(int j=0; j<m; j++) {
                hands[i][deck[k++]]++;
            }
        }
        topmost = deck[k++];
        while(true) {
            if(turn < 0) {
                turn += p;
            }
            rules(hands[turn]);
            //cout << topmost.first << topmost.second << turn << ' ' << var <<  '\n';
            if(turn < 0) {
                turn += p;
            }
            turn %= p;
            sol(hands[turn]);
            //cout << topmost.first << topmost.second << turn << ' ' <<  var << '\n';
            if(isEmpty(hands[turn])) {
                cout << turn + 1 << '\n';
                break;
            }
            turn = (turn + var + p)%p;
            //cout << "turn " << turn << '\n';
        }
    }
    return 0;
}