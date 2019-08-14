/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        helper(quadTree1, quadTree2);
        return quadTree1;
    }
    
    int helper(Node* a, Node* b) {
        if (a->isLeaf && b->isLeaf) {
            a->val |= b->val;
            return a->val; // true = 1, false = 0, mixed = -1;
        }
        if (a->isLeaf) born(a);
        if (b->isLeaf) born(b);
        int tl = helper(a->topLeft, b->topLeft);
        int tr = helper(a->topRight, b->topRight);
        int bl = helper(a->bottomLeft, b->bottomLeft);
        int br = helper(a->bottomRight, b->bottomRight);
        if (tl==tr && tl==bl && tl==br && tl!=-1) {
            a->isLeaf = true;
            a->val = tl;
            a->topLeft = nullptr;
            a->topRight = nullptr;
            a->bottomLeft = nullptr;
            a->bottomRight = nullptr;
            return tl;
        }
        return -1;
    }
    
    void born(Node* a) {
        a->isLeaf = false;
        a->topLeft = new Node(a->val, true, nullptr, nullptr, nullptr, nullptr);
        a->topRight = new Node(a->val, true, nullptr, nullptr, nullptr, nullptr);
        a->bottomLeft = new Node(a->val, true, nullptr, nullptr, nullptr, nullptr);
        a->bottomRight = new Node(a->val, true, nullptr, nullptr, nullptr, nullptr);
    }
};


// Another solution:
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) return quadTree1->val?quadTree1:quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val?quadTree2:quadTree1;
        
        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        Node* res = new Node(tl->val, false, tl, tr, bl, br);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val==tr->val && tl->val==bl->val && tl->val==br->val) {
            res->isLeaf = true;
            res->topLeft = nullptr;
            res->topRight = nullptr;
            res->bottomLeft = nullptr;
            res->bottomRight = nullptr;
            delete tl,tr,bl,br;
        }
        return res;
    }
};