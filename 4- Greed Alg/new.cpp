#include <iostream>
#include <map>

using namespace std;
int main(){

    map <int,string> mapa;

    if(mapa[10] == "lost"){
        cout <<"oi" << endl;
    }else{
        cout << "ola" << endl;
    }
    return 0;
}