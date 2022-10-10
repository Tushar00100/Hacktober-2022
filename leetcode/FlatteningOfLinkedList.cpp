
class Solution {
public:
    Node* flatten(Node* head) {
       
        stack<Node*>st;
        Node *cur=head;
        while(cur){
            if(cur->child){
                if(cur->next)
                st.push(cur->next);
                cur->next=cur->child;
                cur->child->prev=cur;
                cur->child=NULL;
                cur=cur->next;
            }else if(cur->next){
                cur=cur->next;
            }else{
                if(st.empty()) break;
                Node* temp=st.top();
                st.pop();
                cur->next=temp;
                temp->prev=cur;
                cur=temp;
            }
        }
        return head;
      
    }
};
