class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // find and make a list of all the rotting fruits <row,col,0>
        //initialize a queue for processing and making rotten fruits
        //add all the rotten fruits in that
            //during this also make a count of how many fresh fruits were encountered
        
        queue<tuple<int,int,int>> rotten;
        int fresh =0;

        for (int i=0; i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==2){
                    rotten.push({i,j,0});
                    }
                if (grid[i][j]==1){
                    fresh+=1;
                    }
                }
            }
        
        tuple<int,int,int> curr_rotten;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while (!rotten.empty()){
            // start bfs from all rotten fruits
            curr_rotten = rotten.front();
            auto [r,c,t] = curr_rotten;
            rotten.pop();

            //search neighbours and then add any adjacent fresh fruit in the queue(as rotten and time +1)
            for (auto [i,j] : dir){
                int nr = r + i;
                int nc = c + j;

                if (nr >= 0 && nr<=grid.size()-1 && nc >= 0 && nc<=grid[0].size()-1){
                if (grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    rotten.push({nr,nc,t+1});
                    fresh-=1;
                }
                }
            }
        }
            // do while queue empty
        
        // if total fruits made rotten == number of fresh fruits, return last rottening time
        if (fresh==0){
            return get<2>(curr_rotten);
        }
        else{
            return -1;
        }
        }

    
};
