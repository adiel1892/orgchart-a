
#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include "Node.hpp"
namespace ariel{
    class OrgChart{
    public:
    Node *root;
    OrgChart(){
        this->root = nullptr;
    }
    OrgChart &add_root(const std::string & job){
        if(this->root == nullptr){
            this->root = new Node(job);
        }else{
            // there is already root so well make a new root and point the new root to the old root
            Node *newRoot = new Node(job);
            newRoot->subs.push_back(this->root);
            this->root = newRoot;
        }
        return *this;
    }
    OrgChart &add_sub(const std::string &father, const std::string &son){
        return *this;

    }
    Node* searchNode(const string &job){
        if(this->root->job == job){
            return this->root;
        }
        return this->root;
    }
    friend std::ostream & operator<<(std::ostream& out , const OrgChart &org){
        return out;
    }
    class iterator{
        private:
        vector<Node*> nodes;
        Node* currNode;
        public:
        iterator(Node* node , const string &way){
            this->currNode = node;
            if(node != nullptr){
                nodes.push_back(node);
            }
        }
        string* operator->(){
            return &this->currNode->job;
        }
        bool operator!=(const iterator &other){
            return false;
        }
        string operator*(){
             return "orgchart-a";
        }
        iterator operator++(){
            return *this;
        }
    };

    iterator begin_level_order(){
        return iterator(root , "begin_level_order");
    }
    iterator end_level_order(){
        return iterator(nullptr , "end_level_order");
    }
    iterator begin_reverse_order(){
        return iterator(root , "begin_reverse_order");
    }
    iterator reverse_order(){
        return iterator(nullptr , "reverse_order");
    }
    iterator begin_preorder(){
        return iterator(root , "begin_preorder");
    }
    iterator end_preorder(){
        return iterator(nullptr , "end_preorder");
    }
    };
}
