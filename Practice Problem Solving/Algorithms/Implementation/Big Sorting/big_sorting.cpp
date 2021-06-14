//Problem @ https://www.hackerrank.com/challenges/big-sorting/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity = O(n*d) where n is number of inputted big integers and d is digits in the that number as in worst case it can go in checking each digit also
//Logic Explained @ https://git.io/JnTwI

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string a, string b){
    return a.length() == b.length()? a < b : a.length() < b.length();
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(),unsorted.end(),check);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin,n_temp);
    int n = stoi(n_temp);
    
    vector<string> unsorted;
    
    for (int i = 0; i < n; i++) {
        string num;
        getline(cin,num);
        
        unsorted.push_back(num);
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++)
        fout << result[i]<<endl;        

    fout.close();

    return 0;
}
