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
  
#define MARKER ')'   
const int N  = 5;

struct Node{
   char key;
   Node *child[N];
};

Node* newNode(char key){
   Node* temp = new Node();
   temp->key = key;
   memset(temp->child, NULL, sizeof temp->child);
   return temp;
}

void serialise(Node* root, FILE *fp){
   if(root == NULL)return;

   fprintf(fp, "%c ", root->key);
   for(int i = 0; i < N && root->child[i]; i++){
      serialise(root->child[i], fp);
   }
   fprintf(fp, "%c ", MARKER);
}

int deSerialise(Node* &root, FILE *fp){
   char val;
   if(!fscanf(fp, "%c ", &val) || val == MARKER)
      return 1;
   
   root = newNode(val);

   for(int i = 0; i < N; i++)
      if(deSerialise(root->child[i], fp))
         break;
   return 0;
}

Node *createDummyTree(){
    Node *root = newNode('A'); 
    root->child[0] = newNode('B'); 
    root->child[1] = newNode('C'); 
    root->child[2] = newNode('D'); 
    root->child[0]->child[0] = newNode('E'); 
    root->child[0]->child[1] = newNode('F'); 
    root->child[2]->child[0] = newNode('G'); 
    root->child[2]->child[1] = newNode('H'); 
    root->child[2]->child[2] = newNode('I'); 
    root->child[2]->child[3] = newNode('J'); 
    root->child[0]->child[1]->child[0] = newNode('K'); 
    return root; 
}

void traverse(Node* root){
   if(root){
      cout<<root->key<<" ";
      for(int i = 0; i < N; i++){
         traverse(root->child[i]);
      }
   }
}


int main(){
   IOS

   Node* root = createDummyTree();
   
   FILE *fp = fopen("tree.txt", "w");
   if(fp == NULL){
      cout<<"Could not open File";
      return 0;
   }
   serialise(root, fp);

   fclose(fp);

   Node *root1 = NULL;
   fp = fopen("tree.txt", "r");
   deSerialise(root1, fp);
   cout<<"Constructed N-ary tree : \n";
   traverse(root1);

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

