#include <bits/stdc++.h>

using namespace std;


int main() {
    string length,number;
    getline(cin,length);
    getline(cin,number);
    int l=stoi(length);
    // int n=stoi(number);
    

    
    if(l<11){
        cout<<"0";
        return 0;
    }
    if(l>=11){
        int how_many_can_made=l/11;
        int cnt=count(number.begin(),number.end(),'8');
        if(how_many_can_made>=cnt)
            cout<<cnt;
        else{
            if(how_many_can_made<cnt)
                cout<<how_many_can_made;
        }
    }
    
    return 0;
}
