class Solution {
public:
    char nextGreatestLetter(const std::vector<char>& letters, const char& target) {
        int left  = 0;
        int right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left == letters.size() ? letters[0] : letters[left];
    }
};