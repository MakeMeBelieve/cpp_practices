#include <iostream>
#include <stack>
#include <list>

class Node 
{
    public:
    
    std::string text;
    Node* left;
    Node* right;
    
    Node(std::string text)
    {
        this->text = text;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    friend std::ostream& operator<<(std::ostream& cout, const Node& node);

};

std::ostream& operator<<(std::ostream& cout, const Node& node)
{
    std::cout << "value: " << node.text << std::endl;
    return cout;
}


void deepFirst(Node* root, std::list<Node*>& list)
{
    std::stack<Node*> stack;
    stack.push(root);
    
    while(!stack.empty())
    {
        Node* node = stack.top();
        stack.pop();
        
        if(node->right != nullptr) stack.push(node->right);
        if(node->left != nullptr)  stack.push(node->left);
        
        list.emplace_back(node);
    }
}


int main()
{
    Node* n1 = new Node("node1");
    Node* n2 = new Node("node2");
    Node* n3 = new Node("node3");
    Node* n4 = new Node("node4");
    Node* n5 = new Node("node5");
    Node* n6 = new Node("node6");
    
    n1->left = n2;
    n1->right = n5;
    n2->left = n3;
    n2->right = n4;
    n5->right = n6;
    
    std::list<Node*> list;
    
    deepFirst(n1, list);
    
    for(auto it: list)
    {
        std::cout << *it << std::endl;
    }
    

    return 0;
}









