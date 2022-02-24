vector<int> Solution::maxset(vector<int> &A) {
    vector<long long> r(A.size());
    vector<int>res;
    r[0] = A[0];
    int negative = A[0]>=0 ? 0:1;
    for(int i=1;i<A.size();i++){
        if(A[i]<0){
            negative++;
        }
        if(A[i]>=0 && A[i-1]>=0){
            r[i] = r[i-1]+A[i];
        }
        else{
            r[i] = A[i];
        }
    }    

    if(negative==A.size()){
        return res;
    }

    long long max = INT_MIN;
    int max_index = 0,start = 0,g_start =0;
    for(int i=0;i<r.size();i++){
        if(r[i]>=0 && r[i-1]<0){
            start = i;
        }

        if(r[i] > max){
            max = r[i];
            max_index = i;
            g_start = start;
        }

        else if(r[i]==max){
            if(i-start > (max_index-g_start))
            {
                g_start = start;
                max_index = i;
            }
        }
    }

    for(int i = g_start;i<=max_index;i++){
        res.push_back(A[i]);
    }

    return res;
}
