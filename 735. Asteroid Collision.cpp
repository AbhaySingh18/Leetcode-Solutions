class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int diff;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty() && asteroids[i]<0 && st.top()>0){
                diff=asteroids[i]+st.top();
                if(diff<0){
                    st.pop();
                }
                else if(diff>0){
                    asteroids[i]=0;
                }
                else{
                    st.pop();
                    asteroids[i]=0;
                }
            }
            if(asteroids[i]){
                st.push(asteroids[i]);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
