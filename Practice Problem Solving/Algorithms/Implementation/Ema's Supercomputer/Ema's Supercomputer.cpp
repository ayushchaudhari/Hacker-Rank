//Problem @ https://www.hackerrank.com/challenges/two-pluses/problem
//A CPP Solution by Ayush Chaudhari


#include <bits/stdc++.h>

using namespace std;

vector<int> delete_space(string);

//this is the function to find the maximum length for the 2nd possible plus
int findNextMax(vector<string> grid,vector<vector<size_t>> indexes_of_first_plus,int size){

    int max_len2=0;
    
    for(size_t row=1;row<grid.size()-1;row++){
        for(size_t col=1;col<grid[row].size()-1;col++){
            if(grid[row][col]=='G' && row!=indexes_of_first_plus[0][0] && col!=indexes_of_first_plus[0][1]){
                
                bool status=true;

                int temp1=min(col,((grid[row].size()-1)-col));//this for a index max square len possible, so this is for up and down
                int temp2=min(row,(grid.size()-1)-row);//this is for left and right of the centre index
                temp1=min(temp1,temp2); //now this maximum length of the square possible after observing all four direction

                int len=0;                
                
                for(int i=1;i<=temp1;i++){
                    if(grid[row][col+i]=='G' && grid[row][col-i]=='G' && grid[row+i][col]=='G' && grid[row-i][col]=='G' && status==true){
                            len++;
                            // if(i==1){
                            //     cout<<"max2 series->   ";
                            //     cout<<"("<<row<<","<<col<<")";
                            // }
                            // cout<<"  ("<<row<<","<<col+i<<")";
                            // cout<<"  ("<<row<<","<<col-i<<")";
                            // cout<<"  ("<<row+i<<","<<col<<")";
                            // cout<<"  ("<<row-i<<","<<col<<")";

                            for(int j=0;j<size;j++){  //this loop acts as check for intersection between two pluses and also this check is done for each index of 2nd plus at a time is checked with every index of first plus
                                if(row==indexes_of_first_plus[j][0] && (col+i==indexes_of_first_plus[j][1] || col-i==indexes_of_first_plus[j][1] )){
                                    len--;  //this is done as we are adding len before checking the intersection with the first plus so after checking it itersects then we do len--
                                    status=false;
                                    break;
                                }
                                
                                if((row+i==indexes_of_first_plus[j][0] || row-i==indexes_of_first_plus[j][0]) && col==indexes_of_first_plus[j][1]){
                                    len--;
                                    status=false;
                                    break;
                                }
                            }
                    }else{
                        break;
                    }
                }

                if(max_len2<len)
                    max_len2=len;
            }
        }
    }
    // cout<<"("<<index[0]<<","<<index[1]<<")   ";
    return max_len2;  
}


int twoPluses(vector<string> grid) {
    int max_product=0;
    for(size_t row=1;row<grid.size()-1;row++){
        for(size_t col=1;col<grid[row].size()-1;col++){
            if(grid[row][col]=='G'){
                vector<vector<size_t>> indexes_of_first_plus; //this contains the indexes of each sqaure of first plus so that we can check for the no intersection between this and the second plus

                indexes_of_first_plus.push_back({row,col}); //row and col passed initially if @grid(row,col)=='G'

                // cout<<"("<<row<<","<<col<<")";
                int temp1=min(col,((grid[row].size()-1)-col));
                int temp2=min(row,(grid.size()-1)-row);
                
                int len=0;
                
                temp1=min(temp1,temp2);
                
                for(int i=1;i<=temp1;i++){
                    if(grid[row][col+i]=='G' && grid[row][col-i]=='G' && grid[row+i][col]=='G' && grid[row-i][col]=='G'){
                            len++;
                            indexes_of_first_plus.push_back({row,col+i});
                            indexes_of_first_plus.push_back({row,col-i});
                            indexes_of_first_plus.push_back({row+i,col});
                            indexes_of_first_plus.push_back({row-i,col});
                    }else
                        break;
                }
                // cout<<endl<<"max1 series->";
                // for(size_t row=0;row<indexes_of_first_square.size();row++){
                //     cout<<"("<<indexes_of_first_square[row][0]<<","<<indexes_of_first_square[row][1]<<")  ";
                // }
                // cout<<endl;

                //////////////////////////

                int max_len1=len;
                //this loop is for like if a plus is found of max length 3 but if we only find the 2nd plus w.r.t length 3 then we would get length 1 as I got in one of the test case and therefore the product become ((3*4)+1)+((1*5)+1)=65 but also the same plus can be of length 2,1 and 0(0 means only the centre index)     //and for 1st plus length 2 I got 2nd plus with max length 2 and final product was 81 which is >65 so it should be considered   //therefore I did this to find the 2nd plus for all length plus possible under 1st plus as my code tends to find the max length plus therfore I have to do this  
                for(int i=0;i<=max_len1;i++){                
                    int size_of_square_passed_temporarily=1+(i*4);
                    int max_len2=findNextMax(grid,indexes_of_first_plus,size_of_square_passed_temporarily);

                    // cout<<endl<<"maxlen1="<<i<<"   "<<"max_len2="<<max_len2<<endl;
                    // max_len1=(max_len1*4)+1;
                    // max_len2=(max_len2*4)+1;
                    max_product=max(max_product,((i*4)+1)*((max_len2*4)+1));
                }       
                ///////////////////////////
            }
        }
    }

    return max_product;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<int> nm = delete_space(nm_temp);

    int n = nm[0];

    int m = nm[1];

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<int> delete_space(string input_string) {
    vector<int> nm;

    for(size_t i=0;i<input_string.size();i++){
        string s;
        while(input_string[i]!=' ' && i<input_string.size()){
            s.push_back(input_string[i++]);
        }
        nm.push_back(stoi(s));
    }

    return nm;
}