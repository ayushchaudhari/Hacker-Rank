//Problem @ https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JnUG3


#include <bits/stdc++.h>

using namespace std;

vector<int> split(string str_temp); //for spliting the input string into the vector of int

void matrixRotation(vector<vector<int>> matrix,int m,int n, int r) {
    int total_layers = ceil(min(m,n)/2);
    vector<list<int>> all_layers;

    //extracting layers logic and inputting in all_layers vector of lists
    for(int layer = 0; layer < total_layers; layer++){
        int row=layer,col=layer;
        list<int> temp_layer;
    
        for(col=layer;col<n-1-layer;col++)
            temp_layer.push_back(matrix[row][col]);
    
        for(row=layer;row<m-1-layer;row++)
            temp_layer.push_back(matrix[row][col]);

        for(col=(n-1)-layer;col>layer;col--)
            temp_layer.push_back(matrix[row][col]);
        
        for(row=(m-1)-layer;row>layer;row--)
            temp_layer.push_back(matrix[row][col]);
    
        all_layers.push_back(temp_layer);
    }
    
    //to show the raw list of layers
    // for(int i =0; i<all_layers.size();i++){
    //     for(auto it=all_layers[i].begin();it!=all_layers[i].end();it++)
    //         cout<<*it<<" ";
    //     cout<<endl;
    // }
    
    
    //rotation logic(manually/actually rotation takes extra time)
    for(size_t i=0;i<all_layers.size();i++){
       int real_r = r % all_layers[i].size();
        for(size_t rotation=0;rotation<real_r;rotation++){
            all_layers[i].push_back(all_layers[i].front());
            all_layers[i].pop_front();
        }
    }
    
    //to show the list of layers after the rotations performed    
    // for(int i =0; i<all_layers.size();i++){
    //     for(auto it=all_layers[i].begin();it!=all_layers[i].end();it++)
    //         cout<<*it<<" ";
    //     cout<<endl;
    // }
    
    for(int layer = 0; layer < total_layers; layer++){
        auto cur = all_layers[layer].begin();
        int row=layer,col=layer;
    
        for(col=layer;col<n-1-layer;col++,cur++)
            matrix[row][col] = *cur;
    
        for(row=layer;row<m-1-layer;row++,cur++)
            matrix[row][col] = *cur;

        for(col=(n-1)-layer;col>layer;col--,cur++)
            matrix[row][col] = *cur;
        
        for(row=(m-1)-layer;row>layer;row--,cur++)
            matrix[row][col] = *cur;
    }
    
    for(auto row=0;row<matrix.size();row++){
        for(int col=0;col<matrix[row].size();col++)
            cout<<matrix[row][col]<<" ";
        cout<<endl;
    }
}

int main()
{
    string m_n_r_temp;
    getline(cin, m_n_r_temp);

    vector<int> m_n_r = split(m_n_r_temp);

    int m = m_n_r[0];
    int n = m_n_r[1];
    int r = m_n_r[2];

    vector<vector<int>> matrix;

    for (int i = 0; i < m; i++) {
        string matrix_row_temp;
        getline(cin, matrix_row_temp);
        // vector<int> matrix_row = split(matrix_row_temp);
        // matrix.push_back(matrix_row);
        matrix.push_back(split(matrix_row_temp));
    }

    matrixRotation(matrix,m,n,r);

    return 0;
}


vector<int> split(string str_temp) {
    vector<int> vec;
    
    for(size_t i=0; i<str_temp.size(); i++){
        string temp;
        
        while (str_temp[i]!=' ' && i<str_temp.size())
            temp.push_back(str_temp[i++]);

        vec.push_back(stoi(temp));
    }
    
    return vec;
}