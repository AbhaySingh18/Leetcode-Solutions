class Solution {
public:
    vector<int> p; // Union-Find data structure
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        p[y] = x;
    }
    
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 1)); // grid to represent the state of cells
        p = vector<int>(row*col + 3, -1); // initialize Union-Find array
        
        int startG = row*col+1, endG = row*col+2; // two dummy nodes
        for(int j = 0; j < col; j++){
            uni(j, startG); // connect top row cells to the start dummy node
            uni((row-1)*col + j, endG); // connect bottom row cells to the end dummy node
        }
        
        for(int i = row*col-1; i >= 0; --i){
            int r = cells[i][0]-1, c = cells[i][1]-1;
            grid[r][c] = 0; // mark the cell as blocked
            int key = r*col + c; // unique identifier for the current cell
            for(int k = 0; k < 4; ++k){
                int nr = r+dir[k][0], nc = c+dir[k][1]; // neighbor cell coordinates
                if(nr >= 0 && nr < row && nc >= 0 && nc < col && !grid[nr][nc]){
                    int nkey = nr*col + nc; // unique identifier for the neighbor cell
                    uni(key, nkey); // connect the current cell to the neighbor cell
                }
                if(find(startG) == find(endG)){
                    return i; // if the start and end are connected, the last day to cross is found
                }
            }
        }
        
        // If it reaches here, it means it's impossible to cross the grid
        return row*col-1;
    }
};
