class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, n = arr.size();
        if (n < 3)
            return 0;
        for (int i = 1; i < n; i++) {
            int a = i - 1, b = i + 1;

            while (a >= 0 && b < n && arr[a] < arr[a + 1] &&
                   arr[b] < arr[b - 1]) {
                a--;
                b++;
            }
            if (a == i - 1 && b == i + 1)
                continue;
            while (a >= 0 && arr[a] < arr[a + 1])
                a--;
            while (b < n && arr[b] < arr[b - 1])
                b++;
            ans = max(ans, b - a - 1);
        }
        return ans;
    }
};