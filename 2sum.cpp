// solved from interviewBit
// watch striver video for reference

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> m;
    int sizee = A.size();
    vector<int> ans;
    for(int i=0; i<sizee; i++) {
        if(m.find(B-A[i])!=m.end()) {
            auto it = m.find(B-A[i]);
            int index2 = it->second;
            ans.push_back(++index2);
            ans.push_back(++i);
            return ans;
        }
        if(m.find(A[i])==m.end()) {
            // because index1 we want minimum, so if same value is present earlier and we set value of M[i], then previous value will be over-written
            m[A[i]] = i;   
        }
    }
    return ans;
}
