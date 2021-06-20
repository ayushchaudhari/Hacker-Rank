//Problem @ https://www.hackerrank.com/challenges/dynamic-array
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JnoWr
//Time Complexity = O(q) where q is total number of queries

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> split(string str);

//queries contains 3 integer like - 1 x y or 2 x y
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> answers;
    vector<vector<int>> arr(n);
    int lastAns;
    
    for(size_t i=0;i<queries.size();i++){
        if(queries[i][0]==1){
            int idx = ((queries[i][1]^lastAns)%n);//x=queries[i][1]
            arr[idx].push_back(queries[i][2]);//y=queries[i][2]
        }
        else{
            int idx = ((queries[i][1]^lastAns)%n);//x=queries[i][1]
            lastAns = arr[idx][queries[i][2] % arr[idx].size()]; //y=queries[i][2]
            answers.push_back(lastAns);
        }
    }
    
    return answers; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_q_temp;
    getline(cin, n_q_temp);
    vector<int> n_q = split(n_q_temp);
    int n = n_q[0];
    int q = n_q[1];

    vector<vector<int>> queries;
    for (int i = 0; i < q; i++) {
        string queries_temp;
        getline(cin, queries_temp);
        queries.push_back(split(queries_temp));
    }
    
    vector<int> result = dynamicArray(n, queries);
    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) fout << "\n";
    }
    
    fout << "\n";
    fout.close();
    return 0;
}

vector<int> split(string str) {
    vector<int> vec;
    
    for(size_t i=0; i<str.size(); i++){
        string temp;
        while (str[i]!=' ' && i<str.size())
            temp.push_back(str[i++]);
            
        vec.push_back(stoi(temp));
    }
    
    return vec;
}