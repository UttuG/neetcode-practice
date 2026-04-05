class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        //queue of nodes bordering pacific
        queue<pair<int,int>> pacific_q;
        set<pair<int,int>> pacific_s; //set (initialize with bordering) where water will reach pacific
        
        for (int i=0; i< heights.size();i++){
            if (i==0){
                for (int j=0;j<heights[0].size();j++){
                    pacific_q.push({i,j});
                    pacific_s.insert({i,j});
                }
                continue;
            }
            pacific_q.push({i,0});
            pacific_s.insert({i,0});
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        //while pacific queue not empty
        while (!pacific_q.empty()){
            auto [r,c] = pacific_q.front();
            pacific_q.pop();
            //check neighbouring cells not in set already for height greater or equal
            for (auto [i,j] : dir){
                // if yes add them in set and in the queue
                int nc = c + j;
                int nr = r + i;

                if (nc < heights[0].size() && nr < heights.size() && nr >=0 && nc >=0){
                    if (heights[nr][nc]>=heights[r][c] && !pacific_s.count({nr,nc})){
                        pacific_q.push({nr,nc});
                        pacific_s.insert({nr,nc});
                    }
                }
            }
        }
        //same for atlantic

        queue<pair<int,int>> atlantic_q;
        set<pair<int,int>> atlantic_s;

        for (int i=0; i< heights.size();i++){
            if (i==heights.size()-1){
                for (int j=0;j<heights[0].size();j++){
                    atlantic_q.push({i,j});
                    atlantic_s.insert({i,j});
                }
                continue;
            }
            atlantic_q.push({i,heights[0].size()-1});
            atlantic_s.insert({i,heights[0].size()-1});
        }
        
        while (!atlantic_q.empty()) {
            auto [r,c] = atlantic_q.front();
            atlantic_q.pop();

            for (auto [dr,dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                // check bounds
                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size()) {
                    // only move to higher/equal height and not visited yet
                    if (heights[nr][nc] >= heights[r][c] && !atlantic_s.count({nr,nc})) {
                        atlantic_q.push({nr,nc});
                        atlantic_s.insert({nr,nc});
                    }
                }
            }
        }
        vector<vector<int>> result;
        //intersection of both pacific and atlantic set is the answer
        for (int r = 0; r < heights.size(); r++) {
            for (int c = 0; c < heights[0].size(); c++) {
                // if the cell is in both Pacific and Atlantic sets
                if (pacific_s.count({r, c}) && atlantic_s.count({r, c})) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
        
    }
};
