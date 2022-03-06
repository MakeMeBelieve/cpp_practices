#include <iostream>
#include <stack>

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

int32_t treeSum(const Node* root)
{
    if(root == nullptr) return 0;
    return treeSum(root->left) + treeSum(root->right) + root->value;
}

int32_t treeSum2(const Node* root)
{
    if(root == nullptr) return 0;
    
    std::stack<const Node*> stack;
    stack.push(root);
    int32_t result = 0;
    
    while(!stack.empty())
    {
        const Node* node = stack.top();
        stack.pop();
        
        result += node->value;
        
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

    int32_t sum;
    int32_t sum2;
    
    sum = treeSum(n1);
    
    std::cout << "sum: " <<std::to_string(sum) << std::endl;
    
    sum2 = treeSum2(n1);
    
    std::cout << "sum2: " <<std::to_string(sum2) << std::endl;

    return 0;
}






