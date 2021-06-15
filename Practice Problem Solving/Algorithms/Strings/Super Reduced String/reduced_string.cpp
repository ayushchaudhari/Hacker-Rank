//Problem @ https://www.hackerrank.com/challenges/reduced-string/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/Jn3VL
//Time Complexity = O(n)

#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
    string result_str="";

    for(size_t i=0; i<s.size(); i++){
        if(s[i]==s[i+1])
            i++;
        else
            result_str.push_back(s[i]);
    }
    
    if(s!=result_str && result_str!="") result_str = superReducedString(result_str);
    if(result_str=="") result_str = "Empty String";
        
    return result_str; 
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);
    fout << result << "\n";
    fout.close();

    return 0;
}