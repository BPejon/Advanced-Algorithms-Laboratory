#include<iostream>
#include<string>
#include<queue>
#include <stack>

using namespace std;

//print numbers
// while(numbers.empty() == false){
//             int a = numbers.top();
//             numbers.pop();
//             cout << a << endl;
//         }

//print op
        

        // while(op.empty() == false){
        //     char b = op.top();
        //     op.pop();
        //     cout << b << endl;
        // }


unsigned long int minimum(stack<unsigned long int> numbers, stack<char>op){
    stack<unsigned long int> numbers2;
    stack<char> op2;
    unsigned long int a,b, sum;
    char o;

    while(op.empty() == false){
        a = numbers.top(); numbers.pop();
        b = numbers.top(); numbers.pop();
        o = op.top();op.pop();

        if(o == '+'){
            op2.push(o);
            numbers2.push(a);
            numbers.push(b);
        }else{
            sum = a*b;
            numbers.push(sum);
        }
    }

    numbers2.push(numbers.top());

    while(op2.empty() == false){
        a = numbers2.top(); numbers2.pop();
        b = numbers2.top(); numbers2.pop();
        op2.pop();

        sum = a+b;
        numbers2.push(sum);
    }

    return numbers2.top();
}

unsigned long int maximum(stack<unsigned long int> numbers, stack<char>op){
    stack<unsigned long int> numbers2;
    stack<char> op2;
    unsigned long int a,b,sum;
    char o;

    while(op.empty() == false){
        a = numbers.top();numbers.pop();
        b = numbers.top();numbers.pop();
        o = op.top();op.pop();

        if(o == '*'){
            op2.push(o);
            numbers2.push(a);
            numbers.push(b);
        }else{
            sum = a+b ;
            numbers.push(sum);
        }
    }

    numbers2.push(numbers.top());
    while(op2.empty() == false){
        a = numbers2.top(); numbers2.pop();
        b = numbers2.top(); numbers2.pop();
        op2.pop();
        sum = a*b;
        numbers2.push(sum);
    }
    
    return numbers2.top();
}
//vetor com somas parciais e vetor com somas de multiplicacoes
//Max of 12 numbers [1,20] so max value will be 20pow12 = 4e15 - so int can be overfloated
// so used unsigned long int
int main(){
    int numbstring;
    cin >> numbstring;
    string s;
    for(int i=0 ; i< numbstring; ++i){
        cin >> s;
        stack <unsigned long int> numbers;
        stack<char> op;

        for(long long unsigned int j = 0; j<s.size() ; ++j){
            switch(s[j]){
                case '*':
                case '+': op.push(s[j]);break;
                default: 
                    if(isdigit(s[j])){
                        if(isdigit(s[j+1])){
                            numbers.push( (s[j]-'0')*10 + (s[j +1] - '0') ); 
                            ++j;
                        }else
                            numbers.push((s[j]- '0'));
                    }
                break;
            }
        }

        //Get the minimun 
        //multiply then sum
        unsigned long int min = minimum(numbers, op);

        //get the maximun
        //Sum then multiply
        unsigned long int max = maximum(numbers, op);

        cout << "The maximum and minimum are " <<max << " and " << min<< "."<<endl;
    }   
    return 0;
}

