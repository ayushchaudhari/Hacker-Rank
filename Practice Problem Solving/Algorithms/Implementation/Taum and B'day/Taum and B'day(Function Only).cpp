//Problem @ https://www.hackerrank.com/challenges/taum-and-bday/problem
//A C++ Function for the above problem by Ayush Chaudhari
//Function Time Complexity=O(1)
//Logic Explained @ https://git.io/JUM6v


long taumBday(long b, long w, long bc, long wc, long z) {
    return ((b*min(bc,wc+z))+(w*min(wc,bc+z)));
}
