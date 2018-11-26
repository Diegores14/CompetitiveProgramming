#include <bits/stdc++.h>
using namespace std;
map<char, int> order;

void firstRule(map<char, int>  values[2]){
    vector<int> v[2];
    for(int i=0; i<2; i++){
        for(auto j: values[i]){
            for(int k=0; k < j.second; k++)
                v[i].emplace_back(order[j.first]);
        }
    }
    sort(v[0].begin(), v[0].end(), greater<int>());
    sort(v[1].begin(), v[1].end(), greater<int>());
    for(int i=0; i<5; i++){
        if(v[0][i] != v[1][i]){
            cout << ((v[0][i] > v[1][i])? "Black wins.\n" : "White wins.\n");
            return;
        }
    }
    cout << "Tie.\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<vector<string>> cards(2, vector<string> (5));
    order['2'] = 0;
    order['3'] = 1;
    order['4'] = 2;
    order['5'] = 3;
    order['6'] = 4;
    order['7'] = 5;
    order['8'] = 6;
    order['9'] = 7;
    order['T'] = 8;
    order['J'] = 9;
    order['Q'] = 10;
    order['K'] = 11;
    order['A'] = 12;
    while(true){
        map<char, int> suit[2], values[2];
        vector<int> maxsuit(2, 0), maxValue(2, 0), minValue(2, 10000);
        for(int i=0; i<2; i++){
            for(int j=0; j<5; j++){
                if(cin >> cards[i][j]){
                    suit[i][cards[i][j][1]]++;
                    maxsuit[i] = max(maxsuit[i], suit[i][cards[i][j][1]]);
                    values[i][cards[i][j][0]]++;
                    maxValue[i] = max(maxValue[i], order[cards[i][j][0]]);
                    minValue[i] = min(minValue[i], order[cards[i][j][0]]);
                }
                else
                    return 0;
            }
        }
        bool player[2];
        player[0] = (maxsuit[0] == 5 && maxValue[0]-minValue[0] == 4 && values[0].size() == 5);
        player[1] = (maxsuit[1] == 5 && maxValue[1]-minValue[1] == 4 && values[1].size() == 5);
        if(player[0] || player[1]){
            // cout << "Straight flush\n";
            if(player[0] && player[1]){
                if(maxValue[0] == maxValue[1]) cout << "Tie.\n";
                else cout << ((maxValue[0] > maxValue[1])? "Black wins.\n" : "White wins.\n");
            }else{
                cout << (player[0]? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        char carta[2] = {'p', 'p'};
        for(int j=0; j<2; j++)
            for(auto i: values[j]){
                if(i.second == 4)
                    carta[j] = i.first;
            }
        if(carta[0] != 'p' || carta[1] != 'p'){
            // cout << "Four of a kind.\n";
            if(carta[0] != 'p' && carta[1] != 'p'){
                if(carta[0] == carta[1]) cout << "Tie.\n";
                else cout << ((order[carta[0]] > order[carta[1]])? "Black wins.\n" : "White wins.\n");
            }else{
                cout << ((carta[0] != 'p')? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        for(int j=0; j<2; j++)
            for(auto i: values[j]){
                if(i.second == 3)
                    carta[j] = i.first;
            }
        if(values[0].size() == 2 || values[1].size() == 2){
            // cout << "Full House.\n";
            if(values[0].size() == 2 && values[1].size() == 2){
                if(carta[0] == carta[1]) cout << "Tie.\n";
                else cout << ((order[carta[0]] > order[carta[1]])? "Black wins.\n" : "White wins.\n");
            }else{
                cout << ((values[0].size() == 2)? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        if(maxsuit[0] == 5 || maxsuit[1] == 5){
            // cout << "Flush.\n";
            if(maxsuit[0] == 5 && maxsuit[1] == 5){
                firstRule(values);
            }else{
                cout << ((maxsuit[0] == 5)? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        player[0] = (maxValue[0]-minValue[0] == 4 && values[0].size() == 5);
        player[1] = (maxValue[1]-minValue[1] == 4 && values[1].size() == 5);
        if(player[0] || player[1]){
            // cout << "Straight.\n";
            if(player[0] && player[1]){
                if(maxValue[0] == maxValue[1]) cout << "Tie.\n";
                else cout << ((maxValue[0] > maxValue[1])? "Black wins.\n" : "White wins.\n");
            }else{
                cout << (player[0]? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        if(carta[0] != 'p' || carta[1] != 'p'){
            // cout << "Three of a Kind.\n";
            if(carta[0] != 'p' && carta[1] != 'p'){
                if(carta[0] == carta[1]) cout << "Tie.\n";
                else cout << ((order[carta[0]] > order[carta[1]])? "Black wins.\n" : "White wins.\n");
            }else{
                cout << ((carta[0] != 'p')? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        if(values[0].size() == 3 || values[1].size() == 3){
            // cout << "Two Pairs.\n";
            if(values[0].size() == 3 && values[1].size() == 3){
                vector<int> aux[2];
                int aux1[2];
                for(int j=0; j<2; j++){
                    for(auto i : values[j]){
                        if(i.second == 2)
                            aux[j].emplace_back(order[i.first]);
                        else   
                            aux1[j] = order[i.first];
                    }
                    if(aux[j][0] < aux[j][1]) swap(aux[j][0],aux[j][1]);
                }
                if(aux[0][0] == aux[1][0]){
                    if(aux[0][1] == aux[1][1]){
                        if(aux1[0] == aux1[1]) cout << "Tie.\n";
                        else cout << ((aux1[0] > aux1[1])? "Black wins.\n" : "White wins.\n");
                    }else{
                        cout << ((aux[0][1] > aux[1][1])? "Black wins.\n" : "White wins.\n");
                    }
                }else{
                    cout << ((aux[0][0] > aux[1][0])? "Black wins.\n" : "White wins.\n");
                }
            }else{
                cout << ((values[0].size() == 3)? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        if(values[0].size() == 4 || values[1].size() == 4){
            //cout << "Pair.\n";
            if(values[0].size() == 4 && values[1].size() == 4){
                int aux[2];
                for(int j=0; j<2; j++){
                    for(auto i : values[j]){
                        if(i.second == 2)
                            aux[j] = order[i.first];
                    }
                }
                if(aux[0] == aux[1]){
                    firstRule(values);
                }else{
                    cout << ((aux[0] > aux[1])? "Black wins.\n" : "White wins.\n");
                }
            }else{
                cout << ((values[0].size() == 4)? "Black wins.\n" : "White wins.\n");
            }
            continue;
        }
        firstRule(values);
    }
    return 0;
}