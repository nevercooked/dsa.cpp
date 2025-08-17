class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto      product = std::vector<int>(nums.size(), 0);
        long long accu    = 1;
        for (int i = 0; i < product.size(); ++i) {
            product[i] = accu;
            accu      *= nums[i];
        }
        accu = 1;
        for (int i = product.size() - 1; i >= 0; --i) {
            product[i] *= accu;
            accu       *= nums[i];
        }
        return product;
    }
};