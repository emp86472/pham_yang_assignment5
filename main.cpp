#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Sorting.h"

using namespace std;

int main(int argc, char *argv[]) {

    ifstream file;
    file.open(argv[1]); //file with ints
    setbuf(stdout, NULL);

    if (!file.is_open()) {
        cout << "Error: cannot parse information from ";
        cout << argv[1] << endl;
        exit(0);
    } //if

    int number;
    int num[10000];
    for (int i = 0; file >> number; i++) {
        num[i] = number;
    } //for

    file.close();

    for (int i = 0; i < 10000; i++) {
        cout << num[i] << endl;
    } //for


} //main
