//Problem @ https://www.hackerrank.com/challenges/encryption/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity=O(ceilC*floorR)--->>> O(n^(0.5) * n^(0.5))=>O(n) where n is size of string
//Logic Explained @ https://git.io/JU5LO


#include <bits/stdc++.h>

using namespace std;


string encryption(string s) {
    string result;
    int ceilC=ceil(sqrt(s.size()));
    int floorR=floor(sqrt(s.size())); 

    while(true){
        if(floorR*ceilC>=(int)s.size()){
            for(int i=0;i<ceilC;i++){
                for(size_t j=i;j<s.size();j=j+ceilC)
                    result.push_back(s[j]);
                
                result.push_back(' ');
            }
            return result;
        }else{
            floorR=ceilC;
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}