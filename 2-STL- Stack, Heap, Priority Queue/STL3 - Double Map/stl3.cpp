#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
/*
class comparator_class {
public:
    // Comparator function
    bool operator(object o1, object o2)
    {
  
        // There can be any condition
        // implemented as per the need
        // of the problem statement
        return (o1.data_member
                == o2.data_member);
    }
}*/

//If string has all upper case
// bool is_all_upper(string& word){
//     for(auto c : word){
//         if(!isupper(c) && c != ' ')
//             return false;
//     }
//     return true;
// }

bool is_all_upper(string &word){
    for( auto c: word){
        if(c >= 97 && c<= 122 ) //ASCII for small letter
            return false;
    }

    return true;
}

bool comp_Numerical_decres( const pair<int,string> a, const pair<int, string> b){
    if (a.first > b.first) // True - a goes before -- So stay False - Dont go before, a goes after b - switch
        return true;

    return false;
}

bool comp_Alphabet(const pair<int,string> a, const pair<int,string> b){
    if(a.first != b.first)
        return false;
    
    else if(a.second.compare(b.second) > 0)
        return false;
        
    return true;


}


void print_vec_ans(vector<pair<int,string>> print){
    for(auto i: print)
        cout << i.second<< " " << i.first << endl;


}


void printMapProject(map<string,int>m){
    for( auto i: m)
        cout <<"Project: " << i.first << " Nmb: "<< i.second << endl;
}
void printMapStudent(map<string,string> m){
    for( auto i: m)
        cout << "Student: " << i.first << " Group:" << i.second << endl;

}
//One Map for Projects <Name,Nmb of students>
//One map for Students <Name, Project subscribed>
//If student subscribed for more than one project, he/she is banned
//O(n) Time Complexity
//O(nlogn) Space Complexity
int main(){
    string projectName, studentName, plainName;
    map<string,int> projectMap;
    map<string,string> studentsMap;
    getline(cin, plainName);
    while(plainName != "0"){
        if(plainName == "1"){
            //Print Results
            vector<pair<int, string>> print;
            for(auto k :projectMap)
                print.push_back({k.second,k.first});

            sort(print.begin(),print.end(), comp_Numerical_decres); // Sort by numerical order
            sort(print.begin(),print.end(), comp_Alphabet); // Sort alphabetical order

            print_vec_ans(print);
            
            projectMap.clear();
            studentsMap.clear();

        }else if(is_all_upper(plainName)){
            projectName = plainName;
            projectMap[projectName];

        }else{
            studentName = plainName;
            if(studentsMap.find(studentName) == studentsMap.end()){
                studentsMap[studentName] = projectName;
                ++projectMap[projectName];
            /* whe break breaks everything????????
            }else if(studentsMap[studentName] == "banned"){
                break;
*/
            }else if(studentsMap[studentName] == "banned"){
            }else if(studentsMap[studentName] != projectName){
                --projectMap[studentsMap[studentName]];
                studentsMap[studentName] = "banned";
            }
        }

        //printMapStudent(studentsMap);
        //printMapProject(projectMap);
        getline(cin, plainName);
    }

   

    return 0;   
}



/* Advanced Algorithms Laboratory I

    if(map[value]){
        return the value of map[value]
        if theres no - return 0
        So if ur problem doenst acept zero u need to use
    if(map.find(value) == map.end())
        to see if the value exists or not   
    }

*/