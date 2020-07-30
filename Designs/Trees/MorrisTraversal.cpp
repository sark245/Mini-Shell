//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    
struct Node{
    int val;
    Node *left, *right;
    Node (){}
    Node (int val) : val(val), left(NULL), right(NULL){}
};

void inorder(Node *root){
    stack<Node*> st;
    Node*cur = root;
    while(cur != NULL || !st.empty()){
        while(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();

        cout<<cur->val<<" ";
        cur = cur->right;
    }
}

void MorrisTraversal(Node *root){
    Node *cur, *pre;

    if(root == NULL)return;

    cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            cout<<cur->val<<" ";
            cur = cur->right;
        }else{
            pre = cur->left;
            while(pre->right != NULL && pre->right!= cur)pre = pre->right;
            if(pre->right == NULL){
                pre->right = cur;
                cur = cur->left;
            }else{
                pre->right = NULL;
                cout<<cur->val<<" ";
                cur = cur->right;
            }
        }
    }
}



int main(){
   IOS

   Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5);
    inorder(root);
    cout<<endl;

    MorrisTraversal(root);

}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

