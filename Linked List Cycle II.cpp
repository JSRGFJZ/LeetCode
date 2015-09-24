/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    //https://leetcode.com/problems/linked-list-cycle/
    //http://m.blog.csdn.net/blog/hwb1992/23551105
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
		if (head==NULL||head->next==NULL){
			return NULL;
		}

		while (fast!=NULL&&fast->next!=NULL){
			fast=fast->next->next;slow=slow->next;
			if (fast==NULL){
				return NULL;
			}
			if(fast==slow){
			    fast=head;
		        while(fast!=slow){
    		    fast=fast->next;
    		    slow=slow->next;
    		    }
		        return fast;
			}
		}
		//return NULL;
    }
    //在while循环里面的if函数没有添加fast->next==NULL，看来前面一个程序也是要重新跑一下。
    //问题出在fast此时是最后一个节点，本身不为NULL，但是fast->next=NULL，所以不会进入循环
    //相反会执行下面的程序。
    //本题还有一个收获就是bool变量如果不人为初始化，它默认的值为0.
};