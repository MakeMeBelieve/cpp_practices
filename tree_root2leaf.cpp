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

int32_t maxPathSum(const Node* root)
{
    if(root == nullptr) return INT_MIN;
    if(root->left == nullptr && root->right == nullptr) return root->value;
    return std::max(maxPathSum(root->left),maxPathSum(root->right)) + root->value;
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

    int32_t result;
    
    result = maxPathSum(n1);
    
    std::cout << "MaxPathSum: " << std::to_string(result) << std::endl;

    return 0;
}








