//Problem @ https://www.hackerrank.com/challenges/service-lane/problem
//A CPP Function by Ayush Chaudhari
//Logic Explained @ https://git.io/JUhkK


// Service Lane Function
vector<int> serviceLane(int n, vector<int> width, vector<vector<int>> cases) {
    vector<int>  largest_vehicle_through(cases.size(),4);
    for(size_t i=0;i<cases.size();i++){
        for(size_t j=cases[i][0];j<=cases[i][1];j++){
            largest_vehicle_through[i]=min(largest_vehicle_through[i],width[j]);
        }
    }

    return largest_vehicle_through;
}