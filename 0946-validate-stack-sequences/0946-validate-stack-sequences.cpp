class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int i=0, j=0;
        stack<int> st;
        while(j<n) {
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j+=1;
            } else {
                if(i>=n) return false;
                st.push(pushed[i]);
                i+=1;
            }
        }
        if(j == n && st.empty()) return true;
        return false;
    }
};