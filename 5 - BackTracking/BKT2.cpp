#include <iostream>
#include <vector>   
#include <string>
#include <stdio.h>

using namespace std;
int main(){

    int n, m;

    cin >> n >> m;
    
    vector<vector<char>> board(n, vector<char>(m));
    
    for(int i = 0; i<n ; ++i){
        for ( int j= 0; j < m; j++){
            scanf("%c",&board[i][j]); 
        }
    }

    for(int i = 0; i<n ; ++i){
        for ( int j= 0; j < m; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    int k;
    cin >> k;
    string word;

    getline(cin, word);
    cout << word;





    return 0;
}