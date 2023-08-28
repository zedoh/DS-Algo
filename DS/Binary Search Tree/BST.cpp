#include "BST.hpp"

BST::BST(){
    root = nullptr  ;
}

BST::BST(int data) : root(new TreeNode(data)) {}

BST::~BST(){
    deleteTree(root) ; 
}

void BST::deleteTree(TreeNode *node){
    if(!node) return ; 
    if(node->left) deleteTree(node->left) ; 
    if(node->right) deleteTree(node->right) ; 
    delete node ; 
} 

void  BST::insert(TreeNode *root , int val){
    if(val < root->val){
        if(!root->left) root->left = new TreeNode(val) ;
        else
            insert(root->left, val);
    }
    if (val > root->val)
        {
            if (!root->right)
                root->right = new TreeNode(val);
            else
                insert(root->right, val);
        }
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

std::pair<TreeNode*, bool> BST::search(TreeNode* root, int target) {
    if (!root) {
        return {nullptr, false};
    }

    int value = root->val;

    if (value == target) {
        return {root, true};
    } else if (value < target) {
        return search(root->right, target);
    } else {
        return search(root->left, target);
    }
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
    return GetParent(root->right , ToDelete) ; 
    return GetParent(root->left , ToDelete) ; 
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

TreeNode* BST::GetLeaf(TreeNode* root , const std::string &direction){
    if(!root) return nullptr;

    if(direction == "left"){
        if(root->left && IsLeaf(root->left)) return root->left ; 
        else{
            return GetLeaf(root->left , "left") ; 
        } 
    }
    else if(direction == "right"){
        if(root->left && IsLeaf(root->right)) return root->right ; 
        else{
            return GetLeaf(root->right, "right") ; 
        }
    }
    return root ; 
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
        ToDelete = nullptr  ; 
        Parent->left = nullptr ; 
        return ; 
    }else if (IsLeaf(ToDelete)&&Parent->right== ToDelete){
        delete ToDelete ; 
        ToDelete = nullptr  ; 
        ToDelete->right= nullptr; 
        return ;
    }

    if(Parent->left == ToDelete){
        TreeNode* DeleteRight = ToDelete->right ; 
        TreeNode* DeleteLeft = ToDelete->left ; 

        Parent->left = DeleteRight ; 
        TreeNode * LeftLeaf = GetLeaf(DeleteRight , "left") ; 
        LeftLeaf ->left  = DeleteLeft ;
        delete ToDelete ; 
        ToDelete = nullptr ;  

    }else{
        TreeNode* DeleteRight = ToDelete->right ; 
        TreeNode* DeleteLeft = ToDelete->left ; 
        Parent->left = DeleteRight ; 

        TreeNode* LeftLeaf = GetLeaf(DeleteRight , "left") ;
        LeftLeaf->left = DeleteLeft ; 
        delete ToDelete  ; 
        ToDelete = nullptr ;  
    }
}

std::vector<int> BST::BstToVec(TreeNode* root) {
    std::vector<int> vec;

    if (!root) {
        return vec; // Return an empty vector if the root is nullptr
    }

    // Traverse left subtree
    std::vector<int> leftValues = BstToVec(root->left);
    vec.insert(vec.end(), leftValues.begin(), leftValues.end());

    // Add current node's value
    vec.push_back(root->val);

    // Traverse right subtree
    std::vector<int> rightValues = BstToVec(root->right);
    vec.insert(vec.end(), rightValues.begin(), rightValues.end());

    return vec;
}

std::vector<int> BST::DebugSorted(std::vector<int>&v){
    std::set<int>check ; 
    for(auto i : v){
        check.insert(i) ; 
    }
    v.assign(check.begin() , check.end()) ; 
    return v; 
}

bool BST::DebugCheckTree(std::vector<int>&v){
    std::vector<int>vec1 = v ; 
    std::vector<int>vec2 = DebugSorted(v) ; 
    return vec1.size() == vec2.size() ; 
}

bool BST::CheckTree(){
    std::vector<int> check = BstToVec(root) ;  
    return DebugCheckTree(check)  ; 
}