#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>

class Node
{
public:
  int32_t value;
  Node *left;
  Node *right;

    Node (int32_t value)
  {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  friend std::ostream& operator<< (std::ostream & cout, const Node& node);
};

std::ostream& operator<<(std::ostream& cout, const Node& node)
{
    cout << "Node value -> " << std::to_string(node.value) << std::endl;
    return cout;
}

int32_t treeMin(const Node* root)
{
    if(root == nullptr) return INT_MAX;
    int32_t result = root->value;
    return std::min( std::min( treeMin(root->left), treeMin(root->right) ), root->value);
}

int32_t treeMinIt(const Node* root)
{ 
    if(root == nullptr) return INT_MAX;
    
    std::stack<const Node*> stack;
    stack.push(root);
    int32_t result = INT_MAX;
    
    while(!stack.empty())
    {
        const Node* node = stack.top();
        stack.pop();
        
        if(node->value < result)
            result= node->value;
        
        if(node->right != nullptr) stack.push(node->right);
        if(node->left != nullptr)  stack.push(node->left);
    }
    
    return result;
}

int main ()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(-4);
    Node* n3 = new Node(34);
    Node* n4 = new Node(67);
    Node* n5 = new Node(32);
    Node* n6 = new Node(-44);
    
    n1->left = n2;
    n1->right = n5;
    n2->left = n3;
    n2->right = n4;
    n5->right = n6;

    int32_t min;
    int32_t min2;
    
    min = treeMin(n1);
    
    std::cout << "min: " <<std::to_string(min) << std::endl;
    
    min2 = treeMinIt(n1);
    
    std::cout << "min2: " <<std::to_string(min2) << std::endl;

    return 0;
}






