
#include<iostream>
#include<vector>
#include<queue>

class node
{
    // defines and represents one rigidbody
    // can be created programmatically or via parsing an xml file
    public:
    node *parent;
    // node **children;
    std::vector<node*> children;

    double mass;
    double Ixx;
    double Iyy;
    double Izz;

    double gravity = 9.81;
    
    
    
    public:
    std::vector<node*> getChildrenNodes();
    node* getParent();
    void visualize(node* n);

    node(double mass, double Ixx, double Iyy, double Izz);

    double frameLocWRTparent[3]{0.1, 0.0, 0.0};
    double COM[3]{0.0, 0,0.0};
};

node::node(double mass, double ixx, double iyy, double izz)
{
    // std::cout<<"mass"<<mass<<std::endl;
    this->mass = mass;
    this->Ixx = ixx;
    this->Iyy = iyy;
    this->Izz = izz;
}

std::vector<node*> node::getChildrenNodes()
{
    return this->children;
}

node* node::getParent()
{
    return this->parent;
}

void node::visualize(node* n)
{
//   Printing from parent to child in level wise
    std::queue<node*> current;
    current.push(n);
    while (!current.empty()) {
        node* root = current.front();
        current.pop();
        std::cout << "[" << root->mass << ", " << root->Ixx << ", " << root->Iyy << ", " << root->Izz << "] -> "; 
        


        for(auto& child:root->children)
        {
            if (child != nullptr)
            {
                current.push(child);
                std::cout << "[" << child->mass << ", " << child->Ixx << ", " << child->Iyy << ", " << child->Izz << "] ";
            }
        }
         std::cout << std::endl;
    }
    
    
}

node* maketree()
{
    // lets create parent node
    node* n = new node(0.1, 0.01,0,0);
    
    n->parent = nullptr;
    
    // lets create a child
    node* child1 = new node(0.2, 0.3,0,0);
    node* child2 = new node(0.3, 0.01,0,0);

    child1->parent = n;
    child2->parent = n;

    n->children.push_back(child1);
    n->children.push_back(child2);

    node* grandchild1 = new node(0.005, 0.00006,0,0);
    grandchild1->parent = child1;
    child1->children.push_back(grandchild1);

    node* grandchild2 = new node(0.007, 0.00006,0,0);
    grandchild2->parent = child2;
    child2->children.push_back(grandchild2);

    n->visualize(n);
    return n;
}



int main()
{
    //make a tree, populate and visualize using queue , we want to visualize something similar to level order 
    node* root = maketree();
    

}
