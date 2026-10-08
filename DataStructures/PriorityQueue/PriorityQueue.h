// I had implemented Priority Queue by Binary Tree
// But i soon realized that it was really difficult for me to push and  pop


#include <vector>
using namespace std;

class PriorityQueue{

    private:
        vector<int> heap;

    public:
        PriorityQueue();
        ~PriorityQueue();

        void Push(int);
        void Pop();

        int Top();
        bool Empty();
        int Size();
        void Show();
};