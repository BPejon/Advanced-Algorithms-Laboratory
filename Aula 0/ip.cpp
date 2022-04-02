#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <map>

using namespace std;
int main(){
        int numSites, numCommands;
        
        cin >> numSites >> numCommands;
        //Get input for sites and ip
        string nameSite;
        string ipaddress;

        map<string,string> siteMap;
        for (int i =0; i < numSites; ++i){
            cin >> nameSite >> ipaddress ;
            //scanf("%s %s", nameSite, ipadress );    //doenst work cause %s expect 'char*' and namesite is 'std::string'

            //First is the key
            siteMap.insert(pair<string,string>(ipaddress, nameSite));

            //cout << "\n\n";
            //cout << "ip : " << siteMap.find(ipaddress)->first<< " Name: " << siteMap.find(ipaddress)->second << "\n";
        }

    
        //Commandss
        string nameCommand;
        for(int j = 0; j< numCommands; ++j){
            cin >> nameCommand >> ipaddress ;
            ipaddress.pop_back();
            cout << nameCommand << " " << ipaddress << "; #" << siteMap.find(ipaddress)->second << "\n";
        }
    return 0;
}

//Depende da aplicacao da pra melhorar o mapa