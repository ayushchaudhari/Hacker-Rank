//Problem @ https://www.hackerrank.com/challenges/crush/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JnoYJ
//Time Complexity = O(m+n) where m are queries & n is given array size

//Size of array is n
//number of operations are m
//m lines containing a(from) b(till) k(value to be added)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> split(string str);

long arrayManipulation(int n, vector<vector<int>> queries) {
    long maxVal=0,sum=0;
    vector<long> arr(n);
    
    for(vector<int> query:queries){
        arr[query[0]-1]+=query[2];
        if(arr[query]<n) arr[query[1]]-=query[2];
    }

    for(long i:arr){
        sum+=i;
        maxVal=max(maxVal,sum);
    }
    
    return maxVal;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_m_temp;
    getline(cin, n_m_temp);
    vector<int> n_m = split(n_m_temp);
    int n = n_m[0];
    int m = n_m[1];
    cout<<n<<m;
    vector<vector<int>> queries;
    //taking queries input
    for(int i = 0; i < m; i++) {
        string query_row_temp;
        getline(cin, query_row_temp);
        queries.push_back(split(query_row_temp));
    }
    //fuction calling
    long result = arrayManipulation(n, queries);
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