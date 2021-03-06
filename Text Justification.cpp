class Solution {
    //https://leetcode.com/submissions/detail/50523961/
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int len=words.size(),i=0;
        while(i<len){
            int rowlen=0,j=i;
            //找能够放进去几个
            while(j<len&&words[j].length()+rowlen<=maxWidth){//之所以这么写，是考虑到最后一个没有空格
                rowlen+=(words[j++].length()+1);
            }//i---j  此时的j是不行的，另外还多一个字符空格  j-1 就是有多少符合的
            
            if(j-i==1){//处理单个字符
                addSpace(words[i],maxWidth-(rowlen-1));
                res.push_back(words[i]);
                i=j;continue;
            }
            
            int charaLen=rowlen-(j-i);//当前有多少个字符
            int meanSpace=j<len?  (maxWidth-charaLen)/(j-i-1) : 1;//只要是最后一行，无论有多少个字符串，间隙都是1
            int leftSpace=j<len?  (maxWidth-charaLen)%(j-i-1) : (maxWidth-(rowlen-1)); 
            //这里指的是所有的单词都是最后一行
            
            string tmp;
            for(int k=i;k<j-1;k++){//j不符合要求
                tmp+=words[k];
                addSpace(tmp,meanSpace);
                if(j<len&&leftSpace>0){
                    tmp.push_back(' ');leftSpace--;//这次被我写成 k<len，那就一定出错了
                    //那么这之间是不需要增加空格,因为全部为1，已经算进去了
                }
            }//接下来是最后一个单词，最后一个单词要独立完成
            
            tmp+=words[j-1];
            if(leftSpace>0)     addSpace(tmp,leftSpace);
            res.push_back(tmp);
            i=j;
        }
        return res;
    }
    
    void addSpace(string &s,int count){
        for(int i=1;i<=count;i++){
            s.push_back(' ');
        }
    }
};
//rowlen+=(words[j++].length()+1);  这个地方没有加1，很多细节地方还不到位
//  暂时认定 是每个字符都要加1的，中间不能非空
//  (maxWidth-charaLen)/(j-i-1)  这个地方是要减1的，因为最后一个字符不能算   1 2 3  只能算两个的，这样才是meanSpace的
//j<len&&leftSpace>0  这个地方非常容易出错
// 难 注意两种情况 1. 到最后一行，而且j最后一个 2 . j已经成为最后一个,老问题啊，不会做，容易出错
// j<len&&leftSpace>0  这一次还是这边没有注意啊
