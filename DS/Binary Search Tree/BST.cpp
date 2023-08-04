#include "BST.hpp"

BST::BST(){
    root = nullptr  ;
}

BST::BST(int data){
    root->val = data ; 
}

BST::~BST(){
    deleteTree(root) ; 
}

void BST::deleteTree(TreeNode *node){
    if(!node) return ; 
    if(node->left) deleteTree(node->left) ; 
    if(node->right) deleteTree(node->right) ; 
    delete node ; 
} 

TreeNode* BST::insert(TreeNode *root , int val){
    if(!root){
        return new TreeNode(val) ;  
    }
    if(val < root->right->val) insert(root->right , val);
    if(val > root->left->val) insert(root->left , val) ; 
    return nullptr ; 
}

void BST::insert(int target){
    insert(root,target) ; 
}

void BST::inorder_print(TreeNode *root){
    if(!root) return  ; 
    int value = root->val ; 
    if(root->left) inorder_print(root->left) ; 
    std::cout<<value<<'\t' ; 
    if(root->right) inorder_print(root->right) ; 
}

void BST::print(){
    inorder_print(root) ; 
    std::cout<<'\n'  ; 
}

std::pair<TreeNode* , bool> BST::search(TreeNode *root , int target){
    bool res = root->val == target ; 
    int value = root->val ; 
    if(!root)  return {nullptr  ,false} ; 
    if(res) return {root ,true} ; 
    if(value > target && root->right) search(root->right , target) ; 
    if(value < target && root->left) search(root->left , target)  ; 
}

bool BST::search(int target){
    std::pair<TreeNode* , bool> answer = search(root,target) ; 
    return answer.second ; 
}

//--------------------------UTILITY Functions-----------------------------//
TreeNode* BST::GetParent(TreeNode* root  , TreeNode* ToDelete ){
    if(!root) return nullptr ; 
    if(root->right == ToDelete ||root->left == ToDelete ){
        return root ; 
    }
    GetParent(root->right , ToDelete) ; 
    GetParent(root->left , ToDelete) ; 
}

void  BST::link(TreeNode* parent , TreeNode* child , const std::string &direction){
    if(direction == "left"){
        parent->left = child ;
    }else if(direction == "right"){
        parent->right = child; 
    }else{
        std::cerr<<"Invalid Direction\n" ; 
    }
}

bool BST::IsLeaf(TreeNode *node){
    if (node && !node->left && !node->right)
        return true;
    return false  ;
}

void BST::Delete(int target){
    std::pair<TreeNode* , bool> isFound = search(root , target) ; 
    if(!isFound.second) {
        std::cout<<target<<"\t is Not Found !!"<<'\n' ; 
        return ; 
    }
    TreeNode* ToDelete = isFound.first ; 
    TreeNode* Parent = GetParent(root , ToDelete) ; 

    if(IsLeaf(ToDelete)&&Parent->left == ToDelete) {
        delete ToDelete ; 
        Parent->left = nullptr ; 
        return ; 
    }else if (IsLeaf(ToDelete)&&Parent->right== ToDelete){
        delete ToDelete ; 
        ToDelete->right= nullptr; 
        return ;
    }
}
