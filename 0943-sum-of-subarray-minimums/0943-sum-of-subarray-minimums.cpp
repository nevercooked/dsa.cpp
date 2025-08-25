class Solution {
private:
    const long long MOD = 1e9+7;;
public:
    int sumSubarrayMins(std::vector<int>& nums) {
        std::stack<int> stk;
        long long       sum = 0;
        for (int k = 0; k <= nums.size(); ++k) {
            while (!stk.empty() && (k == nums.size() || nums[stk.top()] > nums[k])) {
                int j     = stk.top();
                stk.pop();
                int i     = !stk.empty() ? stk.top() : -1;
                int left  = j - i;
                int right = k - j;
                sum += (left * right * static_cast<long long>(nums[j])) % this->MOD;
            }
            stk.push(k);
        }
        return sum % this->MOD;
    }
};