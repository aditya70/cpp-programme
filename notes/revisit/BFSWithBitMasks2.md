### https://leetcode.com/problems/shortest-path-to-get-all-keys/
- BFS with state tracking	State = (x, y, keys bitmask).

```
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(), n=grid[0].size();
        int allMask=0; // mask for all keys present in the grid
        int startX=-1, startY=-1;
        int k=0; // number of keys

        // Count keys and locate start
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=grid[i][j];
                if(ch=='@'){
                    startX=i;
                    startY=j;
                } else if (ch>='a'&&ch<='f') {
                    int bit=ch-'a';
                    // set bit for this key
                    allMask = allMask | (1<<bit);
                    k++;
                }
            }
        }

        // BFS queue: tuple (x, y, collectedKeysMask)
        // BFS with state tracking	State = (x, y, keys bitmask).
        queue<tuple<int,int,int>> q;

        // visited[x][y][mask]
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(1<<k,false)));
        q.emplace(startX, startY,0);
        vis[startX][startY][0]=true;

        int steps=0;
        int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}}; // 4 neighbours of cell

        while(!q.empty()) {
            int size=q.size();
            while(size--){
                auto [x,y,mask]=q.front();
                q.pop();
                // If we've collected all keys
                if(mask==allMask) return steps;
                
                for(auto& d:dir){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    if(nx<0||nx>=m||ny<0||ny>=n) continue;

                    char ch=grid[nx][ny];
                    if (ch=='#') continue;  //  wall state
                    
                    int newMask = mask;

                    // If it's a key, collect it, key state  
                    if (ch>='a'&&ch<='f') {
                        int bit=ch-'a';
                        newMask=newMask | (1<<bit);
                    }

                     // If it's a lock, check if key present, lock state
                    if (ch>='A'&&ch<='F') {
                        int bit=ch-'A';
                         // we don't have the key for this lock
                        if((newMask & (1<<bit))==0) continue;
                    }

                    // if state not visited
                    if(!vis[nx][ny][newMask]) {
                        vis[nx][ny][newMask]=true;
                        q.emplace(nx,ny,newMask);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
```