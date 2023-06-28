#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int>&nums,int eo){
    int max1=0,max2=0;
    for (int i=eo;i<nums.size();i+=2) {
        if(max1<=nums[i]){
            max2=max1;
            max1=nums[i];
        } 
        else if (nums[i] > max2 && nums[i] < max1) {
            max2 = nums[i];
        }
    }
    return max2;
}    

int main(){
    int n;
    vector<int>nums;
    cout<<"Enter the number of elements you want in the array.";
    cin>>n;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        nums.push_back(p);
    }
    if(n<4)
        cout<<"Not Possible";
    else{
        int oddSecondLargest=helper(nums,1);
        int evenSecondLargest=helper(nums,0);
        cout<<"Sum is equal to: "<<oddSecondLargest+evenSecondLargest;
    }
}
