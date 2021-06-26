//Problem @ https://www.hackerrank.com/challenges/arrays-ds/problem 
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JceAc
//Time Complexity = O(n) ; where n is the size of given array to be reversed

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string str);

vector<int> reverseArray(vector<int> a) {
    vector<int> reverse_a;
    for(int i=a.size()-1;i>=0;i--)
        reverse_a.push_back(a[i]);
    return reverse_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string n_temp;
    getline(cin,n_temp);
    int n=stoi(n_temp);

    string arr_temp;
    getline(cin, arr_temp);
    vector<int> arr = split(arr_temp);

    vector<int> res = reverseArray(arr);
    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];
        if (i != res.size() - 1) {
            fout << " ";
        }
    }
    
    fout << "\n";
    fout.close();
    
    return 0;
}

vector<int> split(string str) {
    vector<int> vec;
    for(size_t i=0;i<str.size();i++){
        string temp;
        while(str[i]!=' ' && i<str.size())
            temp.push_back(str[i++]);
        vec.push_back(stoi(temp));
    }
    return vec;
}