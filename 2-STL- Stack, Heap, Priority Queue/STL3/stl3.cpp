#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <queue>

using namespace std;

//If string has all upper case
bool is_all_upper(string& word){
    for(auto c : word){
        if(!isupper(c) && c != ' ')
            return false;
    }
    return true;
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
            priority_queue<pair<int,string>> print;
            for(auto i : projectMap){
                print.push({i.second,i.first});
                //cout << "PROJECT NAME IS :" << i.first << "- SUBSCRIBED: "<< i.second <<endl;
            }

            while(print.size()){
                cout << "PROJECT NAME IS :" << print.top().second << "- SUBSCRIBED: "<< print.top().first <<endl;
                print.pop();
            }
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

            }else if(studentsMap[studentName] == "banned"){
                break;

            }else if(studentsMap[studentName] != projectName){
                --projectMap[studentsMap[studentName]];
                studentsMap[studentName] = "banned";
            }
        }

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