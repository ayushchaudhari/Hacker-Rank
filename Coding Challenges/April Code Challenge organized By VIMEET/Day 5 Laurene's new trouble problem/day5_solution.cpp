#include <bits/stdc++.h>

using namespace std;

// this is function made to subtract 2 strings using the basic school maths trick
string find_diff(string str1, string str2)
{
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    for (int i = 0; i < n2; i++) {
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
    
    // this logic just cuts the number of extra zeroes coming at the start of the string
    int index=-1;
    int len=str.length();
    if(len>1){      //this condition is applied due to wrong constraint given in problem as there is one test case containing number=1, so to satisfy that this is applied
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                index=i;
                continue;
            }else{
                break;
            }
        }
    }
    // cout<<index<<endl;
    
    if(index!=-1)
        str=str.substr(index+1,len-index);
    return str;
}

int main() {
    string t_case;
    getline(cin,t_case);
    for(long long int i=0;i<stoll(t_case);i++){
        string number;
        getline(cin,number);
        string x=find_diff(number,"1");
        cout<<x<<" 1\n";   
    }
    return 0;
}