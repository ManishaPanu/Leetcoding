class Solution {
public:
    int n;
    pair<int, int> getCoord(int num) {
        int RT = (num-1) / n;
        int RB = (n-1) - RT;
        int col = (num-1) % n;
        if((RB%2 == 0 && n%2 == 0) || (RB%2 == 1 && n%2 == 1)) {
            col = (n-1) - col;
        }
        return make_pair(RB, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        int steps = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n-1][0] = true;
        q.push(1);

        while (!q.empty()) {
            int size = q.size();
            while(size--) {
                int x = q.front();
                q.pop();

                if(x == n*n) return steps;

                for(int k=1; k<=6; k++) {
                    int val = k+x;
                    if(val > n*n) break;
                    pair<int, int> coord = getCoord(val);
                    int r = coord.first;
                    int c = coord.second;
                    if(vis[r][c] == true) continue;
                    vis[r][c] = true;
                    if(board[r][c] == -1) {
                        q.push(val);
                    }
                    else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
