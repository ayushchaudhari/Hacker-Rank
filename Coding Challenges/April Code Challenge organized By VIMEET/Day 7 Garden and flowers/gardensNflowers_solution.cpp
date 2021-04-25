/*Solution By Ayush Chaudhari*/
/*Solution For Problem Gardens & Flowers*/

#include<bits/stdc++.h>

using namespace std;

vector<int> vectorize_string(string str){
    vector<int> vec;
    for(size_t i=0;i<str.size();i++){
        string temp;
        while(str[i]!=' ' && i<str.size()){
            temp.push_back(str[i]);
            i++;
        }
        // cout<<stoi(temp)<<"\t";
        vec.push_back(stoi(temp));
    }
    //cout<<endl;
    return vec;
}

int maximum(vector<int> arr){
    int max_num=0;
    int add=0;
    for(size_t i=0;i<arr.size();i++){
        add+=arr[i];
        max_num=max(max_num,add);
        //Testing Purpose
        // cout<<endl<<"Iteration "<<i<<endl;
        // cout<<"Add:"<<add<<endl;
        // cout<<"Max:"<<max_num<<endl;
    }
    return max_num;
}

int main() {
    string test_cases;
    getline(cin,test_cases);
    int tc=stoi(test_cases);
    vector<vector<string>> strings(tc);
    vector<vector<int>> lengths(tc);
    for(int t=0;t<tc;t++){
        string str1,str2,str3,str4;
        getline(cin,str1);
        // cout<<str1;
        getline(cin,str2);
        // cout<<str2;
        getline(cin,str3);
        // cout<<str3;
        getline(cin,str4);
        // cout<<str4;
        lengths[t].push_back(stoi(str1));
        strings[t].push_back(str2);
        lengths[t].push_back(stoi(str3));
        strings[t].push_back(str4);
    }
        
        // string arr_one_len,arr_two_len,str1,str2;
        // getline(cin,arr_one_len);
        // getline(cin,str1);
        // getline(cin,arr_two_len);
        // getline(cin,str2);
    for(int t=0;t<tc;t++){    
        vector<int> x=vectorize_string(strings[t][0]);
        vector<int> y=vectorize_string(strings[t][1]);
        
        // Testing Purpose
        // for(int i=0;i<stoi(arr_one_len);i++)
        //     cout<<x[i]<<"\t";
        // cout<<endl;
        // for(int i=0;i<stoi(arr_two_len);i++){
        //   cout<<y[i]<<"\t";
        // }
        // cout<<endl;
        // testing block ends
        
        // cout<<maximum(x)<<endl;
        // cout<<maximum(y)<<endl;
        cout<<maximum(x)+maximum(y)<<endl;
        
    }
    return 0;
}