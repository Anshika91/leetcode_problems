// The API isBadVersion is defined for you.

class Solution {
    public:
    int firstBadVersion(int n) {
        long long int beg,last,mid;
        beg = 1 , last = n;
        long int pos = 1;
        while(beg<=last){
            // ensure you calculate mid values this way ,otherwise ,it would cause overflow
            mid = beg + (last-beg)/2;
            bool x = isBadVersion(mid);
            if(x == true){
                pos = mid;
                last = mid-1;
            }
            else
                beg = mid+1;
        }

        // return the first index of faulty product
        return pos;
    }
};