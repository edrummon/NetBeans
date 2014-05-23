/* 
 * File:   KnowledgeBase.h
 * Author: Instinct
 *
 * Created on February 23, 2014, 10:06 PM
 */

#ifndef KNOWLEDGEBASE_H
#define	KNOWLEDGEBASE_H
#include <utility>

template<typename T> class BinaryTree;

template<typename T>
class KnowledgeBase {
    
public:
    KnowledgeBase() {guessedWrong = false;}
    ~KnowledgeBase() {}
    KnowledgeBase(const KnowledgeBase&);

    void addQandA(T&, T&, char);
    void giveUp() {guessedWrong = true;}
    bool outOfQuestions() {return bTree.getUnableToGuess(guessedWrong);}
    bool isGuess() {return bTree.isGuess();}
    T getData() const {return bTree.getData();}
    void resetTraverse() {bTree.resetTraverse();}
    void traverse(char direction) {bTree.traverse(direction);}

    KnowledgeBase<T>& operator=(const KnowledgeBase);
private:
    BinaryTree<T> bTree;
    bool guessedWrong;
};

template<typename T>
KnowledgeBase<T>::KnowledgeBase(const KnowledgeBase& other) {
    bTree = other.bTree;
    guessedWrong = other.guessedWrong;
}

template<typename T>
void KnowledgeBase<T>::addQandA(T& question, T& answer, char side) {
    bTree.addQandA(question, answer, side, guessedWrong);
    guessedWrong = false;
}

template<typename T>
KnowledgeBase<T>& KnowledgeBase<T>::operator =(const KnowledgeBase other) {
    std::swap(bTree, other.bTree);
    std::swap(guessedWrong, other.guessedWrong);
    return *this;
}

#endif	/* KNOWLEDGEBASE_H */