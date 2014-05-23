/* 
 * File:   BinaryTree.h
 * Author: Instinct
 *
 * Created on February 23, 2014, 10:05 PM
 */

#ifndef BINARYTREE_H
#define	BINARYTREE_H
#include <utility>

template<typename T>
class BinaryTree {
public:

    struct Node {
        Node() : lChild(nullptr), rChild(nullptr) {}
        Node(T& newData) : data(newData), lChild(nullptr), rChild(nullptr) {}
        ~Node();
        Node(const Node&);
        
        bool isLeaf() {return (lChild == nullptr) && (rChild == nullptr);}

        BinaryTree<T>::Node& operator=(const Node);

        T data;
        Node *lChild;
        Node *rChild;
    };

    BinaryTree() : root(nullptr), current(nullptr), unableToGuess(true) {}
    ~BinaryTree() {delete root; root = nullptr;}
    BinaryTree(const BinaryTree&);
    
    void addQandA(T&, T&, char, bool);
    bool isGuess() {return current->isLeaf();}
    bool getUnableToGuess(bool);
    T getData() const {return current->data;}
    void traverse(char);
    void resetTraverse() {current = root;}

    BinaryTree<T>& operator=(const BinaryTree other);
private:
    Node *root, *current;
    bool unableToGuess;
};

template<typename T>
BinaryTree<T>::Node::~Node() {
    delete lChild;
    delete rChild;
}

template<typename T>
BinaryTree<T>::Node::Node(const Node& other) {
    data = other.data;
    lChild = new Node;
    rChild = new Node;
    if (other.lChild != nullptr)
        *lChild = *(other.lChild);
    else
        lChild = nullptr;
    
    if (other.rChild != nullptr)
        *rChild = *(other.rChild);
    else
        rChild = nullptr;
}

template<typename T>
typename BinaryTree<T>::Node& BinaryTree<T>::Node::operator=(const Node other) {
    std::swap(data, other.data);
    std::swap(lChild, other.lChild);
    std::swap(rChild, other.rChild);
    return *this;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other) {
    root = new Node;
    *root = *(other.root);
}

template<typename T>
bool BinaryTree<T>::getUnableToGuess(bool guessedWrong) {
    if (guessedWrong)
        unableToGuess = true;
    
    return unableToGuess;
}

template<typename T>
void BinaryTree<T>::addQandA(T& question, T& answer, char side, bool guessedWrong) {
    Node *newQnode = new Node(question);
    Node *newAnode = new Node(answer);
    newQnode->rChild = newAnode;
    if (!guessedWrong) { //was unable to guess, new question/answer node being placed as response to current question node
        if (root != nullptr) {
            if ((side == 'y') || (side == 'Y'))
                current->rChild = newQnode;
            else
                current->lChild = newQnode;
        } else {
            root = newQnode;
        }
    } else { //guess was wrong, need to move current node to "no" response from newQuestion
        Node *nodeToMove = new Node(current->data);
        nodeToMove->rChild = current->rChild;
        nodeToMove->lChild = current->lChild;
        current->data = question;
        current->rChild = newAnode;
        current->lChild = nodeToMove;
    }
    current = root;
    unableToGuess = false;
}

template<typename T>
void BinaryTree<T>::traverse(char direction) {
    if ((direction == 'y') || (direction == 'Y')) {
        if (current->rChild != nullptr)
            current = current->rChild;
        else
            unableToGuess = true;
    } else {
        if (current->lChild != nullptr)
            current = current->lChild;
        else
            unableToGuess = true;
    }
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree other) {
    std::swap(root, other.root);
    return *this;
}

#endif	/* BINARYTREE_H */