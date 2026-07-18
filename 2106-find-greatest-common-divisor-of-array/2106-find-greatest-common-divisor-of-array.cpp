class Solution {
public:
    int findGCD(vector<int>& nums) {
        int  x   = *min_element(nums.begin(), nums.end()); 
        int  y   = *max_element(nums.begin(), nums.end()); 
        auto gcd = [](this const auto& self, int x, int y) -> int {
            return y == 0 ? x : self(y, x % y);
        };
        return gcd(x, y);
    }
};