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
        queue <pair<int,bool>> entrance;
        priority_queue <int> printer;
        for(int j =0; j < nJobs; ++j){
            int priority;
            cin >> priority;
            printer.push(priority);

            if(j == urJobPos)
                entrance.push({priority,true});
            else
                entrance.push({priority, false});
        }

        //print the paper
        int time = 0;
        while(printer.size()){
            //If diff, go to back of the line
            if(printer.top() != entrance.front().first){
                entrance.push(entrance.front());
                entrance.pop();
            }else if(entrance.front().second == true){
                ++time;
                break;
            }else{
                ++time;
                printer.pop();
                entrance.pop();
            }
        }

        cout << time << endl;
    }


    return 0;
}



//DOING ONLY ONE PRIORITY QUEUE - FAIL
// int main(){
//     int nCases;
//     cin >> nCases;

//     for(int i =0; i< nCases; ++i){
//         int nJobs, urJobPos;
//         cin >> nJobs >> urJobPos;   

//         //Get the jobs
//         queue <int> entrance;
//         for(int j =0; j < nJobs; ++j){
//             int priority;
//             cin >> priority;
//             entrance.push(priority);
//         }

//         //Put jobs in priority queue
//         priority_queue<pair<int,int>> printer;
//         int k=0;
//         while(entrance.size()){
//             printer.push({entrance.front(), k});
//             entrance.pop();
//             ++k;
//         }  

//         //showpq(printer);

//         //Find your Job
//         int time = 0;
//         //Why map I use map.find()->second and priority queue printer.top().second? it has something to do with pointer right?
//         while(printer.size()){
//             ++time;
//             if(printer.top().second == urJobPos){
//                 cout << time << endl;
//                 break;
//             }
//             printer.pop();

//         }
//     }
//     return 0;
// }

/*
class Solution {
public:
    int convertTime(string current, string correct) {
        //Parse String
        int op = 0,hours1, hours2, minutes1,minutes2, rest;
        stringstream ss, ss2;
        char extra;
        
        ss << current;
        ss2 <<correct;
        
        ss >> hours1 >>extra >> minutes1;
        ss2 >> hours2 >> extra >> minutes2;
        
        int time = ( hours2*60 + minutes2)- (hours1*60 + minutes1);
        
        op += (int)time/60;
        time = (int)time%60;
        
        op += (int)time/15;
        time = (int)time%15;
        
        op += (int)time/5;
        time = (int)time%5;
        
        op += (int)time/1;
        
        return op;      
    }
};
*/