class Solution {
public:
    long long calculate(vector<int> &nums,vector<int> &cost,long long median){
        long long ans =0;
        for(int i=0;i<nums.size();i++){
            ans=ans+abs(1ll*nums[i]-median)*(1ll*cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long int total =0,sum=0,n=nums.size();
        vector<pair<int,int>> m;
        for(int i=0;i<n;i++){
            m.push_back({nums[i],cost[i]});
        }
        sort(m.begin(),m.end());
        for(int i=0;i<n;i++){
            sum=sum+1ll*m[i].second;
        }
        long long median;
        int i=0;
        while(total<(sum+1)/2 && i<n){
            total=total+(1ll*m[i].second);
            median=m[i].first;
            i++;
        }
        return calculate(nums,cost,median);
    }
};
