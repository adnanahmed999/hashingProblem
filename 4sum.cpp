vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    int size = A.size();
    if(size<4) {
        return ans;
    }
    int front, back, target;
    sort(A.begin(), A.end());
    vector<int> quaters;
    for(int i=0; i<(size-3); i++) {
        for(int j=i+1; j<(size-2); j++) {
            front = j+1;
            back = (size-1);
            target = B - A[i] - A[j];
            while(front < back) {
                if(A[front]+A[back]<target) {
                    while(A[front+1]==A[front]) {
                        front++;
                    }
                    front++;
                } else if(A[front]+A[back]>target) {
                    while(A[back-1]==A[back]) {
                        back--;
                    }
                    back--;
                } else if(A[front]+A[back]==target) {
                    quaters.clear();
                    quaters.push_back(A[i]);
                    quaters.push_back(A[j]);
                    quaters.push_back(A[front]);
                    quaters.push_back(A[back]);
                    ans.push_back(quaters);
                    while(A[front+1]==A[front]) {
                        front++;
                    }
                    front++;
                    while(A[back-1]==A[back]) {
                        back--;
                    }
                    back--;
                }
            }
            while((j+1)!=size && A[j+1]==A[j]) {
                j++;
            }
        }
        while((i+1)!=size &&A[i+1]==A[i]) {
            i++;
        }
    }
    return ans;
}
