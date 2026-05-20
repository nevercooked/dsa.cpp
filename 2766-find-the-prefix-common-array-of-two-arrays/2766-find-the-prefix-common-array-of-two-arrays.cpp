class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int         n = A.size();
        vector<int> C(n);
        set<int> seenA;
        set<int> seenB;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            seenA.insert(A[i]);
            seenB.insert(B[i]);
            set_intersection(seenA.begin(), seenA.end(), seenB.begin(), seenB.end(), inserter(seen, seen.begin()));
            C[i] = seen.size();
        }
        return C;
    }
};