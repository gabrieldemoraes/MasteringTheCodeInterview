//g++ -O3 knight_probability_in_chessboard.cpp -o knight_probability_in_chessboard.exe

#include "knight_probability_in_chessboard.hpp"
#include <iostream>

int main() {
    double n = 6;
    double k = 3;
    double row = 2;
    double column = 2;
    
    std::cout << knight_probability_botton_up_tabulation_oprimization(n, k, row, column) << std::endl;

    return 0;
}
