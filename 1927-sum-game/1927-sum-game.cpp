class Solution {
public:
    bool sumGame(string num) {
        int sum1 = 0;
        int sum2 = 0;
        int q1 = 0 ;
        int q2 = 0;
        int n = num.size();
        for(int i = 0 ; i<num.size(); i++)
        {
            if(i<n/2)
            {
                if(num[i]=='?')
                {
                    q1++;
                }
                else
                {
                    sum1+=(num[i]-'0');
                }
            }
            else
            {
                if(num[i]=='?')
                {
                    q2++;
                }
                else
                {
                    sum2+=(num[i]-'0');
                }
            }
        }
        if((q1+q2)%2!=0) return true;
        if(sum1-sum2 == ((q2 - q1) / 2.0 * 9.0)) return false;
        return true;
    }
};