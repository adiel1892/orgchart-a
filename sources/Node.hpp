#include <string>
#include <vector>
using namespace std;
class Node{
    public:
    string job;
    vector<Node*> subs;
    Node(const string & job){
        this->job = job;
    }
    ~Node(){

    }
};