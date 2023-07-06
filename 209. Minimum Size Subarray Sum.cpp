class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), ans = INT_MAX;
        int sum = 0;
        int left = 0,right = 0;
        while(right<len){
            sum+=nums[right];
            while(sum>=target && left<=right){
                sum-=nums[left];
                ans = min(ans,right-left+1);
                left++;
            }
            right++;
        }
        return ans==INT_MAX?0:ans;
    }
};
