//Problem @ https://www.hackerrank.com/challenges/strong-password/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/Jnc72
//Time Complexity = 0(n) where n is size of string password

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// length 6 or greater
// password should contain -
// 1 digit ("0123456789")
// 1 lowercase ("abcdefghijklmnopqrstuvwxyz")
// 1 uppercase ("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
// 1 special character ("!@#$%^&*()-+")

int minimumNumber(int n, string password) {
    int changes=0;
    vector<bool> flags={false,false,false,false}; //number @ index0 //lower_case @ index1 //upper_case @ index2 //special_char @ index3
    
    for(size_t i=0;i<n;i++){
        if((int)password[i]>=48 && (int)password[i]<=57) flags[0]=true; //ascii(0)=48 & ascii(9)=57
        else
            if(password[i]>='a' && password[i]<='z') flags[1]=true;
            else
                if(password[i]>='A' && password[i]<='Z') flags[2]=true;
                else flags[3]=true;
    }

    for(size_t i=0;i<flags.size();i++)
        if(flags[i]==false) changes++;

    if(n<6 && changes<(6-n)) changes=6-n;

    return changes;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);
    int n = stoi(n_temp);

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);
    fout << answer << "\n";

    fout.close();

    return 0;
}