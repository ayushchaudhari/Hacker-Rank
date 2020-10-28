//Problem @ https://www.hackerrank.com/challenges/larrys-array/problem
//A CPP Function by Ayush Chaudhari
//Logic Explained @ https://git.io/JTXM1


// Larry's Array Function
string larrysArray(vector<int> A) {
    int total_num_of_inversions=0;
    for(size_t i=0;i<A.size();i++){		//this is to find the total number of inversions					
        for(size_t j=i+1;j<A.size();j++){	//inversion are like if index i<j & a[i]>a[j] then it is 1 inversion
            if(A[i]>A[j])
                total_num_of_inversions++;
        }
    }
    if(total_num_of_inversions%2==0)
        return "YES";
    else
        return "NO";
}
