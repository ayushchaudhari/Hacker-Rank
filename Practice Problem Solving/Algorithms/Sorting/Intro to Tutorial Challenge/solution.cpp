#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string input);

int introTutorial(int V, vector<int> arr) {
    if((arr[arr.size()-1] - V) < (V - arr[0])){
        for(size_t i=arr.size()-1;i>=0;i--){
            if(arr[i] == V)
                return i;
        }
    }else{
        for(size_t i=0;i<arr.size();i++){
            if(arr[i] == V)
                return i;
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string V_temp;
    getline(cin, V_temp);
    int V = stoi(V_temp);

    string n_temp;
    getline(cin, n_temp);
    int n = stoi(n_temp);

    string arr_temp;
    getline(cin, arr_temp);

    vector<int> arr = split(arr_temp);

    int result = introTutorial(V, arr);

    fout << result << "\n";
    fout.close();

    return 0;
}

vector<int> split(string str){
    vector<int> vec;
    for(size_t i=0;i<str.size();i++){
        string num;
        while(str[i]!=' ' && i<str.size())
            num.push_back(str[i++]);
        vec.push_back(stoi(num));
    }
    return vec;
}