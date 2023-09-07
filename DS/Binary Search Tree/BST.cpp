#include "BST.hpp"

BST::BST() {
    root = nullptr;
}

BST::BST(int data) : root(new TreeNode(data)) {}

BST::~BST() {
    deleteTree(root);
}

void BST::deleteTree(TreeNode* node) {
    if (!node) return;
    if (node->left)
        deleteTree(node->left);
    if (node->right)
        deleteTree(node->right);
    delete node;
}

void BST::insert(TreeNode* root, int val) {
    if (val < root->val) {
        if (!root->left)
            root->left = new TreeNode(val);
        else
            insert(root->left, val);
    }
    else if (val > root->val) { 
        if (!root->right)
            root->right = new TreeNode(val);
        else
            insert(root->right, val);
    }
}

void BST::insert(int target) {
    insert(root, target);
}

void BST::inorder_print(TreeNode* root) {
    if (!root)
        return;
    int value = root->val;
    inorder_print(root->left);
    std::cout << value << '\t';
    inorder_print(root->right);
}

void BST::print() {
    inorder_print(root);
    if(!CheckTree())
        {
            std::cout<<"Tree is not valid check the tree values again!!" ; 
            return ; 
        }
    std::cout << '\n';
}

std::pair<TreeNode*, bool> BST::search(TreeNode* root, int target) {
    if (!root) {
        return { nullptr, false };
    }

    int value = root->val;
  
    if (value == target) {
        return { root, true };
    }
    else if (value < target) {
        return search(root->right, target);
    }
    else {
        return search(root->left, target);
    }
}


bool BST::search(int target) {
    auto answer = search(root, target);
    return answer.second;
}

//--------------------------UTILITY Functions-----------------------------//
TreeNode* BST::GetParent(TreeNode* root, TreeNode* ToDelete) {
    if (!root) return nullptr; // Node not found, return nullptr
    if (ToDelete == root) {
        std::cout << "You are trying to get the parent of the ROOT ! :)\n";
        return nullptr; // Node is the root, so it has no parent
    }
    
    // Check the left subtree
    if ((root->left) && (root->left == ToDelete)) {
        return root;
    }

    // Check the right subtree
    if ((root->right) && (root->right == ToDelete)) {
        return root;
    }

    // If the node wasn't found in the current subtree, recursively search both subtrees
    TreeNode* leftParent = GetParent(root->left, ToDelete);
    if (leftParent) {
        return leftParent; // Found in the left subtree
    }
    
    return GetParent(root->right, ToDelete); // Check the right subtree
}

void  BST::link(TreeNode* parent, TreeNode* child, const std::string& direction) {
    if (direction == "left") {
        parent->left = child;
    }
    else if (direction == "right") {
        parent->right = child;
    }
    else {
        std::cerr << "Invalid Direction\n";
    }
}

bool BST::IsLeaf(TreeNode* node) {
    if (node && !node->left && !node->right)
        return true;
    return false;
}

TreeNode* BST::getLeaf(TreeNode* root, const std::string& direction) {
    TreeNode* curr = root;
    if (direction == "left") {
        while (curr && curr->left) {
            curr = curr->left;
        }
    }
    else if (direction == "right") {
        while (curr && curr->right) {
            curr = curr->right; 
        }
    }
    return curr; 
}

