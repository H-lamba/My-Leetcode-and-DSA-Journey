class Solution {
public:
    int minimumPushes(string s) {
        int freq[26] = {0};
        
        for(char c : s) {
            freq[c - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            
            ans += freq[i] * (i / 8 + 1);
        }
        
        return ans;
    }
};