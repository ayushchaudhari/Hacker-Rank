//Problem @ https://www.hackerrank.com/challenges/sparse-arrays/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JB2y5
//Time Complexity = O(n), where n is number of queries

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<int> matchingStrings(map<string,int> string_map, vector<string> queries) {
    vector<int> res(queries.size());
    for(size_t i=0;i<queries.size();i++)
        res[i]=string_map.find(queries[i])!=string_map.end()?string_map[queries[i]]:0;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string strings_count_temp;
    getline(cin, strings_count_temp);

    int strings_count = stoi(strings_count_temp);

    map<string,int> string_map;

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);
        if(string_map.find(strings_item)!=string_map.end()){
            string_map[strings_item]++;    
        }else{
            string_map.insert(make_pair(strings_item, 1));
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(queries_count_temp);

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(string_map, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}