class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;

		int min_diff = INT_MAX;

		

		sort(arr.begin(), arr.end());

		for (int i = 1; i < arr.size(); ++i)

		{

			int md = abs(arr[i] - arr[i - 1]);

			if (md < min_diff)

			{

				res.clear();

				min_diff = md;

			}

			if (md == min_diff)

			{

				vector<int> v {arr[i - 1], arr[i]};

				res.push_back(v);

			}

		}

		return res;
    }
};