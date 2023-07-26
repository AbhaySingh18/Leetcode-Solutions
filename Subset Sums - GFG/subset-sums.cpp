//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    public:
    void fun(int index,int sum,vector<int>&arr,int n,vector<int>&summation){
        if(n==index){
            summation.push_back(sum);
            return;
        }
        fun(index+1,sum+arr[index],arr,n,summation);
        fun(index+1,sum,arr,n,summation);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>summation;
        fun(0,0,arr,N,summation);
        sort(summation.begin(),summation.end());
        return summation;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends