#include "BST.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <functional>

using namespace std;

static int passed = 0, failed = 0;

#define CHECK(cond, name)                                  \
    do {                                                   \
        if (cond) { ++passed; cout << "[PASS] " << name << "\n"; } \
        else      { ++failed; cout << "[FAIL] " << name << "  (line " << __LINE__ << ")\n"; } \
    } while (0)

vector<int> capture(function<void()> fn) {
    stringstream buf;
    streambuf* old = cout.rdbuf(buf.rdbuf());
    fn();
    cout.rdbuf(old);

    string s = buf.str();
    vector<int> res;
    for (size_t i = 0; i < s.size();) {
        bool neg = (s[i] == '-' && i + 1 < s.size() && isdigit(s[i + 1]));
        if (isdigit(s[i]) || neg) {
            size_t j = neg ? i + 1 : i;
            int v = 0;
            while (j < s.size() && isdigit(s[j])) v = v * 10 + (s[j++] - '0');
            res.push_back(neg ? -v : v);
            i = j;
        } else ++i;
    }
    return res;
}

void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

bool checkTraversal(BST& t, const vector<int>& pre, const vector<int>& in, const vector<int>& post) {
    vector<int> a = capture([&] { t.Preorder_Show(); });
    vector<int> b = capture([&] { t.Inorder_Show(); });
    vector<int> c = capture([&] { t.Postorder_Show(); });
    bool ok = (a == pre && b == in && c == post);
    if (!ok) {
        cout << "  Preorder  got: ";  printVec(a);
        cout << "  Preorder  exp: ";  printVec(pre);
        cout << "  Inorder   got: ";  printVec(b);
        cout << "  Inorder   exp: ";  printVec(in);
        cout << "  Postorder got: ";  printVec(c);
        cout << "  Postorder exp: ";  printVec(post);
    }
    return ok;
}

