//Problem @ https://www.hackerrank.com/challenges/insertionsort1/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity = O(n^2) where n is size of arr to be sorted
//Logic Explained @ https://git.io/JnnCs

#include <bits/stdc++.h>

using namespace std;

vector<int> split(string str);

void displayArr(vector<int> arr){
    for(size_t i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void insertionSort1(int n, vector<int> arr) {
    for(size_t i=0; i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int key = arr[i+1];
            size_t j=i;
            while(arr[j]>key){
                arr[j+1]=arr[j];
                j--;
                displayArr(arr);
            }
            arr[j+1]=key;
            displayArr(arr);
        }
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

    insertionSort1(n, arr);

    return 0;
}

vector<int> split(string str) {
    vector<int> arr;

    for(size_t i=0;i<str.size(); i++){
        string temp;
        while (str[i]!=' ' && i<str.size())
            temp.push_back(str[i++]);
        arr.push_back(stoi(temp));
    }
    
    return arr;
}
