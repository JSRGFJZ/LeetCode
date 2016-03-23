class Solution {
public:
    bool isValid(string s) {
    	if (s.empty()){
    		return true;
    	}
    
    	int len=s.size();
    	if (len%2!=0){
    		return false;
    	}
    	stack<char>res;
    	for (int i=0;i<len;i++){
    		if (s[i]=='('||s[i]=='['||s[i]=='{'){
    			res.push(s[i]);
    		}else{
    			if (res.empty()){
    				return false;
    			}else{
    				char c=res.top();res.pop();
    				if((c=='('&&s[i]!=')')||(c=='['&&s[i]!=']')||(c=='{'&&s[i]!='}')){
    					return false;
    				}  
    			}
    		}
    	}
    	return res.empty();
    }
};
//防止出现 “((”的情况
//本题颇有难度，	if((c=='('&&s[i]!=')')||(c=='['&&s[i]!=']')||(c=='{'&&s[i]!='}'))  这个判断不曾想到
//还有最后的 “((”的情况 也不曾想到
//还有最后的 “((”的情况 也不曾想到
