/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
            return {};
        queue<Node* >q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> temp;
        while(!q.empty()){
            Node* f = q.front();
            if(f==NULL){
                q.pop();
                ans.push_back(temp);
                temp.clear();
                if(!q.empty())  q.push(NULL);
            }
            else{
                temp.push_back(f->val);
                q.pop();
                if(f->children.size()!=0){
                    for(auto x : f->children)
                        q.push(x);
                }
            }
        }
        return ans;
    }
};