/* 
 * File:   main.cpp
 * Author: Instinct
 *
 * Created on February 23, 2014, 10:01 PM
 */

#include "BinaryTree.h"
#include "KnowledgeBase.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int main(int argc, char** argv) {

    void playRound(KnowledgeBase<string>&);

    KnowledgeBase<string> Kbase;
    playRound(Kbase);
    return 0;
}

void playRound(KnowledgeBase<string>& Kbase) {
    void checkVowel(string, string);
    
    cout << endl << endl << "Ok. Think of something. Ready? ('y' to continue): ";
    char keepPlaying, traversalSide, guessResponse;
    cin >> keepPlaying;
    while ((keepPlaying == 'y') || (keepPlaying == 'Y')) {
        if (!Kbase.outOfQuestions()) { //still have questions/guesses left
            if (!Kbase.isGuess()) { //question found
                cout << Kbase.getData() << " ";
                cin >> traversalSide;
                Kbase.traverse(traversalSide);
            } else { //guess found
                checkVowel(Kbase.getData(), "Is it");
                cin >> guessResponse;
                if ((guessResponse == 'y') || (guessResponse == 'Y')) {
                    cout << "I win!" << endl;
                    cout << "Would you like to play again? ('y' or 'n')? ";
                    cin >> keepPlaying;
                    Kbase.resetTraverse();
                } else { //program guesses wrong, need to rearrange nodes
                    traversalSide = 'n';
                    Kbase.giveUp();
                }
            }
        } else { //out of questions/guesses
            cout << endl << "I give up. What is it? ";
            string newAnswer;
            cin >> newAnswer;
            checkVowel(newAnswer, "What question would tell me it's");
            string newQuestion;
            cin.ignore(80, '\n');
            getline(cin, newQuestion);
            Kbase.addQandA(newQuestion, newAnswer, traversalSide);
            cout << "Would you like to play again? ('y' or 'n'): ";
            cin >> keepPlaying;
            cout << endl;
        }
    }
}

void checkVowel(string toCheck, string output) {
    if (find(vowels.begin(), vowels.end(), toCheck.at(0)) != vowels.end())
        cout << output << " an " << toCheck << "? ";
    else
        cout << output << " a " << toCheck << "? ";
}