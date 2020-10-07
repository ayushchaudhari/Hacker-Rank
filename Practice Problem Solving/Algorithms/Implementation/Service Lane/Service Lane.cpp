//Problem @ https://www.hackerrank.com/challenges/service-lane/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JUhkK


#include <bits/stdc++.h>

using namespace std;

vector<string> delete_space(string s_temp);


vector<int> serviceLane(int n, vector<int> width, vector<vector<int>> cases) {
    vector<int>  largest_vehicle_through(cases.size(),4);
    for(size_t i=0;i<cases.size();i++){
        for(size_t j=cases[i][0];j<=cases[i][1];j++){
            largest_vehicle_through[i]=min(largest_vehicle_through[i],width[j]);
        }
    }

    return largest_vehicle_through;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nt_temp;
    getline(cin, nt_temp);

    vector<string> nt = delete_space(nt_temp);

    int n = stoi(nt[0]);

    int t = stoi(nt[1]);

    string width_temp_temp;
    getline(cin, width_temp_temp);

    vector<string> width_temp = delete_space(width_temp_temp);

    vector<int> width(n);

    for (int i = 0; i < n; i++) {
        int width_item = stoi(width_temp[i]);

        width[i] = width_item;
    }

    vector<vector<int>> cases(t);
    for (int i = 0; i < t; i++) {
        cases[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> cases[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = serviceLane(n, width, cases);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}


vector<string> delete_space(string s_temp){
    vector<string> s;

    for(size_t i=0;i<s_temp.size();i++){
        string temp;
        
        while(s_temp[i]!=' ' && i<s_temp.size()){   //this while is just used take the inputs which are more than one char such 28 it is 2 digit number so I copied it till we get' ''
            temp.push_back(s_temp[i]);
            i++;
        }

        s.push_back(temp);
    }
    
    return s;
}