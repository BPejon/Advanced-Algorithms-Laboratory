#include <iostream>
#include <queue>

using namespace std;

// Function to print the data of
// the priority queue ordered by first
void showpq(
    priority_queue<pair<int, int> > g)
{
    // Loop to print the elements
    // until the priority queue
    // is not empty
    while (!g.empty()) {
        cout << g.top().first
             << " " << g.top().second
             << endl;
        g.pop();
    }
    cout << endl;
}


int main(){
    int nCases;
    cin >> nCases;

    for(int i =0; i< nCases; ++i){
        int nJobs, urJobPos;
        cin >> nJobs >> urJobPos;   

        //Get the jobs
        queue <int> entrance;
        for(int j =0; j < nJobs; ++j){
            int priority;
            cin >> priority;
            entrance.push(priority);
        }

        //Put jobs in priority queue
        priority_queue<pair<int,int>> printer;
        int k=0;
        while(entrance.size()){
            printer.push({entrance.front(), k});
            entrance.pop();
            ++k;
        }  

        //showpq(printer);

        //Find your Job
        int time = 0;
        //Why map I use map.find()->second and priority queue printer.top().second? it has something to do with pointer right?
        while(printer.size()){
            ++time;
            if(printer.top().second == urJobPos){
                cout << time << endl;
                break;
            }
            printer.pop();

        }
    }
    return 0;
}