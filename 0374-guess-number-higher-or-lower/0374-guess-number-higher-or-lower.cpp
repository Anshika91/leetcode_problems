int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, cur = left+(right-left)/2;

        while(true){
            switch(guess(cur)){
                case -1:
                    right = cur-1;
                    cur = left+(right-left)/2;
                    break;
                case 1:
                    left = cur+1;
                    cur = left+(right-left)/2;
                    break;
                case 0:
                    return cur;
            }
        }
        return 0;
    }
};