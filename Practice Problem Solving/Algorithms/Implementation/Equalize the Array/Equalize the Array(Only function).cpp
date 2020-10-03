//Problem @ https://www.hackerrank.com/challenges/equality-in-a-array/problem
//A CPP Function by Ayush Chaudhari
//Time Complexity=O(n) where n is number of elements in array or size of array
//Logic Explained @ https://git.io/JU7NX


// Equalize Array Function
int equalizeArray(vector<int> arr) {

    int maxCount=-1;     //store the count of the number that comes maximum time 
    vector<int> count_arr(arr.size());
    
    for(size_t i=0;i<arr.size();i++)
        count_arr.push_back(count(arr.begin(),arr.end(),arr[i])); 
    
    for(size_t i=0;i<count_arr.size();i++)
        maxCount=max(maxCount,count_arr[i]);

    return arr.size()-maxCount;

}