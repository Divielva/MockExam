#ifndef Mock_Header
#define Mock_Header
#pragma once


#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Storage {
    Storage(int index, char name, int value)
        : index(index), name(name), value(value) {}
    void toString() {
        std::string lives = "";
        for (int i = 0; i < value; i++)
            lives.append("*");
        std::cout << index << " " << name << " " << value << " " << lives << std::endl;
    }
    int index;
    char name;
    int value;
};


std::vector<char> required{ 's', 'd', 'w', 'd' };
std::vector<char> input = {};

int tries = 3;
bool correct = true;
int MenuAnswer;

void drawBoard() {
    std::cout << std::endl;
    for (int i = 1; i <= 9; i++) {
        std::cout << "| " << i << " ";
        if (i % 3 == 0)
            std::cout << "|" << std::endl;
    }
}

#endif // !Mock_Header