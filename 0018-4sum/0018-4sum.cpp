class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            if (i && nums[i] == nums[i - 1]) continue;

            // Pruning
            long long mn = 1LL * nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (mn > target) break;

            long long mx = 1LL * nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (mx < target) continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long mn2 = 1LL * nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (mn2 > target) break;

                long long mx2 = 1LL * nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (mx2 < target) continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {

                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {

                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        l++;
                        r--;

                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;

                    }
                    else if (sum < target)
                        l++;
                    else
                        r--;
                }
            }
        }

        return ans;
    }
};