class Solution {
public:
    int n;
    const int direction[5] = {0,1,0,-1,0};

    unordered_map<int, int> componentSize;

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = 0;
        // because we already have 0 and 1
        int nextColor = 2;
        for (int r = 0; r < n; r++){
            for (int c = 0; c< n; c++){
                if (grid[r][c] !=1){
                    continue;
                }
                paint(grid, r,c, nextColor);
                ans = max(ans, componentSize[nextColor]);
                nextColor++;
            }
        }

        for (int r = 0; r<n; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c] != 0){
                    continue;
                }

                unordered_set<int> neighborColor;
                for (int i = 0; i <4; i++){
                    int nr = r+ direction[i];
                    int nc = c+ direction[i+1];
                    if (nr< 0|| nr==n||nc==n||nc<0||grid[nr][nc]==0){
                        continue;
                    }

                    neighborColor.insert(grid[nr][nc]);
                }

                int sizeForm = 1;
                for (int color: neighborColor){
                    sizeForm += componentSize[color];
                }

                ans = max(ans, sizeForm);
            }
        }

        return ans;
        
    }


    void paint(vector<vector<int>>& grid, int r, int c, int color){
        if (r< 0 || r == n || c<0 || c == n || grid[r][c] !=1){
            return;
        }
        grid[r][c] = color;
        componentSize[color]+=1;
        for (int i = 0; i < 4; i++){
            paint(grid, r+direction[i], c+direction[i+1], color);
        }
    }
};
