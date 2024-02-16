class Solution {
public:
    int hammingWeight(uint32_t n) {

        
        // if(n==0)return 0;
        if(n==1)return 1;
       int count=0;
        while(n&&(n-1)!=0)
        {
            count++;
            n=n&(n-1);
        }
        return count;
    }
};
