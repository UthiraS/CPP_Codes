#include<iostream>
#include<algorithm>





























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