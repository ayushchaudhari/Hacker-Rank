//Problem @ https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
//A CPP Solution by Ayush Chaudhari
//Logic Explained @ https://git.io/JnUG3


#include <bits/stdc++.h>

using namespace std;

vector<int> split(string str_temp); //for spliting the input string into the vector of int

void matrixRotation(vector<vector<int>> matrix,int m,int n, int r) {
    int total_layers = ceil(min(m,n)/2);
    vector<vector<int>> all_layers;

    //extracting layers logic and inputting in all_layers vector of lists
    for(int layer = 0; layer < total_layers; layer++){
        int row=layer,col=layer;
        vector<int> temp_layer;
    
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

    //By maintaing only the start element position we can optimise the solution more instead of rotating it manually so I just calculated the real rotation value and changed the start_pos of the layer
    for(int layer = 0; layer < total_layers; layer++){
        int real_r = r % all_layers[layer].size();
        int row=layer,col=layer,pos = real_r;
    
        for(col=layer;col<n-1-layer;col++){
            matrix[row][col] = all_layers[layer][pos];
            if(pos == all_layers[layer].size()-1)
                pos=0;
            else pos++;
        }
    
        for(row=layer;row<m-1-layer;row++){
            matrix[row][col] = all_layers[layer][pos];
            if(pos == all_layers[layer].size()-1)
                pos=0;
            else pos++;
        }

        for(col=(n-1)-layer;col>layer;col--){
            matrix[row][col] = all_layers[layer][pos];
            if(pos == all_layers[layer].size()-1)
                pos=0;
            else pos++;
        }
        
        for(row=(m-1)-layer;row>layer,pos!=real_r;row--){
            matrix[row][col] = all_layers[layer][pos];
            if(pos == all_layers[layer].size()-1)
                pos=0;
            else pos++;
        }
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