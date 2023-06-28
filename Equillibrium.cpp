#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int prefix=nums[0];
    int total = 0;
    for(int i=0; i<n; i++){
        total+= nums[i];
    }
    vector<int> ans;
    for(int i=1; i<nums.size()-1; i++){
        if(total - (prefix + nums[i]) == prefix){
            ans.push_back(i);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}