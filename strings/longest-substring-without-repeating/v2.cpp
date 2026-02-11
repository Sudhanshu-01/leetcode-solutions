class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, maxlen=0;
        unordered_map<char,int> mpp;
        for(int right=0;right<s.length();right++){
            mpp[s[right]]++;
            while(mpp[s[right]]>1){
                mpp[s[left]]--;
                left++;
            }
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};