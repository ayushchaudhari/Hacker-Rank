//Problem @ https://www.hackerrank.com/challenges/beautiful-triplets/problem
//A CPP Function by Ayush Chaudhari
//Time Complexity=O((n-1)*(n-2)*(n-3)) or O(n^3) where n is the length/size of sequene/vector
//Logic Explained @https://git.io/JU75I


//Beutiful Triplets Function
int beautifulTriplets(int d, vector<int> arr) {
    int count=0;
    for(size_t i=0;i<(arr.size()-1);i++){
        for(size_t j=i+1;j<arr.size();j++){
            if((arr[j]-arr[i])==d){
                for(size_t k=j+1;k<arr.size();k++){
                    if((arr[k]-arr[j])==d)
                        count++;
                }
            }
        }
    }
    
    return count;
}