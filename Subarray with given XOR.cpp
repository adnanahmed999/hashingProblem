int Solution::solve(vector<int> &A, int B) {
    // cout<<"B val"<<B<<endl;
    // cout<<"starts"<<endl;
    int n = A.size();
    if(n==1) {if(A[0]==B){return 1;}} 
    vector<int> xoredArr(n);
    xoredArr[0] = A[0];
    for(int i=1; i<n; i++) {
        xoredArr[i] = xoredArr[i-1]^A[i];
    }
    // for(int i=0; i<n; i++) {
    //     cout<<A[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<n; i++) {
        
    //     cout<<xoredArr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"no prob "<<endl;
    unordered_map<int, int> m;
    unordered_map<int, int> :: iterator it;
    int ans = 0;
    // cout<<"n val"<<n<<endl;
    for(int i=0; i<n; i++) {
        // cout<<"came inse ";
        // cout<<A[i]<<endl;
        if(xoredArr[i]==B) {
            // cout<<"--"<<endl;
            // cout<<xoredArr[i]<<" "<<B<<endl;
            // cout<<"in"<<endl;
            ans++;
        } 
        if(m.find(xoredArr[i]^B)!=m.end()) {
            // cout<<"else"<<endl;
            it = m.find(xoredArr[i]^B);
            ans += it->second;
        }
        // cout<<"ans "<<ans<<endl;
        m[xoredArr[i]]++;
        // cout<<"gone outs"<<endl;
    }
    return ans;
}
