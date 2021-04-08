#include <bits/stdc++.h>

using namespace std;

string compresser(string word){
    int len=word.length();
    if(len>5){
        // string between_letter_length=to_string(len-2);
        // return word[0]+between_letter_length+word[len-1];
        return word[0]+to_string(len-2)+word[len-1];
    }
    else
        return word;
}

int main() {
    string word;
    getline(cin,word);
    string compressed_word=compresser(word);
    cout<<compressed_word;
    return 0;
}