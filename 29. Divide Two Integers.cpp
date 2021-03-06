class Solution {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
    	ll a = llabs(dividend);
    	ll b = llabs(divisor);
    	bool sign=(dividend>0&&divisor<0)||(dividend<0&&divisor>0);
    	ll result=0,c=b;
    	while (a>=b){
    		c=b;
    		for (int i=0;a>=c;c=c<<1,i++){
    			a=a-c;
    			result+=(1<<i);
    		}
    	}
    	return sign==true? -result:result;
    }
};

};
