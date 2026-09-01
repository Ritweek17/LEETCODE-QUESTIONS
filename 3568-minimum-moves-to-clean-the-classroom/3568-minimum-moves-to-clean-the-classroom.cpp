class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        
        pair<int,int> start;
        vector<pair<int,int>> litter;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(classroom[i][j] == 'S') {
                    start = {i, j};
                }
                
                if(classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if(k == 0)
            return 0;

       
        map<pair<int,int>, int> litterIndex;

        for(int i = 0; i < k; i++) {
            litterIndex[litter[i]] = i;
        }

        
        int allMask = (1 << k) - 1;

        queue<tuple<int,int,int,int,int>> q;

        q.push({start.first, start.second, energy, 0, 0});

      
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        visited[start.first][start.second][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

       
        while(!q.empty()) {

            auto [r, c, e, mask, moves] = q.front();
            q.pop();

           
            if(mask == allMask)
                return moves;

           
            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

               
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

              
                if(classroom[nr][nc] == 'X')
                    continue;

                if(e == 0)
                    continue;

                int newEnergy = e - 1;
                int newMask = mask;

          
                if(classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

              
                if(classroom[nr][nc] == 'L') {
                    int idx = litterIndex[{nr, nc}];
                    newMask |= (1 << idx);
                }

                
                if(visited[nr][nc][newEnergy][newMask])
                    continue;

                visited[nr][nc][newEnergy][newMask] = true;

                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    moves + 1
                });
            }
        }

        return -1;
    }
};