std::vector<int> BST:: BstToVec(TreeNode* root) {
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

std::vector<int> BST::DebugSorted(std::vector<int>& v) {
    std::set<int>check;
    for (auto i : v) {
        check.insert(i);
    }
    v.assign(check.begin(), check.end());
    return v;
}

bool BST::DebugCheckTree(std::vector<int>& v) {
    std::vector<int>vec1 = v;
    std::vector<int>vec2 = DebugSorted(v);
    return vec1.size() == vec2.size();
}

bool BST::CheckTree() {
    auto check = BstToVec(root);
    return DebugCheckTree(check);
}

// Getting the minimum Value starting from a certain Node !!
int BST::minValue(TreeNode* root) {
    TreeNode* MIN = getLeaf(root, "left"); 
    int value = MIN->val; 
    return value; 
}

int BST::minValue() {
    return minValue(root); 
}

int BST::maxValue() {
    TreeNode* MAX = getLeaf(root, "right"); 
    int value = MAX->val; 
    return value; 
}

int BST::GetParent(int target) {
    auto answer = search(root, target); 
    TreeNode* curr = GetParent(root , answer.first);
    return curr->val; 
}

int BST::GetChild(int target, const std::string& direction) {
    auto node = search(root, target).first;
    if (IsLeaf(node)) return -1; 
    
    if (direction == "left") {
        assert(node->left); 
        return node->left->val; 
    }
    else if (direction == "right") {
        assert(node->right); 
        return node->right->val; 
    }
    return -1 ; 
}


TreeNode* BST::getNext(std::vector<TreeNode*>& ancsector) {
    if(ancsector.size() == 0)
        return nullptr;
    TreeNode* child = ancsector.back(); 
    ancsector.pop_back(); 
    return child;
}

bool BST::FindChain(TreeNode* root , int target , std::vector<TreeNode*>&ancestor){
    ancestor.push_back(root);
    if (target == root->val)
        return true;
    if (target < root->val)
        return FindChain(root->left, target, ancestor);
    return root->right && FindChain(root->right, target, ancestor);
}


std::pair<bool ,int> BST::successor(int target){
    std::vector<TreeNode*>ancestor  ; 
    if(!FindChain(root , target , ancestor))
        return std::make_pair(false , -1) ;
    TreeNode* child = getNext(ancestor) ; 
    if(child->right)
        return std::make_pair(true,minValue(child->right)) ; 
    TreeNode* parent = getNext(ancestor) ; 
    while(parent && parent->right == child)
        {
            child = parent ; 
            parent = getNext(ancestor) ;
        }

    if(parent)
        return std::make_pair(true , parent->val) ; 
    return std::make_pair(false , -1) ; 
}


TreeNode* BST::DeleteNode(TreeNode* root, int target) {
    // Step 1: Find the node to delete (ToDelete) using GetNode function
    TreeNode* ToDelete = GetNode(root, target);

    if (!ToDelete) {
        // Node with the target value not found, nothing to delete
        return root;
    }

    // Step 2: Store a temporary pointer to the node to delete
    TreeNode* temp = ToDelete;

    // Step 3: Handle different cases for node deletion
    if (!ToDelete->right && !ToDelete->left) {
        // Case 1: Node has no children (leaf node)
        delete ToDelete;
        ToDelete = nullptr;
    } else if (!ToDelete->right) {
        // Case 2: Node has only a left child
        ToDelete = ToDelete->left;
        delete temp;
        temp = nullptr;
    } else if (!ToDelete->left) {
        // Case 3: Node has only a right child
        ToDelete = ToDelete->right;
        delete temp;
        temp = nullptr;
    } else {
        // Case 4: Node has two children
        // Find the minimum value in the right subtree
        ToDelete->val = minValue(ToDelete->right);
        // Recursively delete the successor node from the right subtree
        ToDelete->right = DeleteNode(ToDelete->right, ToDelete->val);
        delete temp;
        temp = nullptr;
    }

    // Step 4: Return the updated root of the tree
    if (temp == root) {
        return ToDelete;  // Return the new root if the root itself was deleted
    } else {
        return root;      // Return the original root if a non-root node was deleted
    }
}


TreeNode* BST::GetNode(TreeNode*root , int target){
   if(!root)
    return nullptr ; 
    int value = root->val ; 
    if(target ==  value)
        return root ; 
    if(target < value)
        return GetNode(root->left , target)  ; 
    return GetNode(root->right , target )  ; 
}

void BST::Delete(int target){
    DeleteNode(root,target) ; 
}