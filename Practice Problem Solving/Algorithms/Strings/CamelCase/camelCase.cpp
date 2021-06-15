//Problem @ https://www.hackerrank.com/challenges/camelcase/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/Jn35N
//Time Complexity = O(n)

#include <bits/stdc++.h>

using namespace std;

int camelcase(string s) {
    int words=0;
    for(size_t i=0;i<s.size();i++)
        if(s[i]>='A' && s[i]<='Z')
            words++;
                
    return words+1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);
    fout << result << "\n";
    fout.close();

    return 0;
}
