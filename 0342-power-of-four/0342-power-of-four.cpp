class Solution {
public:
    bool isPowerOfFour(int n) {
         bool b= true;
    if(n==0){
        return false;
    }
    while(n!=1){
        if(n%4!=0){
            b=false;
            break;
        }
        n=n/4;
    }
    if(b==true){
        return true;
    }
    else{
        return false;
    }
    }
};