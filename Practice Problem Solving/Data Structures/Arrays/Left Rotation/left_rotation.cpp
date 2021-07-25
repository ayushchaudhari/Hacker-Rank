//Problem @ https://www.hackerrank.com/challenges/array-left-rotation/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/J4gcR
//Time Complexity = O(1) Time complexity for the logic ,but to print the array O(n) is the time complexity(where n is the size of given array)

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

vector<int> split(string str){
    vector<int> arr;
    
    for(size_t i=0;i<str.size();i++){
        string temp;
        while(str[i]!=' ' && i<str.size())
            temp.push_back(str[i++]);
        arr.push_back(stoi(temp));
    }
    
    return arr;   
}

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> result;
    d%=arr.size();
    int i=d;
    do{
        result.push_back(arr[i]);
        i++;
        if(i==arr.size())
            i=0;
    }while(i!=d);
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string input_nd;
    getline(cin, input_nd);
    vector<int> nd = split(input_nd);
    
    string arr_temp;
    getline(cin, arr_temp);
    vector<int> arr = split(arr_temp);

    vector<int> result = rotateLeft(nd[1], arr);    //nd[0]->n & nd[1]->d
    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }
    
    fout << "\n";
    fout.close();

    return 0;
}