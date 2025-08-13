class Solution {
public:
    bool isPowerOfThree(int n) {
        bool b= true;
    if(n==0){
        return false;
    }
    while(n!=1){
        if(n%3!=0){
            b=false;
            break;
        }
        n=n/3;
    }
    if(b==true){
        return true;
    }
    else{
        return false;
    } 
    }
};