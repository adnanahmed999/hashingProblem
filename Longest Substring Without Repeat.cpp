int Solution::lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) {return 0;}
        int lastIndex = 0;
        int len=0, maxLen=0;
        unordered_map<char, int> m;
        unordered_map<char, int> :: iterator it;
        // cout<<"fineeeeeeeeeee"<<endl;
        for(int i=0; i<n; i++) {
            // cout<<i<<"->"<<s[i]<<endl;
            if(m.find(s[i])!=m.end()) {
                it = m.find(s[i]);
                if(it->second >= lastIndex) {
                    maxLen = max(maxLen, len);
                    len = i-(it->second);
                    lastIndex = (it->second)+1;
                } else {
                    len++;
                }
            } else {
                len++;
            }
            m[s[i]] = i;
        }
        maxLen = max(maxLen, len);
        return maxLen;
}
