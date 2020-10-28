//Problem @ https://www.hackerrank.com/challenges/lisa-workbook/problem
//A CPP Function by Ayush Chaudhari
//Logic Explained @ https://git.io/JT1zi


// Lisa's Workbook Function
int workbook(int n, int k, vector<int> arr) {
    int special_problem=0;
    int ongoing_page=1;
    for(size_t chapter=1;chapter<=n;chapter++){
        int ongoing_problem=1;
        int pages_required_by_chap=ceil((float)arr[chapter-1]/(float)k);
        int check_till_page=ongoing_page+pages_required_by_chap-1;
       
        while(ongoing_page<=check_till_page){
            if((arr[chapter-1]-ongoing_problem+1)>=k){
                if((ongoing_page>=ongoing_problem) && (ongoing_page<=(ongoing_problem+(k-1)))){
                    special_problem++;
                }
            }else{
                if((ongoing_page>=ongoing_problem) && (ongoing_page<=arr[chapter-1])){
                    special_problem++;
                }
            }

            ongoing_problem+=k;
            ongoing_page++;
            
        }
    }
    
    return special_problem;
}