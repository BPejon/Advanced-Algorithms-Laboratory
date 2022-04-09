#include <iostream>
#include <queue>

using namespace std;

//Grafo bipartido
//Grupo de Dragons
// Grupo de Knights
//Cada Knigh deve associar com um ou mais dragoes
//Greedy - Smaller knight with smaller head

//E uma boa pratica colocar a mesma variavel pra fazer varias coisas????
int main(){

    int head, knight;
    cin >> head >> knight;

    while(head != 0 && knight != 0){
        priority_queue <int , vector<int>, greater<int>> headHeight;
        priority_queue <int, vector<int>, greater<int>> knightHeight;
        int headValue, knightValue;
        for(int i = 0 ; i<head; ++i){
            cin >> headValue;
            headHeight.push(headValue);
        }
        for(int j =0 ; j< knight; ++j){
            cin >> knightValue;
            knightHeight.push(knightValue);
        }

        int cost = 0;
        head = headHeight.top();
        while(headHeight.size()!= 0 && knightHeight.size() > 0){
            knight = knightHeight.top();
            knightHeight.pop();


            if(knight >= head){
                cost += knight;
                headHeight.pop();
                head = headHeight.top();
            }
        }

        if(headHeight.size() > 0)
            cout << "Loowater is doomed!"<< endl;
        else    
            cout << cost << endl;

        cin >> head >> knight;
    }
    return 0;
}