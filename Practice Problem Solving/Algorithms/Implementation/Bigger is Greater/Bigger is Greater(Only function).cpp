//Problem @ https://www.hackerrank.com/challenges/bigger-is-greater/problem
//A CPP Function by Ayush Chaudhari
//Logic Explained @ https://git.io/JUdYh


//Bigger is Greater Function
string biggerIsGreater(string w) {
    
    string w_clone=w;
    sort(w_clone.begin(),w_clone.end(),greater<char>());
    if(w==w_clone){
        return "no answer";
    }
    else{
        size_t i=0;

        for(size_t i=w.size()-2;i>=0;i--){
            for(size_t j=w.size()-1;j>i;j--){
                if(w[i]<w[j]){
                   
                    string w_clone;
                    for(size_t x=0;x<i;x++){
                        w_clone.push_back(w[x]);
                    }
                    vector<int> minimum={0,30};
                    for(size_t x=i+1;x<=j;x++){
                        int diff=w[x]-w[i];
                        if(diff>0){
                            if(min(minimum[1],diff)!=minimum[1]){
                                minimum[1]=diff;
                                minimum[0]=j;
                            }
                        }
                    }
                    if(minimum[1]!=30){
                        string second_part;
                        for(size_t j=i;j<w.size();j++)
                            if((int)j!=minimum[0])
                                second_part.push_back(w[j]);
                        sort(second_part.begin(),second_part.end());
                        w_clone=w_clone+w[minimum[0]];
                        w_clone=w_clone+second_part;
                        return w_clone;
                    }else{
                        continue;
                    }   
                }
            }
        }
    }
}