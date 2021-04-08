#include <bits/stdc++.h>

using namespace std;

string findItsPossibleOrNot(int flour){
    if(flour%2==0 && flour!=2)
        // if((flour/2)%2==0)
        return "YES";
        // else    
        //     return "NO";
    else
        return "NO";
}

int main() {
    
    int flour;
    cin>>flour;
    //getline(cin,flour);

    cout<< findItsPossibleOrNot(flour);
    // cout<<itsPossibleOrNot;
    return 0;
}