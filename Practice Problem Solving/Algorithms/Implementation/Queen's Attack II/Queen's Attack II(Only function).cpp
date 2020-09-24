//Problem @ https://www.hackerrank.com/challenges/queens-attack-2
//A CPP Function by Ayush Chaudhari
//Time Complexity=O(k)

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