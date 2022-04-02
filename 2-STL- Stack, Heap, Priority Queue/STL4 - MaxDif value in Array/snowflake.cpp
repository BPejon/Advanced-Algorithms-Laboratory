#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    int nSnowflakes, id, totalDif;

    unordered_map<int, int> posMap;
    
    for (int i =0; i< nCases; ++i){
        cin >> nSnowflakes;
        totalDif = 0;
        vector<int> snowflakevec; //vector reset
        for (int j =0; j< nSnowflakes; ++j){
            cin >> id;
            snowflakevec.push_back(id);
        }

        int k = 0;
        
        while(k < (int)snowflakevec.size()){
       
            if(posMap.find(snowflakevec[k]) == posMap.end()){
                posMap[snowflakevec[k]] = k;
                ++k;

            }else{
                if(totalDif < (int)posMap.size())
                    totalDif = (int)posMap.size();
                k = posMap[snowflakevec[k]] +1;
                posMap.clear();
            }

            if(totalDif < (int)posMap.size())
                totalDif = (int)posMap.size();
        }
        
        cout << totalDif << "\n";
        posMap.clear();
    }
    return 0;
}