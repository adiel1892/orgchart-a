using namespace std;
namespace ariel{
    template <typename T>
    class OrgChart{
        struct Block{
            T data;
            Block *right;
            Block *left;
            Block *up;
            Block *down;
            Block(const T &data) : data(data) ,right(nullptr) , left(nullptr) , up(nullptr) , down(nullptr){};
        };
        private:
            Block *root;
        public:
            OrgChart() : root(nullptr){};
            ~OrgChart();
            OrgChart add_root(T &data);
            OrgChart add_sub(T &father, T &son);
            class auto{

                public:
                    auto begin_level_order();
                    auto end_level_order();
                    auto begin_reverse_order();
                    auto reverse_order();
                    auto begin_preorder();
                    auto end_preorder();
            }
    };
}