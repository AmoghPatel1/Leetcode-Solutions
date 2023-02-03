class Solution{
public:
    int rob(vector<int> &nums){
        if(nums.size() == 1) return nums[0];
        int ans = 0;
        int rob1 = 0, rob2 = 0;
        int last = nums[nums.size()-1];
        nums.pop_back();
        for (int i = 0; i < nums.size(); i++){
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        ans = rob2;
        cout << ans << endl;
        rob1 = 0, rob2 = 0;
        nums.erase(nums.begin());
        nums.push_back(last);
        for(int i=0;i<nums.size();i++) {
            int temp = max(rob1+nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }   
        ans = max(ans, rob2);

        return ans;
    }
};