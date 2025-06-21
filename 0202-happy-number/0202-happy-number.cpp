class Solution {
public:
    bool isHappy(int n) {
       
        unordered_map<int,bool> m1;
        int sum = 0;
        while(true){
          while(n > 0){
            int b = n%10;
            sum += b*b;
            n = n/10;
          }
          if(sum == 1||  sum == 7){
            return 1;
          }
          else if(sum < 10){
            return 0;
          }
          if(!m1[sum]){
            m1[sum] = 1;
            n = sum;
            sum = 0;
          }
            
        }
        return 0;
    }
};