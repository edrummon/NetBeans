/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on May 31, 2014, 2:12 AM
 */

#include <fstream>

using std::ofstream;

int main(int argc, char** argv) {
    
    int gods[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77};
    long long numGods = 0;
    
    ofstream file("/cygdrive/c/Users/Instinct212/Desktop/results.txt");
    
    for (int i = 0; i < 13; ++i) {
        //file << (char) (gods[0] + i) << "\r\n";
        ++numGods;
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            //file << (char) gods[i] << (char) gods[j] << "\r\n";
            ++numGods;
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                //file << (char) gods[i] << (char) gods[j] << (char) gods[k] << "\r\n";
                ++numGods;
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    if (!(i == j && j == k && k == l)) {
                        //file << (char) gods[i] << (char) gods[j] << (char) gods[k] << (char) gods[l] << "\r\n";
                        ++numGods;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    if (!(i == j && j == k && k == l)) {
                        for (int m = 0; m < 13; ++m) {
                            //file << (char) gods[i] << (char) gods[j] << (char) gods[k] << (char) gods[l] << (char) gods[m] << "\r\n";
                            ++numGods;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    if (!(i == j && j == k && k == l)) {
                        for (int m = 0; m < 13; ++m) {
                            for (int n = 0; n < 13; ++n) {
                                //file << (char) gods[i] << (char) gods[j] << (char) gods[k] << (char) gods[l] << (char) gods[m] << (char) gods[n] << "\r\n";
                                ++numGods;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    if (!(i == j && j == k && k == l)) {
                        for (int m = 0; m < 13; ++m) {
                            for (int n = 0; n < 13; ++n) {
                                for (int o = 0; o < 13; ++o) {
                                    //file << (char) gods[i] << (char) gods[j] << (char) gods[k] << (char) gods[l] << (char) gods[m] << (char) gods[n] << (char) gods[o] << "\r\n";
                                    ++numGods;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    if (!(i == j && j == k && k == l)) {
                        for (int m = 0; m < 13; ++m) {
                            for (int n = 0; n < 13; ++n) {
                                for (int o = 0; o < 13; ++o) {
                                    for (int p = 0; p < 13; ++p) {
                                        if (!(m == n && n == o && o == p)) {
                                            //file << (char) gods[i] << (char) gods[j] << (char) gods[k] << (char) gods[l] << (char) gods[m] << (char) gods[n] << (char) gods[o] << (char) gods[p] << "\r\n";
                                            ++numGods;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    if (!(i == j && j == k && k == l)) {
                        for (int m = 0; m < 13; ++m) {
                            for (int n = 0; n < 13; ++n) {
                                for (int o = 0; o < 13; ++o) {
                                    for (int p = 0; p < 13; ++p) {
                                        if (!(m == n && n == o && o == p)) {
                                            for (int q = 0; q < 13; ++q) {
                                                if (numGods > 11477782000) {
                                                    file << (char) gods[i] << (char) gods[j] << (char) gods[k] << (char) gods[l] << (char) gods[m] << (char) gods[n] << (char) gods[o] << (char) gods[p] << (char) gods[q] << "\r\n";
                                                }
                                                ++numGods;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //file << numGods << "\r\n";

    return 0;
}