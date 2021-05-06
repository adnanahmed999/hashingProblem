vector<int> Solution::lszero(vector<int> &A) {
    vector<int> ans;
    int start=0, end=0;
    int n = A.size();
    if(n==0) return ans;
    if(n==1) { 
        if(A[0]==0) {
            ans.push_back(0);
            return ans;
        } else {
            return ans;
        }
    }
    unordered_map<int, int> m;
    unordered_map<int, int> :: iterator it;
    int maxx = INT_MIN;
    bool nothingHere = true;
    int sumTillHere=0; //more like storing prefix Sum with single variable (it will have prefix sum at ith element).
    for(int i=0; i<n; i++) {
        sumTillHere += A[i];
        if(sumTillHere==0) {
            nothingHere = false;
            start = 0;
            end = i;
            maxx = i+1;
        } else {
            if(m.find(sumTillHere)!=m.end()) {
                nothingHere = false;
                it = m.find(sumTillHere);
                if(i-(it->second)>maxx) {
                    maxx = i-(it->second);
                    start = (it->second)+1;
                    end = i;
                }
            } else {
                m[sumTillHere] = i;
            }
        }
    }
    if(nothingHere==true) {
        return ans;
    } else {
        for(int i=start; i<=end; i++) {
            ans.push_back(A[i]);
        }
    }
    return ans;
}
