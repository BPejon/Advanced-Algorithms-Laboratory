#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

    int nCases, nElements, element;
    stack<int> Stack;
    cin >> nCases;

    for(int i =0; i<nCases; ++i){
        cin >> nElements;
        for(int j =0; j< nElements; ++j){
            cin >> element;
            Stack.push(element);
        }
        while(Stack.empty() != true){
            cout << Stack.top() << "\n";
            Stack.pop();

        }

        if( i+1 != nCases)
            cout << "\n";
    }

    return 0;
}
