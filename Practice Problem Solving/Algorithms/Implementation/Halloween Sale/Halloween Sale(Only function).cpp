//Problem @ https://www.hackerrank.com/challenges/halloween-sale/problem
//A CPP Function by Ayush Chaudhari
//Time Complexity=O(n)
//Logic Explained @ https://git.io/JUA7l


// Halloween Sale-How Many Games Function
int howManyGames(int p, int d, int m, int s) {
    int games=0,total_cost=0,current_game_cost=p;
    
    while((total_cost+current_game_cost)<=s){
        if((current_game_cost)>=m){
            games++;
            total_cost+=current_game_cost;
            current_game_cost-=d;
        }else{
            current_game_cost=m;
            games+=floor((s-total_cost)/current_game_cost);
            total_cost+=(floor((s-total_cost)/current_game_cost))*m;
            break;
        }
    }
    return games;
}