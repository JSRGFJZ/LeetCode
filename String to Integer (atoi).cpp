class Solution {
public:
    int myAtoi(string str) {
    	if (str.empty()){
    		return 0;
    	}
    	int sign=1,i=0,base=0;
    	while (str[i]==' '){
    		i++;
    	}
    	if (str[i]=='-'||str[i]=='+'){
    		sign=1-2*(str[i++]=='-');
    	}
    	while ('0'<=str[i]&&str[i]<='9'){
    		if (base>INT_MAX/10||(base==INT_MAX/10&&str[i]>'7')){
    			if (sign==1){
    				return INT_MAX;
    			}else
    				return INT_MIN;
    		}
    		base=base*10+(str[i++]-'0');
    	}
    	return base*sign;
    }
};
// 好题目啊,不会，还是很多bug的,小瑕疵不断啊
//这种小题目 ,做了不知道多少遍 还是不会啊
