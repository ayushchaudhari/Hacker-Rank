//Problem @ https://www.hackerrank.com/challenges/the-time-in-words/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity=O(1)
//Logic Explained @ https://git.io/JUxJJ


#include <bits/stdc++.h>

using namespace std;


string timeInWords(int h, int m) {

    map<int,string> hour;
    hour.insert(pair<int,string>(1,"one"));
    hour.insert(pair<int,string>(2,"two"));
    hour.insert(pair<int,string>(3,"three"));
    hour.insert(pair<int,string>(4,"four"));
    hour.insert(pair<int,string>(5,"five"));
    hour.insert(pair<int,string>(6,"six"));
    hour.insert(pair<int,string>(7,"seven"));
    hour.insert(pair<int,string>(8,"eight"));
    hour.insert(pair<int,string>(9,"nine"));
    hour.insert(pair<int,string>(10,"ten"));
    hour.insert(pair<int,string>(11,"eleven"));
    hour.insert(pair<int,string>(12,"twelve"));

    map<int,string> minutes;
    minutes.insert(pair<int,string>(15,"quarter"));
    minutes.insert(pair<int,string>(30,"half"));
    minutes.insert(pair<int,string>(0,"o' clock"));

    map<int,string> minutes_added;
    minutes_added.insert(pair<int,string>(13,"thirteen"));
    minutes_added.insert(pair<int,string>(14,"fourteen"));
    minutes_added.insert(pair<int,string>(16,"sixteen"));
    minutes_added.insert(pair<int,string>(17,"seventeen"));
    minutes_added.insert(pair<int,string>(18,"eighteen"));
    minutes_added.insert(pair<int,string>(19,"nineteen"));
    minutes_added.insert(pair<int,string>(10,"ten"));
    minutes_added.insert(pair<int,string>(20,"twenty"));
    minutes_added.insert(pair<int,string>(40,"fourty"));
    minutes_added.insert(pair<int,string>(50,"fifty"));
    

    if(m<=30){
        if(minutes.find(m)!=minutes.end()){
            if(m==0)
                return hour[h]+" "+minutes[m];
            else
                return minutes[m]+" past "+hour[h];
        }else{
            if(m==1)
                return "one minute past "+hour[h];
            else{
                int first=((int)(m/10))*10;
                int last_digit=m%10;
                if(last_digit==0)
                    return minutes_added[first]+" minutes past "+hour[h];
                else
                    return minutes_added[first]+" "+hour[last_digit]+" minutes past "+hour[h];
            }
        }
    }else{
        m=60-m;
        h+=1;
        if(hour.find(m)!=hour.end())
            return hour[m]+" minutes to "+hour[h];
        else{
            if(minutes.find(m)!=minutes.end()){
                if(m==0)
                    return hour[h]+" "+minutes[m];
                else
                    return minutes[m]+" to "+hour[h];
            }else{
                if(minutes_added.find(m)!=minutes_added.end()){
                    return minutes_added[m]+" minutes to "+hour[h];
                }else{
                    if(m==1)
                        return "one minute to "+hour[h];
                    else{
                        int first=((int)(m/10))*10;
                        int last_digit=m%10;
                        return minutes_added[first]+" "+hour[last_digit]+" minutes to "+hour[h];
                    }
                }
            }
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}