using namespace std;
#include <string>
#include <vector>
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