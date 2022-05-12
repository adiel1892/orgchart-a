
#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include "Node.hpp"
#include <queue>
using namespace std;
namespace ariel{
    class OrgChart{
    public:
    Node *root;
    OrgChart(){
        this->root = nullptr;
    }
    OrgChart &add_root(const string & job){
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
    // adding a node to a father node
    OrgChart &add_sub(const string &father, const string &son){
        Node* dad =  searchNode(father);
        if(dad == nullptr){
            throw invalid_argument("Can't add sub to Null");
        }
        dad->subs.push_back(new Node(son));
        return *this;
    }
    // finding the node by level order the organization
    Node* searchNode(const string & job){
        if(this->root == nullptr){
            throw invalid_argument("There is not a root for this organization");
        }
        std::queue<Node*> helper; 
        helper.push(this->root);
        while(!helper.empty()){
            int times = helper.size();
            while(times > 0){
                Node* tmp = helper.front();
                // we found our node
                if(tmp->job == job){
                    return tmp;
                }
                helper.pop();
                for(unsigned int i = 0; i < tmp->subs.size(); i++){
                    helper.push(tmp->subs.at(i));
                }
            }
        }
        return nullptr;
    }

    friend ostream & operator<<(ostream& out , const OrgChart &org){
        return out;
    }
    class iterator{
        private:
        vector<Node*> nodes;
        Node* currNode;
        public:
        iterator(Node* node , const string &way){
            // this->currNode = node;
            // if(node != nullptr){
            //     nodes.push_back(node);
            // }
            if(way == "begin_level_order"){
                iter_begin_level_order(node);
            }
            if(way == "begin_reverse_order"){

            }
            if(way == "begin_preorder"){

            }
        }

        void iter_begin_level_order(Node *node){
            cout << "got here" << endl;
            std::queue<Node*> helper; 
            helper.push(node);
            while(!helper.empty()){
                int times = helper.size();
                while(times > 0){
                    Node* tmp = helper.front();
                    helper.pop();
                    for(unsigned int i = 0; i < tmp->subs.size(); i++){
                        helper.push(tmp->subs.at(i));
                        this->nodes.push_back(tmp->subs.at(i));
                    }
                }
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

    iterator begin_level_order()const{
        return iterator(root , "begin_level_order");
    }
    static iterator end_level_order(){
        return iterator(nullptr , "end_level_order");
    }
    iterator begin_reverse_order()const{
        return iterator(root , "begin_reverse_order");
    }
    static iterator reverse_order(){
        return iterator(nullptr , "reverse_order");
    }
    iterator begin_preorder()const{
        return iterator(root , "begin_preorder");
    }
    static iterator end_preorder(){
        return iterator(nullptr , "end_preorder");
    }
    };
}
