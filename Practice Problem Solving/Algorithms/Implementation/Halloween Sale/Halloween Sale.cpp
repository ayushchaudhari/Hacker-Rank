//Problem @ https://www.hackerrank.com/challenges/halloween-sale/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity=O(n)
//Logic Explained @ https://git.io/JUA7l


#include <bits/stdc++.h>

using namespace std;

vector<string> delete_space(string pdms_temp);


int howManyGames(int p, int d, int m, int s) {
    int games=0,total_cost=0,current_game_cost=p;
    
    while((total_cost+current_game_cost)<=s){
        if((current_game_cost)>=m){
            games++;
            total_cost+=current_game_cost;
            current_game_cost-=d;
        }else{
            current_game_cost=m;
            games+=floor((s-total_cost)/current_game_cost);
            total_cost+=(floor((s-total_cost)/current_game_cost))*m;
            break;
        }
    }
    return games;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pdms_temp;
    getline(cin, pdms_temp);

    vector<string> pdms = delete_space(pdms_temp);

    int p = stoi(pdms[0]);

    int d = stoi(pdms[1]);
    
    int m = stoi(pdms[2]);

    int s = stoi(pdms[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> delete_space(string pdms_temp){
    vector<string> pdms;

    for(size_t i=0,j=0;i<4;i++){
        string s;
        while(pdms_temp[j]!=' ' && j<pdms_temp.size()){
            s.push_back(pdms_temp[j]);
            j++;
        }
        j++;
        pdms.push_back(s);
    }
    return pdms;
}