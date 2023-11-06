#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int date;
    node*left;
    node* right;

    node(int data){
        this->date=data;
        this->left=NULL;
        this->right=NULL;
    }

};

node* buildTree(node *root){
        cout<<"Enter the data"<<endl;
        int data;
        cin>>data;
        root= new node(data);
        if (data == -1) {
            return NULL;
        }
        cout<<"Enter data from the left"<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter data from the right"<<endl;
        root->right=buildTree(root->right);
        return root;
        

    }




void levelOrderTraversal(node * root){
    queue <node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * current = q.front();
        q.pop();
        if(current==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << current -> date << " ";
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
    }
}


void Inorder(node *root){
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->date<<" ";
    Inorder(root->right);
}

void PreOrder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->date<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

}

void PostOrder(node *root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->date<<" ";


}



int main(){

    node* root= NULL;
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Inorder Traversal \n";
    Inorder(root);
    cout<<endl<<"PreOrder Traversal\n";
    PreOrder(root);
    cout<<endl<<"PostOrder Traversal\n";
    PostOrder(root);
    cout<<endl;

   

}