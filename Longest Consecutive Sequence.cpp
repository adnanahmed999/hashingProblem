int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> s;
    int size = A.size();
    for(int i=0; i<size; i++) {
        s.insert(A[i]);
    }
    int maxCount=0, tempCount=0;
    for(int i=0; i<size; i++) {
        if(s.find(A[i]-1)==s.end()) {
            int nextNum = A[i]+1;
            tempCount = 1; // the number itself
            while(s.find(nextNum)!=s.end()) {
                // cout<<(*(s.find(nextNum)))<<endl;
                tempCount++;
                nextNum++;
            }
            maxCount = max(maxCount, tempCount);
        }
    }
    return maxCount;
}
