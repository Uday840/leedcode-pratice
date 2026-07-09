class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n - 3; i++) {

            for (int j = i + 1; j < n - 2; j++) {

                unordered_set<long long> seen;

                for (int k = j + 1; k < n; k++) {

                    long long need = (long long)target - nums[i] - nums[j] - nums[k];

                    if (seen.count(need)) {
                        st.insert({nums[i], nums[j], (int)need, nums[k]});
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};