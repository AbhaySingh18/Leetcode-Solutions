class Solution {
public:
    void helper(int index,vector<int>& cookies,vector<int>& pair,int k,int & ans){
        int n=cookies.size();
        if(index==n){
            int temp=INT_MIN;
            for(auto i:pair)
                temp=max(temp,i);
            ans=min(ans,temp);
                return;
        }
        for(int i=0;i<k;i++){
            pair[i]+=cookies[index];
            helper(index+1,cookies,pair,k,ans);
            pair[i]-=cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>pair(k,0);
        int ans=INT_MAX;
        helper(0,cookies,pair,k,ans);
        return ans;
    }
};
