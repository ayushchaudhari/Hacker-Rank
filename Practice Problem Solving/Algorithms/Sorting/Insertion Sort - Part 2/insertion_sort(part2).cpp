//Problem @ https://www.hackerrank.com/challenges/insertionsort2/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity = O(n^2) where n is size of arr to be sorted
//Logic Explained @ https://git.io/JnPDu

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string str);

void display_arr(vector<int> arr){
    for(auto it=arr.begin();it!=arr.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}

void insertionSort2(int n, vector<int> arr) {
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int ele=arr[i+1];
            int pos=i;
            while(arr[i]>ele){
                arr[i+1]=arr[i];
                i--;
            }
            arr[i+1]=ele;
            i=pos; 
        }
        display_arr(arr);
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(n_temp);

    string arr_temp;
    getline(cin, arr_temp);
    vector<int> arr = split(arr_temp);
    insertionSort2(n, arr);

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