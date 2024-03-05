#include<iostream>
#include<vector>
#include<array>
#include<queue>
class Node 
{
   public:   
   Node* left;
   Node* right;
   double data;

  public: 
    Node(double d)
    {
        right = nullptr;
        left = nullptr;
        this->data = d;

    }
};

class binaryTree
{

    private:
     Node* root;
    //  int depth;
     int count;
    public:

    binaryTree();
    // Inserting an element.
    void insert(double d);

    // Removing an element.
    bool remove(double d);

    // Return the root node
    Node * get_root();

    // Searching for an element, returns if a value is present or not
    int search(Node* root, double d);

    // Traversing the tree.
    void inorder_traversal(Node* root);
    void preorder_traversal(Node* root);
    void postorder_traversal(Node* root);


    // Finding the height of the tree
    int heightTree(Node* root);
    // Find the level of a node of the tree
    int levelTree(Node* node, double data, int level);

    // Finding the size of the entire tree.
    int sizeTree();

    

};

binaryTree::binaryTree()
{
  this->root = nullptr;
  count = 0;
}

int binaryTree::sizeTree()
{
    return count;
}


Node* binaryTree::get_root()
{
    return this->root;
}
void binaryTree::insert(double d)
{
    Node *newNode = new Node(d);
    Node* current = this->root;
    // first verison of code
    // i have just taken into consideration of current child 
    // which means that the level of insertion is not uniform

    //    It does not ensure that nodes are inserted at the correct level. A node could be inserted into a deeper part of the tree even when there are available spots at higher levels.
    // It moves to the right child if both children of the current node are occupied but doesn't properly navigate the entire tree to find the next available spot.


    // while(current!= nullptr)
    // {
    //  if(current->left== nullptr)
    //  {
    //    current->left = newNode;
    //    std::cout<<" left is inserted"<<std::endl;
    //    break;

    //  }
    //  else
    //  if(current->right== nullptr)
    //  {
    //     current->right = newNode;
    //     std::cout<<" right is inserted"<<std::endl;
    //     break;
    //  }
    //  else
    //  if(current->left!= nullptr)
    //  {
    //     current = current->right;
    //  }
    //  else
    //  if(current->right!= nullptr)
    //  {
    //     current = current->left;
    //  }

    // }
    
    // if(this->root == nullptr)
    // {
    //     this->root = newNode;
    //     this->root->left = nullptr;
    //     this->root->right = nullptr;
    //     std::cout<<" root is inserted"<<std::endl;
    // }



    // using queue based insertion  method

    
if (this->root == nullptr) {
        this->root = newNode;
        std::cout << "Root is inserted" << std::endl;
    } else {
        std::queue<Node*> q;
        q.push(this->root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->left == nullptr) {
                temp->left = newNode;
                std::cout << "Left is inserted" << std::endl;
                break;
            } else {
                q.push(temp->left);
            }
            if (temp->right == nullptr) {
                temp->right = newNode;
                std::cout << "Right is inserted" << std::endl;
                break;
            } else {
                q.push(temp->right);
            }
        }
    }
 count++;
}
int binaryTree::heightTree(Node* node) {
    if (node == nullptr) {
        // The height of an empty tree is -1 and height of a leaf node is 0.
        return -1;
    } else {
        // Compute the height of each subtree.
        int leftHeight = heightTree(node->left);
        int rightHeight = heightTree(node->right);

        // Return the larger of the two heights plus one.
        return std::max(leftHeight, rightHeight) + 1;
    }
}


int binaryTree::levelTree(Node* node, double data, int level = 0) {
    if (node == nullptr) {
        // If the node doesn't exist, return -1 or some indication that the node wasn't found.
        return -1;
    }
    if (node->data == data) {
        // If the current node is the one we're looking for, return its level.
        return level;
    } else {
        // First check in the left subtree.
        int leftLevel = levelTree(node->left, data, level + 1);
        if (leftLevel != -1) {
            // If found in the left subtree, return the level.
            return leftLevel;
        }
        // Check in the right subtree.
        return levelTree(node->right, data, level + 1);
    }
}

// bool binaryTree::remove(double d)
// {
//   while(root!= NULL)
//     {
     

//     }
    
//     count--;

// }

void binaryTree::preorder_traversal(Node* ro)
{
   if (ro == NULL)
        return;
    std::cout<<ro->data<<",";
    preorder_traversal(ro->left);
    preorder_traversal(ro->right);
    
    


}

void binaryTree::inorder_traversal(Node* ro)
{
   if (ro == NULL)
        return;
    
    inorder_traversal(ro->left);
    std::cout<<ro->data<<",";
    inorder_traversal(ro->right);
    
    


}
void binaryTree::postorder_traversal(Node* ro)
{
   if (ro == NULL)
        return;
    
    postorder_traversal(ro->left);    
    postorder_traversal(ro->right);
    std::cout<<ro->data<<",";
    


}


int binaryTree::search(Node* node,double d)
{
   if (node == nullptr) {
        // If the node doesn't exist, return -1 or some indication that the node wasn't found.
        return -1;
    }
    if (node->data == d) {
        // If the current node is the one we're looking for, return its level.
        return 1;
    } else {
        // First check in the left subtree.
        int leftS = search(node->left, d);
        int rightS = search(node->right, d);
        if (leftS != -1) {
            // If found in the left subtree, return the level.
            return leftS;
        }
        // Check in the right subtree.
        else
        if (rightS != -1) {
            // If found in the left subtree, return the level.
            return rightS;
        }
    }


}

// std::vector<int> binaryTree::preorder_traversal_1()
// {

//     std::vector<int> result ={};
//     Node* current = this->root;
//     Node* previous = nullptr;
//     if(root == nullptr)
//     {
//       return result;
//     }
//     else
//     if((root->left== nullptr)&&(root->right== nullptr))
//     {
//         result.push_back(root->data);
//         return result;
//     }
//     else
//     {
//       result.push_back(current->data);
//       previous = current;
//       current= current->left;
      
//      do
//      {
        
//         while(current->left!=nullptr)
//         {
//             result.push_back(current->data);
//             previous = current;
//             current= current->left;
//         }
//         if(current->left==nullptr)
//         {
//             result.push_back(current->data);
//             current= previous->right;
//         }
//       } while (current!= root);
     
//     }
//     return result;

// }
int main()
{
    binaryTree bT = binaryTree();
    bT.insert(11);
    bT.insert(2);
    bT.insert(30);
    bT.insert(4);
    bT.insert(15);
    bT.insert(6);
    bT.insert(7);
    std::cout<<"Count :"<<bT.sizeTree()<<std::endl;
    std::cout<<"Pre order traversal tree :"<<std::endl;
    bT.preorder_traversal(bT.get_root());
    std::cout<<std::endl;
    std::cout<<"In order traversal tree :"<<std::endl;
    bT.inorder_traversal(bT.get_root());
    std::cout<<std::endl;
    std::cout<<"Post order traversal tree :"<<std::endl;
    bT.postorder_traversal(bT.get_root());
    std::cout<<std::endl;
    int result1 =  bT.search(bT.get_root(),11);
    
    if(result1 == -1)
    {
        std::cout<<"Value Not found in tree :"<<std::endl;
    }
    else
    if(result1 == 1)
    {
        std::cout<<"Value  found in tree :"<<std::endl;
    }
    int result2 =  bT.search(bT.get_root(),100);
    if(result2 == -1)
    {
        std::cout<<"Value Not found in tree :"<<std::endl;
    }
    else
    if(result2 == 1)
    {
        std::cout<<"Value  found in tree :"<<std::endl;
    }


}
