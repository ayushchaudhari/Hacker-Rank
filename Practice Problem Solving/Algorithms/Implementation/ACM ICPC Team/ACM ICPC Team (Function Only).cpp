//Problem @ https://www.hackerrank.com/challenges/acm-icpc-team/problem
//A C++ Function for given problem by Ayush Chaudhari
//Time Complexity=O((n^2)*m) or ((n)*(n-1)*m)
//Logic Explained @ https://git.io/JUMrx


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