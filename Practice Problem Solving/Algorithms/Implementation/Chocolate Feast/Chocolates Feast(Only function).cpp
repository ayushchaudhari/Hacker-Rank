//Problem @ https://www.hackerrank.com/challenges/chocolate-feast/problem
//A CPP Function by Ayush Chaudhari
//Logic Explained @ https://git.io/JUp9b


//Chocolate Feast Function
int chocolateFeast(int n, int c, int m) {
    int chocolate=n/c,wrappers=n/c;      //initially in first time we buy chocolate as per the amount(n) we have and that much only wrappers we would have
    while(wrappers>=m){
        int chocolate_ex_wrappers=wrappers/m;   //each time chocolate you can buy by exchanging wrappers
        chocolate+=chocolate_ex_wrappers;  //increase in chocolate with no. of chocolates buyed from the wrappers
        //wrappers=wrappers-chocolate_ex_wrappers*m+chocolate_ex_wrappers;    //each time decreasing wrappers by calculating cost of all chocolate buyed @ m price and increasing it by the number of chocolate buyed
        wrappers+=(chocolate_ex_wrappers*(1-m)); //same above formula
    }

    return chocolate;//At last return total chocolate you have buyed after feast ends 
}