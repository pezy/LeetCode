class Solution {
public:
    int myAtoi(string A) {
        long long int temp=0, ans=0;
    
        int i=0;
        bool neg=0;
        
        while(A[i]==' ') i++;
        if(i==A.size()) return 0;

        if(A[i]=='-'){
            i++;
            neg=1;
        } else if(A[i]=='+') i++;

        for(;i<A.size();i++){
            if(A[i]<'0' || A[i]>'9') break;

            temp = A[i]-'0';

            ans = ans*10 + temp;
            
            if(neg && ans>INT_MAX) return INT_MIN;
            
            if(!neg && ans>=INT_MAX) break;
        }

        if(neg){
                return -ans;
        }
        if(ans>=INT_MAX) return INT_MAX;
        return ans;
    }
};