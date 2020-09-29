//Problem @ https://www.hackerrank.com/challenges/acm-icpc-team/problem
//A C++ Solution by Ayush Chaudhari
//Time Complexity=O((n^2)*m) or ((n)*(n-1)*m)
//Logic Explained @ https://git.io/JUMrx

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//function acmTeam
vector<int> acmTeam(vector<string> topic,int num_of_topics) {
    vector<int> result(2,0);
    
    vector<int> counter;

    for(size_t i=0;i<topic.size()-1;i++){          //topic.size() is count of total attendees 
        for(size_t j=i+1;j<topic.size();j++ ){
            int count_of_one=0;
            for(int z=0;z<num_of_topics;z++){      //num_of_topics is count of topics
                if(topic[i][z]=='1' || topic[j][z]=='1')
                    count_of_one++;             
            }
            counter.push_back(count_of_one);
            result[0]=max(result[0],count_of_one);
        }
    }

    result[1]=count(counter.begin(),counter.end(),result[0]);
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic,m);

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
