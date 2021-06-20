//Problem @ https://www.hackerrank.com/challenges/two-characters
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JnrHF

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool chk_alternate(string str,vector<char> selection){
    cout<<str<<endl;
    int key=0;
    if(str[0]==selection[1]) key=1;
    
    for(size_t i=0; i<str.size(); i++){
        if(str[i]!=selection[key])
            return false;
        if(key==0) key=1;
        else if(key==1) key=0;
    }
    
    return true;
}

int alternate(int l, string s) {
    int max_strlen=0;
    set<char> unique_char;
    //find total unique character to get the selection combination
    for(size_t i=0;i<l;i++)
        unique_char.insert(s[i]);
        
    //selections contains the 2 selected char for making longest string
    //each selection has 2 unique characters which are selected
    vector<vector<char>> selections;
    for(auto it1=unique_char.begin(); it1!=unique_char.end(); it1++){
        auto it2=it1;
        it2++;
        for(; it2!=unique_char.end(); it2++){
            selections.push_back({*it1,*it2});
        }
    }

    //this forms the string on basis of selection from selections and find max length
    for(size_t pair=0;pair<selections.size();pair++){
        string long_str;
        for(size_t i=0;i<s.size();i++){
            if(s[i]==selections[pair][0] || s[i]==selections[pair][1])
                long_str.push_back(s[i]);
        }
        if(chk_alternate(long_str,selections[pair])==true)
            max_strlen=max(max_strlen,(int)long_str.size());
    }
    
    return max_strlen;
}
    
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);
    int l = stoi(l_temp);

    string s;
    getline(cin, s);
    int result = alternate(l,s);

    fout << result << "\n";
    fout.close();

    return 0;
}
