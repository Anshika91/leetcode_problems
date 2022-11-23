class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        
        while(n > 0){
            int d = n%10;
            product *= d;
            sum += d;
            n /= 10;
        }
        
        return product - sum;
    }
};

