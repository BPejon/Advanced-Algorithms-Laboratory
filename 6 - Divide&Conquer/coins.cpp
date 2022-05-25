#include <iostream>
#include <vector>
using  namespace std;

//Greedy algorithm
//O(Raiz(N)) -- PA formula
//2^31 = 10^9
//Raiz = 10^4 Total
/*
int main(){
    int coins;
    int ladder = 0;
    cin >> coins;

    while(coins >= ladder){
        coins = coins - ladder;
        ++ladder;
    }

    --ladder;

    cout << ladder;
    return 0;
}
*/
//Divide and Conquer Algorithm
// O(long2(n)) -- Much faster
//2^31 = 10^9
//log2(10^9) = 30

int recursive_conq(vector<int> ladder){


    


}
int main(){

    int coins;

    vector<int>ladder;
    cin >> coins;

    int inf=0 , sup = INT_MAX;

    cout << recursive_conq(ladder);

    return 0;
}