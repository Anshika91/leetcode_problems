// The API isBadVersion is defined for you.

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right){
            int mid = left + (right-left)/2;
            // cout << left << ", " << mid << ", " << right << endl;
            if(isBadVersion(mid)){
                /*
                when right is equal to left+1, 
                mid is also left,
                we should jump out (left < right = mid breaks),  
                because we have found 
                the first bad version which is mid, 
                and mid is equal to left
                */
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};