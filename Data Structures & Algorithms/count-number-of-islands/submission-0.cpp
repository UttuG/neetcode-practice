class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // make the nodes all present in a set (for easy add and removal)
        set<pair<int, int>> nodes;

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                nodes.insert({i,j});
            }
        } 
        // int for counting number of islands
        int islands = 0;

        // high level idea of the algo below : simple bfs

        while (nodes.size() >= 1){
            //start with a random or first node in the set
            pair<int,int> curr_node = *nodes.begin();
            // if 0 then just remove from parent set and continue else below logic:
            if (grid[curr_node.first][curr_node.second]== '0'){
                nodes.erase(curr_node);
                continue;
            }
            // make temperory queue for nodes to visit
            queue<pair<int,int>> curr_queue;
            curr_queue.push(curr_node);

            // remove node from the parent node set so that it is not explored any more (or chosen as start)
            nodes.erase(curr_node);

            while (curr_queue.size()>=1){
                // add its neighbours in the set to explore
                pair<int,int> curr_node = curr_queue.front();
                pair<int, int> right = {curr_node.first , curr_node.second + 1};
                pair<int, int> left = {curr_node.first , curr_node.second - 1};
                pair<int, int> top = {curr_node.first - 1, curr_node.second};
                pair<int, int> down = {curr_node.first + 1, curr_node.second};
                
                curr_queue.pop();
                // add left,right,top,down neighbors
                if (nodes.count(right)) {   // Check if neighbor is in the set
                    nodes.erase(right);     // Remove neighbor from set (mark visited)
                    if (grid[right.first][right.second] == '1'){
                        curr_queue.push(right); // Add neighbor to the BFS queue
                    }
                }
                if (nodes.count(left)) {   // Check if neighbor is in the set
                    nodes.erase(left);     // Remove neighbor from set (mark visited)
                    if (grid[left.first][left.second] == '1'){
                            curr_queue.push(left); // Add neighbor to the BFS queue
                        }
                }
                if (nodes.count(top)) {   // Check if neighbor is in the set
                    nodes.erase(top);     // Remove neighbor from set (mark visited)
                    if (grid[top.first][top.second] == '1'){
                            curr_queue.push(top); // Add neighbor to the BFS queue
                        }
                }
                if (nodes.count(down)) {   // Check if neighbor is in the set
                    nodes.erase(down);     // Remove neighbor from set (mark visited)
                    if (grid[down.first][down.second] == '1'){                 // if the neighbour is also one, add its neighbours in the queue
                            curr_queue.push(down); 
                        }
                }

                // do while the queue is empty
            }
            // once a queue is empty add 1 to count as a continuous queue meant that it was an island
            islands +=1;

        // do this while all nodes are not depleted in the parent island

        }


        // return the number of islands
        return islands;
    }
};
