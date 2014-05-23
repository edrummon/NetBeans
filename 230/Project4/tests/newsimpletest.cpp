/* 
 * File:   newsimpletest.cpp
 * Author: Instinct
 *
 * Created on Feb 25, 2014, 6:30:59 PM
 */

#include <stdlib.h>
#include <iostream>
#include "KnowledgeBase.h"

/*
 * Simple C++ Test Suite
 */

void testAddQandA() {
    T& p0;
    T& p1;
    char p2;
    KnowledgeBase knowledgeBase;
    knowledgeBase.addQandA(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAddQandA (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testAddQandA (newsimpletest)" << std::endl;
    testAddQandA();
    std::cout << "%TEST_FINISHED% time=0 testAddQandA (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

