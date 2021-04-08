#include<bits/stdc++.h>

using namespace std;

int find_steps(int d){
    if(d==1)
        return 0;
    if(d==2)
        return 1;
    if(d==3)
        return 2;
               
    if(d%2==0)
        return 2;
    else
        return 3;
    
}

int main() {
    string str_test_cases;
    getline(cin,str_test_cases);
    int test_cases=stoi(str_test_cases);
    for(int test=0;test<test_cases;test++){
        string input_int;
        getline(cin,input_int);
        int d= stoi(input_int);
        int steps=find_steps(d);
        cout<<steps<<endl;
    }
    return 0;
}