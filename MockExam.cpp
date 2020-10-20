#include "Header.h"


int main() {

    drawBoard();
    std::cout << "                                              " << std::endl;
    std::cout << "Starting from 1, use the WASD buttons to login" << std::endl;

    while (tries-- > 0) {
        input = {};
        std::cout << "                                    " << std::endl;
        std::cout << "Please input 4 values in sequence : ";
        for (unsigned int i = 0; i < required.size(); i++) {
            char g = _getch();
            input.push_back(g);
            std::cout << g;
        }
        std::cout << std::endl;

        for (unsigned int i = 0; i < required.size(); i++) {
            correct = required[i] == input[i];
            if (correct)
                continue;
            else
                break;
        }

        if (!correct) {
            std::cout << "Incorrect answer! You have " << tries << " tries left" << std::endl;
        }
        else
            break;

    }

    if (correct) {

        std::cout << "                                        " << std::endl;
        std::cout << "You have succesfully logged in, Welcome!" << std::endl;
        std::cout << "                                        " << std::endl;

        bool chosenMenu = false;

        while (chosenMenu == false) {
            std::cout << "|------------------------|" << std::endl;
            std::cout << "|    MAIN MENU           |" << std::endl;
            std::cout << "| 1. Dice Rolling        |" << std::endl;
            std::cout << "| 2. Health Bar          |" << std::endl;
            std::cout << "| 3. Pac Man             |" << std::endl;
            std::cout << "| 4. Pac Man (full game) |" << std::endl;
            std::cout << "| 5. EXIT                |" << std::endl;
            std::cout << "|------------------------|" << std::endl;
            std::cout << "What do you wanna use? : ";
            std::cin >> MenuAnswer;
            std::cout << "                          " << std::endl;

            if (MenuAnswer == 1) {
                std::cout << "here we do the dice rolls" << std::endl;
                chosenMenu = true;
            }
            else if (MenuAnswer == 2) { 
                std::vector<Storage> entries{};

                for (int i = 0; i < 10; i++) {
                    entries.push_back({ i, static_cast<char>('A' + i), rand() % 20 + 1 });
                }

                std::sort (entries.begin(), entries.end(), [](Storage a, Storage b) {return a.value > b.value; });

                for (Storage entry : entries) {
                    entry.toString();
                }


                return 0;
                
            }
            else if (MenuAnswer == 3) {
                std::cout << "pac man shit goes here" << std::endl;
                chosenMenu = true;
            }
            else if (MenuAnswer == 4) {
                std::cout << "whenever i figure out how to make a working pac man game ill add it here" << std::endl;
                chosenMenu = true;
            }
            else if (MenuAnswer == 5) {
                std::cout << "Exiting the program" << std::endl;
                return 0;
            }
            else {
                std::cout << "Wrong input, do you want to try again? y/n :";
                char temp;
                std::cin >> temp;
                if (temp == 'y' || temp == 'Y') {
                    continue;
                }
                else if (temp == 'n' || temp == 'N') {
                    return 0;
                }
            }


        }


    }
    else
        std::cout << "You failed to login, terminating program" << std::endl;
    return 0;

}
