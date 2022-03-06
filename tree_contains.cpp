#include <iostream>
#include <stack>
#include <list>
#include <queue>

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

bool contains(Node* root,const std::string& target)
{
    if(root == nullptr) return false;
    
    std::queue<Node*> nodes;
    nodes.push(root);
    
    while(!nodes.empty())
    {
        Node* node = nodes.front();
        nodes.pop();
        
        if(node->left != nullptr) nodes.push(node->left);
        if(node->right != nullptr) nodes.push(node->right);
        
        if(node->text.compare(target) == 0)
        {
            return true;
        }
    }

    return false;
}

bool constainsRecursive(Node* root, const std::string& target)
{
    if(root == nullptr) return false;
    if(root->text.compare(target) == 0) return true;
    return constainsRecursive(root->left, target) || constainsRecursive(root->right, target);
}

int main()
{
    Node* n1 = new Node("node 1 text");
    Node* n2 = new Node("node 2 text");
    Node* n3 = new Node("node 3 text");
    Node* n4 = new Node("node 4 text");
    Node* n5 = new Node("Hello2");
    Node* n6 = new Node("node 6 text");
    
    n1->left = n2;
    n1->right = n5;
    n5->right = n6;
    n2->left = n3;
    n2->right = n4;
    
    std::string word = "Hello";
    
    bool result = contains(n1, word);

    if(result)
    {
        std::cout << "\"" + word + "\" is exist." << std::endl;
    }
    else
    {
        std::cout << "\"" + word + "\" is absent!" << std::endl;
    }
    
    result = constainsRecursive(n1, word);

    if(result)
    {
        std::cout << "\"" + word + "\" is exist." << std::endl;
    }
    else
    {
        std::cout << "\"" + word + "\" is absent!" << std::endl;
    }

    return 0;
}