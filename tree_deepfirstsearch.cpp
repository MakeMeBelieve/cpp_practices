#include <iostream>
#include <stack>
#include <vector>
#include <list>

class Node
{
    public:
    
    char value;
    Node* left;
    Node* right;
    
    Node(char value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    friend std::ostream& operator<<(std::ostream& cout,const Node& node);

};

std::ostream& operator<<(std::ostream& cout,const Node& node)
{
    std::string str(" ");
    
    str += "left: ";
    
    if(node.left == nullptr)
    {
        str += "nullptr";
    }
    else
    {
        str += node.left->value;
    }
    
    
    str += " right: ";
    
    if(node.right == nullptr)
    {
        str += "nullptr";
    }
    else
    {
        str += node.right->value;
    }
    
    std::cout << "value :" << node.value << str << std::endl;
    
    return cout;
}


void deepFirstStack(Node* root, std::list<Node*>& list)
{
    if(root == nullptr) return;
    
    std::stack<Node*> stack;
    stack.push(root);
    
    while(!stack.empty())
    {
        Node* node = stack.top();
        stack.pop();
        
        if(node->right != nullptr) stack.push(node->right);
        if(node->left != nullptr)  stack.push(node->left);
        
        //debug
        //std::cout << *node << std::endl;
        
        list.emplace_back(node);
    }
    
}

void deepFirstRecursive(Node* root, std::list<Node*>& list)
{
    if(root == nullptr) return;
    
    list.emplace_back(root);
    
    if(root->left != nullptr) deepFirstRecursive(root->left, list);
    if(root->right != nullptr) deepFirstRecursive(root->right, list);
}

int main()
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');
    
    a->left = b;
    a->right = e;
    b->left = c;
    b->right = d;
    e->right = f;

    // deepFirstStack
    
    std::cout << "deepFirstStack" << std::endl;
    
    std::list<Node*> deepFirstStackList;
    
    deepFirstStack(a, deepFirstStackList);
    
    if(!deepFirstStackList.empty())
    {
        for(auto it : deepFirstStackList)
        {
            std::cout << *it << std::endl;
        }
    }
    
    
    // deepFirstRecursive
    
    std::cout << "deepFirstRecursive" << std::endl;
    
    std::list<Node*> deepFirstRecursiveList;
    
    deepFirstRecursive(a, deepFirstRecursiveList);
    
    if(!deepFirstRecursiveList.empty())
    {
        for(auto it : deepFirstRecursiveList)
        {
            std::cout << *it << std::endl;
        }
    }

    return 0;
}










