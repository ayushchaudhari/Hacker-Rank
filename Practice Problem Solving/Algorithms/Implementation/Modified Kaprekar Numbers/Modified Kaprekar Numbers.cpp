//Problem @ https://www.hackerrank.com/challenges/kaprekar-numbers/problem
//A C++ code by Ayush Chaudhari
//Time Complexity=O(q-p+1) or for n numbers it is O(n)
//Logic Explained @ https://git.io/JUM2A

#include <bits/stdc++.h>

using namespace std;


void kaprekarNumbers(int p, int q) {
    int state=0;
    for(int i=p;i<=q;i++){
        unsigned long isquare=pow(i,2);

        //calculate digits of number(p to q) one at a time as loop is for 1 num ata time
        int digits=floor(log10(i))+1;

//calc. number's square's right and left part where right part length=digits of number
        unsigned int right=isquare%(int)(pow(10,digits));
        unsigned int left=isquare/(pow(10,digits));

        //condition to check if number's square's right and left part sum to i or not
        if(right!=0 && right+left==i){
            cout<<i<<" ";
            state=1;
        }
    }
    //If state is not changed from 0 to 1 means no number i.e. p to q
    if(state==0)
        cout<<"INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
