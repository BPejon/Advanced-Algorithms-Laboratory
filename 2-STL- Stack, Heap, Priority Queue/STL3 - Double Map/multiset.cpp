#include <set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){


    string magazine;
    getline(cin, magazine);
    string ransomNote;
    getline(cin, ransomNote);

    sort(magazine.begin(), magazine.end());
    sort(ransomNote.begin(), ransomNote.end());
 
    ///multiset<char> mag(magazine.begin(), magazine.end());
   // multiset<char> ransom(ransomNote.begin(), ransomNote.end());

    // for(char m : mag)
    //     cout << m << " ";
    // cout << endl;
    // for(char r :ransom)
    //     cout << r << " ";
    // cout << endl;
    // if( includes(mag.begin(), mag.end(), ransom.begin(), ransom.end()))
    //     cout << "true"<< endl;
    // else
    //     cout << "false" <<endl;

    if( includes(magazine.begin(), magazine.end(), ransomNote.begin(), ransomNote.end()))
        cout << "true"<< endl;
    else
        cout << "false" <<endl;
    return 0;
}