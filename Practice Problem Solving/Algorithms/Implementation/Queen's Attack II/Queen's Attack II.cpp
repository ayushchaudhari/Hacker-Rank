//Problem @ https://www.hackerrank.com/challenges/queens-attack-2/problem
//A CPP Solution by Ayush Chaudhari
//Time Complexity=O(k)
//Logic Explained @ https://git.io/JU7SJ

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
/*Equation to count how many squares a queen can attack from a given position on (nxn)size chess board without any obstacle*/
int totalSquaresForAttack=(n-r_q)+(r_q-1)+(c_q-1)+(n-c_q)+min((n-r_q),(c_q-1))+min((r_q-1),(c_q-1))+min((n-r_q),(n-c_q))+min((r_q-1),(n-c_q));


vector<vector<int>> reframed_obstacles(8,{0,0});	//this vector saves the coordinate of closest obstacle in 8 directions 
vector<int> distance_of_closest_obstacle(8,1000000);	//this just saves the distance of the closest obstacle from queen


/*8 directions where a queen can attack and where the obstacle can be placed to save the attack of queen*/
//right@0     //left@1      //up@2      //down@3   //north-east@4    //south-east@5    //south-west@6     //north-west@7


for(size_t i=0;i<k;i++){

    if(abs(r_q-obstacles[i][0])==abs(c_q-obstacles[i][1])){
        if(r_q-obstacles[i][0]>0 && c_q-obstacles[i][1]>0){  //south-west direction
            int distance_from_queen=abs(r_q-obstacles[i][0]);
            
            if(distance_from_queen<distance_of_closest_obstacle[6]){
                distance_of_closest_obstacle[6]=distance_from_queen;
                reframed_obstacles[6]={obstacles[i][0],obstacles[i][1]};
            }
        }else{
                if(r_q-obstacles[i][0]>0 && c_q-obstacles[i][1]<0){ //south-east direction
                    int distance_from_queen=abs(r_q-obstacles[i][0]);
                    
                    if(distance_from_queen<distance_of_closest_obstacle[5]){
                        distance_of_closest_obstacle[5]=distance_from_queen;
                        reframed_obstacles[5]={obstacles[i][0],obstacles[i][1]};
                    }
                }else{
                    if(r_q-obstacles[i][0]<0 && c_q-obstacles[i][1]<0){  //north-east direction
                        int distance_from_queen=abs(r_q-obstacles[i][0]);

                        if(distance_from_queen<distance_of_closest_obstacle[4]){
                            distance_of_closest_obstacle[4]=distance_from_queen;
                            reframed_obstacles[4]={obstacles[i][0],obstacles[i][1]};
                        }
                    }else{
                        if(r_q-obstacles[i][0]<0 && c_q-obstacles[i][1]>0){   //north-west direction
                            int distance_from_queen=abs(r_q-obstacles[i][0]);

                            if(distance_from_queen<distance_of_closest_obstacle[7]){
                                distance_of_closest_obstacle[7]=distance_from_queen;
                                reframed_obstacles[7]={obstacles[i][0],obstacles[i][1]};
                            }
                        }
                    }
                }
            }
    }else{
        if(r_q==obstacles[i][0]){   //obstacle is in queen's row
            if(c_q<obstacles[i][1]){    //obstacle is right side
                int distance_from_queen=abs(c_q-obstacles[i][1]);

                if(distance_from_queen<distance_of_closest_obstacle[0]){
                    distance_of_closest_obstacle[0]=distance_from_queen;
                    reframed_obstacles[0]={obstacles[i][0],obstacles[i][1]};
                }
            }else{
                if(c_q>obstacles[i][1]){   //obstacle is left side
                    int distance_from_queen=abs(c_q-obstacles[i][1]);

                    if(distance_from_queen<distance_of_closest_obstacle[1]){
                        distance_of_closest_obstacle[1]=distance_from_queen;
                        reframed_obstacles[1]={obstacles[i][0],obstacles[i][1]};
                    }
                }
            }
        }else{
            if(c_q==obstacles[i][1]){   //obstacle is in queen's column
                if(r_q<obstacles[i][0]){    //obstacle is up side
                    int distance_from_queen=abs(r_q-obstacles[i][0]);

                    if(distance_from_queen<distance_of_closest_obstacle[2]){
                        distance_of_closest_obstacle[2]=distance_from_queen;
                        reframed_obstacles[2]={obstacles[i][0],obstacles[i][1]};
                    }
                }else{
                    if(r_q>obstacles[i][0]){    //obstacle is down side
                        int distance_from_queen=abs(r_q-obstacles[i][0]);

                        if(distance_from_queen<distance_of_closest_obstacle[3]){
                            distance_of_closest_obstacle[3]=distance_from_queen;
                            reframed_obstacles[3]={obstacles[i][0],obstacles[i][1]};
                        }
                    }
                }        
            }
        }
    }
}



for(size_t i=0;i<8;i++){
   if(distance_of_closest_obstacle[i]!=1000000){  // or this condition (reframed_obstacles[i][0]!=0 && reframed_obstacles[i][0]!=0)
      switch(i){
        case 0:totalSquaresForAttack-=((n-c_q)-abs(c_q-reframed_obstacles[i][1])+1);//obstacle in right direction
                continue;

        case 1:totalSquaresForAttack-=((c_q-1)-abs(c_q-reframed_obstacles[i][1])+1);//obtacle in left direction
                continue;

        case 2:totalSquaresForAttack-=((n-r_q)-abs(r_q-reframed_obstacles[i][0])+1);//obstacle is up/above
                continue;

        case 3:totalSquaresForAttack-=((r_q-1)-abs(r_q-reframed_obstacles[i][0])+1);//obstacle is down/below
                continue;

        case 4:totalSquaresForAttack-=(min((n-r_q),(n-c_q))-abs(r_q-reframed_obstacles[i][0])+1); //obstacle in north-east direction
                continue;

        case 5:totalSquaresForAttack-=(min((r_q-1),(n-c_q))-abs(r_q-reframed_obstacles[i][0])+1); //obstacle in south-east direction
                continue;

        case 6:totalSquaresForAttack-=(min((r_q-1),(c_q-1))-abs(r_q-reframed_obstacles[i][0])+1); //obstacle in south-west direction
                continue;

        case 7:totalSquaresForAttack-=(min((n-r_q),(c_q-1))-abs(r_q-reframed_obstacles[i][0])+1); //obstacle in north-west direction
                continue;
        }
    }
}

return totalSquaresForAttack;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
