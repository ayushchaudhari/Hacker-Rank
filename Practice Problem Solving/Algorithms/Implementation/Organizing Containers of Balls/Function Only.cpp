//Problem @ https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
//A C++ Function for the above problem by Ayush Chaudhari
//Time Complexity=O(q*(n^2)) or for 1 query O(n^2)
//Logic Explain @ https://git.io/JUrw7


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
//Sorting is done for some specific cases which get wrong if you not do this.Explained in logic.txt
sort(containers_capacity.begin(),containers_capacity.end());
sort(balls_of_a_type.begin(),balls_of_a_type.end());

if(containers_capacity==balls_of_a_type)
    return "Possible";
else
    return "Impossible";

}