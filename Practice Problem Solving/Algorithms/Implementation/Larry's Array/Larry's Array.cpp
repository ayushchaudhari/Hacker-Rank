//Problem @ https://www.hackerrank.com/challenges/larrys-array/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JTXM1


#include <bits/stdc++.h>

using namespace std;

vector<int> delete_space(string input_string,int n);

string larrysArray(vector<int> A) {
    int total_num_of_inversions=0;
    for(size_t i=0;i<A.size();i++){     //this is to find the total number of inversions
        for(size_t j=i+1;j<A.size();j++){     //inversion are like if index i<j & a[i]>a[j] then it is 1 inversion
            if(A[i]>A[j])
                total_num_of_inversions++;
        }
    }
    if(total_num_of_inversions%2==0)    //if the total number of inversion is even then its possible to sort the array else not, for more see the logic.txt file(link is given above)
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<int> A= delete_space(A_temp_temp,n);

        string result = larrysArray(A);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<int> delete_space(string input_string,int n) {
    vector<int> larry_arr(n);
    for(size_t i=0,j=0;i<input_string.size(),j<n;i++,j++){
        string s;
        while(input_string[i]!=' ' && i<input_string.size()){
            s.push_back(input_string[i]);
            i++;
        }
        
        larry_arr.push_back(stoi(s));
    }

    return larry_arr;
}