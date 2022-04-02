#include <iostream>
#include <queue>
using namespace std;

int main(){

    int numbers, total, n;
    priority_queue <int, vector<int>, greater<int> > queue;
    int a,b;
    cin >> numbers;

    while(numbers != 0 ){
        total = 0;
        for (int i = 0 ; i< numbers; ++i){
            cin >> n;
            queue.push(n);
        }

        while(queue.size() > 1){
            a = queue.top();
            queue.pop();
            b = queue.top();
            queue.pop();
            total += a+b; 
            queue.push(a+b);
        }


        cout << total <<"\n";
        cin >> numbers;
        queue.pop();
    }

    return 0;
}