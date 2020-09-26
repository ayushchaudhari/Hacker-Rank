//Problem @ https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
//A C++ Solution by Ayush Chaudhari
//Time Complexity=O(q*(n^2)) or for 1 query O(n^2)
//Logic Explain @ https://git.io/JUrw7

#include <bits/stdc++.h>

using namespace std;

string organizingContainers(vector<vector<int>> container) {
vector<int> containers_capacity,balls_of_a_type;

for(size_t i=0;i<container.size();i++){
    int sum_row=0;
    int sum_coloumn=0;
    for(size_t j=0;j<container.size();j++){
        sum_row+=container[i][j];
        sum_coloumn+=container[j][i];
    }
    containers_capacity.push_back(sum_row);
    balls_of_a_type.push_back(sum_coloumn);
}
/*Just comparing like given below OR sorting the vector and comparing them will also work*//*
for(size_t i=0;i<containers_capacity.size();i++){
    auto itr=find(balls_of_a_type.begin(),balls_of_a_type.end(),containers_capacity[i]);
    if(itr!=balls_of_a_type.end())
        continue;
    else 
        return "Impossible";
}

return "Possible";
*/
sort(containers_capacity.begin(),containers_capacity.end());
sort(balls_of_a_type.begin(),balls_of_a_type.end());

if(containers_capacity==balls_of_a_type)
	return "Possible";
else
	return "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
