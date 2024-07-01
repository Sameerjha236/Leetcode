class Solution {
public:
    int solve(const vector<int>& obstacles, int point, int lane,
              vector<vector<int>>& memo) {
        if (point + 1 >= obstacles.size()) {
            return 0;
        }
        if (obstacles[point + 1] != lane) {
            return solve(obstacles, point + 1, lane, memo);
        }
        if (memo[lane][point] != INT_MAX) {
            return memo[lane][point];
        }

        int jumpToLane1 = INT_MAX, jumpToLane2 = INT_MAX;
        if (lane == 1) {
            if (obstacles[point] != 2) {
                jumpToLane1 =
                    min(jumpToLane1, 1 + solve(obstacles, point, 2, memo));
            }
            if (obstacles[point] != 3) {
                jumpToLane2 =
                    min(jumpToLane2, 1 + solve(obstacles, point, 3, memo));
            }
        } else if (lane == 2) {
            if (obstacles[point] != 1) {
                jumpToLane1 =
                    min(jumpToLane1, 1 + solve(obstacles, point, 1, memo));
            }
            if (obstacles[point] != 3) {
                jumpToLane2 =
                    min(jumpToLane2, 1 + solve(obstacles, point, 3, memo));
            }
        } else {
            if (obstacles[point] != 1) {
                jumpToLane1 =
                    min(jumpToLane1, 1 + solve(obstacles, point, 1, memo));
            }
            if (obstacles[point] != 2) {
                jumpToLane2 =
                    min(jumpToLane2, 1 + solve(obstacles, point, 2, memo));
            }
        }

        memo[lane][point] = min(jumpToLane1, jumpToLane2);
        return memo[lane][point];
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> memo(4, vector<int>(n, INT_MAX));
        return solve(obstacles, 0, 2, memo);
    }
};
