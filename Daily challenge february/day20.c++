class Solution{   
public:
    int countPaths(int N){
        // code here
        long long t1 = 0, t2 = 3, t3 = 6;

        if(N==0 || N==1) return t1;

        if(N==2) return t2;

        if(N==3) return t3;

        for(int i=4; i<=N; i++){

            long long t4 = ((3*t1) + (5*t2) + t3)%1000000007;

            t1 = t2;

            t2 = t3;

            t3 = t4;

        }

        return t3;
    }
};
