class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<2) return s;
        int start=0,maxlen=1;
        for(int i=0;i<s.length();i++){
            int len=0;
            int left=i-1;
            int right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                len++;
                left--;
                right++;
            }
            int oddlen=2*len+1;
            if(oddlen>maxlen){
                maxlen=oddlen;
                start=i-len;
            }
            len=0;
            left=i;
            right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                len++;
                left--;
                right++;
            }
            int evenlen=2*len;
            if(evenlen>maxlen){
                maxlen=evenlen;
                start=i-len+1;
            }
        }
        return s.substr(start,maxlen);
    }
};