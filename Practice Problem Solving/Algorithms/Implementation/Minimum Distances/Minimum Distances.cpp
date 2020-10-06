//Problem @ https://www.hackerrank.com/challenges/minimum-distances/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JUNMm


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int minimumDistances(vector<int> a) {
    int minimum=a.size();
    map<int,int> count_of_elements;
    /*checking that how many element in vector a have 
    frequency greter than or equal to 2 so that we can make
    there pair*/
    for(size_t i=0;i<a.size();i++){
        if(count_of_elements.find(a[i])==count_of_elements.end()){
            int cnt=count(a.begin(),a.end(),a[i]);
            if(cnt>=2)
                count_of_elements.insert(pair<int,int>(a[i],cnt));
        }
    }
    vector<int>::iterator vec_itr1,vec_itr2;//2 iterator pointing to elements in vector a
    map<int,int>::iterator itr;//iterator used to iterate map

    if(count_of_elements.empty())   //checking is map is empty means no pair exists in vector a
        return -1;
    else{   //executes if map is not empty
        //for loop iterator the map fully
        for(itr=count_of_elements.begin();itr!=count_of_elements.end();itr++){
            int times=ceil((itr->second)/2);//this is no. of times we have to search for that element like for x coming 3 times in a it should be search 2 times like for x1 to x2 & then x2 to x3        
            vec_itr2=a.begin();
            
            for(int i=0;i<times;i++){
                vec_itr1=find(vec_itr2,a.end(),(itr->first));//pointing to first location at which itr->first the element with count>=2 is found
                vec_itr2=find(vec_itr1+1,a.end(),(itr->first));//pointing to the second location in a for a element

                minimum=min((int)(vec_itr2-vec_itr1),minimum);//keeps track of the minimum distance
            }
        }
        return minimum;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}