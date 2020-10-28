//Problem @ https://www.hackerrank.com/challenges/lisa-workbook/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JT1zi


#include <bits/stdc++.h>

using namespace std;

vector<string> delete_space(string s_temp);


int workbook(int n, int k, vector<int> arr) {
    int special_problem=0;
    int ongoing_page=1;
    for(size_t chapter=1;chapter<=n;chapter++){
        int ongoing_problem=1;
        int pages_required_by_chap=ceil((float)arr[chapter-1]/(float)k);
        int check_till_page=ongoing_page+pages_required_by_chap-1;
       
        while(ongoing_page<=check_till_page){
            if((arr[chapter-1]-ongoing_problem+1)>=k){
                if((ongoing_page>=ongoing_problem) && (ongoing_page<=(ongoing_problem+(k-1)))){
                    special_problem++;
                }
            }else{
                if((ongoing_page>=ongoing_problem) && (ongoing_page<=arr[chapter-1])){
                    special_problem++;
                }
            }

            ongoing_problem+=k;
            ongoing_page++;
            
        }
    }
    
    return special_problem;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = delete_space(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = delete_space(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = workbook(n, k, arr);

    fout << result << "\n";

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