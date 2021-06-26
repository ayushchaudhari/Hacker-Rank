//Problem @ https://www.hackerrank.com/challenges/2d-array/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JcvqV
//Time Complexity = O(n^2) or more preciesly O(r*c); where r->row & c->col of the given matrix

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string str);

int hourglassSum(vector<vector<int>> arr) {
    int maxSum=-10000;
    for(size_t row=0;row<arr.size();row++){
        for(size_t col=0;col<arr[row].size();col++){
            int sum=arr[row][col]+arr[row][col+1]+arr[row][col+2]+arr[row+1][col+1]+arr[row+2][col]+arr[row+2][col+1]+arr[row+2][col+2];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr;
    for (int i = 0; i < 6; i++) {
        string arr_row_temp;
        getline(cin, arr_row_temp);
        vector<int> arr_row = split(arr_row_temp);
        arr.push_back(arr_row);
    }

    int result = hourglassSum(arr);

    fout << result << "\n";
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