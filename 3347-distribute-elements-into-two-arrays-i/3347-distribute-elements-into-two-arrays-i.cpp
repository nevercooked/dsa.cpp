class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        deque<int> arr1; 
        deque<int> arr2; 
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }
        vector<int> res;
        while (!arr1.empty()) {
            res.push_back(arr1.front());
            arr1.pop_front();
        }
        while (!arr2.empty()) {
            res.push_back(arr2.front());
            arr2.pop_front();
        }
        return res;
    }
};