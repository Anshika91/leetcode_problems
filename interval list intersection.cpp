class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> result;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int left = max(A[i].start, B[j].start);
            int right = min(A[i].end, B[j].end);
            if (left <= right) {
                result.emplace_back(left, right);
            }
            if (A[i].end < B[j].end) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};
