//Problem @ https://www.hackerrank.com/challenges/chocolate-feast/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JUp9b


#include <bits/stdc++.h>

using namespace std;

vector<string> delete_space(string pdms_temp);

int chocolateFeast(int n, int c, int m) {
    int chocolate=n/c,wrappers=n/c;      //initially in first time we buy chocolate as per the amount(n) we have and that much only wrappers we would have
    while(wrappers>=m){
        int chocolate_ex_wrappers=wrappers/m;   //each time chocolate you can buy by exchanging wrappers
        chocolate+=chocolate_ex_wrappers;  //increase in chocolate with no. of chocolates buyed from the wrappers
        //wrappers=wrappers-chocolate_ex_wrappers*m+chocolate_ex_wrappers;    //each time decreasing wrappers by calculating cost of all chocolate buyed @ m price and increasing it by the number of chocolate buyed
        wrappers+=(chocolate_ex_wrappers*(1-m)); //same above formula in short
    }

    return chocolate;//At last return total chocolate you have buyed after feast ends 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string ncm_temp;
        getline(cin, ncm_temp);

        vector<string> ncm = delete_space(ncm_temp);

        int n = stoi(ncm[0]);

        int c = stoi(ncm[1]);

        int m = stoi(ncm[2]);

        int result = chocolateFeast(n, c, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}


vector<string> delete_space(string ncm_temp){
    vector<string> ncm;

    for(size_t i=0,j=0;i<4;i++){
        string s;
        while(ncm_temp[j]!=' ' && j<ncm_temp.size()){
            s.push_back(ncm_temp[j]);
            j++;
        }
        j++;
        ncm.push_back(s);
    }
    return ncm;
}