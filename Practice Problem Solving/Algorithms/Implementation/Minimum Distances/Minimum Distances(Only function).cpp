//Problem @ https://www.hackerrank.com/challenges/minimum-distances/problem
//A CPP Function by Ayush Chaudhari
//Logic Explained @ https://git.io/JUNMm


//Minimum Distances Function
int minimumDistances(vector<int> a) {
    int minimum=a.size();   //as no distance in a will be greater than or equal to minimum
    map<int,int> count_of_elements;//map to keep the frequency of the elemnents in a whose freq>=2
    /*checking that how many element in vector a have 
    frequency greter than or equal to 2 so that we can make
    there pair*/
    for(size_t i=0;i<a.size();i++){
        if(count_of_elements.find(a[i])==count_of_elements.end()){
            int cnt=count(a.begin(),a.end(),a[i]);
            if(cnt>=2)
                count_of_elements.insert(pair<int,int>(a[i],cnt));
        }
    }
    vector<int>::iterator vec_itr1,vec_itr2;//2 iterator pointing to elements in vector a
    map<int,int>::iterator itr;//iterator used to iterate map

    if(count_of_elements.empty())   //checking is map is empty means no pair exists in vector a
        return -1;
    else{   //executes if map is not empty
        //for loop iterator the map fully
        for(itr=count_of_elements.begin();itr!=count_of_elements.end();itr++){
            int times=ceil((itr->second)/2);//this is no. of times we have to search for that element like for x coming 3 times in a it should be search 2 times like for x1 to x2 & then x2 to x3        
            vec_itr2=a.begin();
            
            for(int i=0;i<times;i++){
                vec_itr1=find(vec_itr2,a.end(),(itr->first));//pointing to first location at which itr->first the element with count>=2 is found
                vec_itr2=find(vec_itr1+1,a.end(),(itr->first));//pointing to the second location in a for a element

                minimum=min((int)(vec_itr2-vec_itr1),minimum);//keeps track of the minimum distance
            }
        }
        return minimum;
    }
}