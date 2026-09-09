class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long base = 1000;
        while(base<=n)
        {
            count+=(n-base+1);
            base = base*1000;
        }
        return count;
    }
};