int main() {
    cout << "=== Empty tree ===\n";
    {
        BST t;
        CHECK(t.Empty(), "new tree is empty");
        CHECK(t.Size() == 0, "new tree size == 0");
        CHECK(!t.Search(5), "search on empty tree -> false");
        CHECK(capture([&] { t.Inorder_Show(); }).empty(), "inorder on empty prints nothing");
        t.Delete(5);
        CHECK(t.Size() == 0 && t.Empty(), "delete on empty tree does nothing");
    }

    cout << "\n=== Insert + Traversal ===\n";
    BST t;
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    for (int v : vals) t.Insert(v);

    CHECK(!t.Empty(), "not empty after insert");
    CHECK(t.Size() == 10, "size == 10");
    CHECK(checkTraversal(t,
        {50, 30, 20, 40, 35, 45, 70, 60, 65, 80},
        {20, 30, 35, 40, 45, 50, 60, 65, 70, 80},
        {20, 35, 45, 40, 30, 65, 60, 80, 70, 50}),
        "traversals after insert");

    cout << "\n=== Search ===\n";
    for (int v : vals) CHECK(t.Search(v), "search existing " + to_string(v));
    CHECK(!t.Search(0), "search 0 -> false");
    CHECK(!t.Search(55), "search 55 -> false");
    CHECK(!t.Search(100), "search 100 -> false");

    cout << "\n=== Delete leaf (20) ===\n";
    t.Delete(20);
    CHECK(t.Size() == 9, "size == 9");
    CHECK(!t.Search(20), "20 gone");
    CHECK(checkTraversal(t,
        {50, 30, 40, 35, 45, 70, 60, 65, 80},
        {30, 35, 40, 45, 50, 60, 65, 70, 80},
        {35, 45, 40, 30, 65, 60, 80, 70, 50}),
        "traversals after delete 20");

    cout << "\n=== Delete node with 1 child (60) ===\n";
    t.Delete(60);
    CHECK(t.Size() == 8, "size == 8");
    CHECK(!t.Search(60) && t.Search(65), "60 gone, 65 still there");
    CHECK(checkTraversal(t,
        {50, 30, 40, 35, 45, 70, 65, 80},
        {30, 35, 40, 45, 50, 65, 70, 80},
        {35, 45, 40, 30, 65, 80, 70, 50}),
        "traversals after delete 60");

    cout << "\n=== Delete node with 2 children (40) ===\n";
    t.Delete(40);
    CHECK(t.Size() == 7, "size == 7");
    CHECK(!t.Search(40) && t.Search(35) && t.Search(45), "40 gone, children kept");
    CHECK(checkTraversal(t,
        {50, 30, 45, 35, 70, 65, 80},
        {30, 35, 45, 50, 65, 70, 80},
        {35, 45, 30, 65, 80, 70, 50}),
        "traversals after delete 40");

    cout << "\n=== Delete root (50) ===\n";
    t.Delete(50);
    CHECK(t.Size() == 6, "size == 6");
    CHECK(!t.Search(50), "50 gone");
    CHECK(checkTraversal(t,
        {65, 30, 45, 35, 70, 80},
        {30, 35, 45, 65, 70, 80},
        {35, 45, 30, 80, 70, 65}),
        "traversals after delete root");

    cout << "\n=== Delete non-existent ===\n";
    t.Delete(999);
    CHECK(t.Size() == 6, "size unchanged after deleting 999");
    CHECK(checkTraversal(t,
        {65, 30, 45, 35, 70, 80},
        {30, 35, 45, 65, 70, 80},
        {35, 45, 30, 80, 70, 65}),
        "tree unchanged after deleting 999");

    cout << "\n=== Delete everything ===\n";
    int rest[] = {30, 35, 45, 65, 70, 80};
    for (int v : rest) t.Delete(v);
    CHECK(t.Empty(), "empty after deleting all");
    CHECK(t.Size() == 0, "size == 0 after deleting all");
    CHECK(capture([&] { t.Inorder_Show(); }).empty(), "inorder prints nothing");

    cout << "\n=== Reuse tree after emptied ===\n";
    t.Insert(10);
    t.Insert(5);
    t.Insert(15);
    CHECK(t.Size() == 3, "size == 3 after reinsert");
    CHECK(checkTraversal(t, {10, 5, 15}, {5, 10, 15}, {5, 15, 10}), "traversals after reinsert");

    cout << "\n=== Skewed tree (right) ===\n";
    {
        BST s;
        for (int i = 1; i <= 5; ++i) s.Insert(i);
        CHECK(s.Size() == 5, "size == 5");
        CHECK(checkTraversal(s, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}), "right-skewed traversals");
        for (int i = 1; i <= 5; ++i) {
            s.Delete(i);
            CHECK(s.Size() == 5 - i, "size after deleting root " + to_string(i));
        }
        CHECK(s.Empty(), "skewed tree empty");
    }

    cout << "\n=== Skewed tree (left) ===\n";
    {
        BST s;
        for (int i = 5; i >= 1; --i) s.Insert(i);
        CHECK(checkTraversal(s, {5, 4, 3, 2, 1}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}), "left-skewed traversals");
        s.Delete(5);
        CHECK(checkTraversal(s, {4, 3, 2, 1}, {1, 2, 3, 4}, {1, 2, 3, 4}), "after delete root of left-skewed");
    }

    cout << "\n=== Single node ===\n";
    {
        BST s;
        s.Insert(42);
        CHECK(s.Size() == 1 && s.Search(42), "single node inserted");
        s.Delete(42);
        CHECK(s.Empty() && !s.Search(42), "single node deleted");
    }

    cout << "\n=== Negative values ===\n";
    {
        BST s;
        int v[] = {0, -5, 5, -10, -3};
        for (int x : v) s.Insert(x);
        CHECK(checkTraversal(s, {0, -5, -10, -3, 5}, {-10, -5, -3, 0, 5}, {-10, -3, -5, 5, 0}), "negative traversals");
    }

    cout << "\n=== Duplicate insert (behavior check) ===\n";
    {
        BST s;
        s.Insert(10);
        s.Insert(10);
        cout << "  size after inserting 10 twice = " << s.Size()
             << " (1 = ignores duplicate, 2 = allows duplicate)\n";
        cout << "  inorder: ";
        s.Inorder_Show();
        cout << "\n";
    }

    cout << "\n==============================\n";
    cout << "Passed: " << passed << "  Failed: " << failed << "\n";
    return failed == 0 ? 0 : 1;
}