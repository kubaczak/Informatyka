#include <iostream>


int main() {
    int aMatrix[5][2] = {{5, 1}, {-3, 3}, {4, -1}, {-1, 2}, {0, 7}};
    int bMatrix[2][7] = {{1, 7, 0, -1, 9, 0, 5}, {2, -6, -1, 10, 2, -3, 1}};
    
    int kolumnya = 5;
    int wierszea = 2;
    int kolumnyb = 2;
    int wierszeb = 7;
    int Matrix[5][7] = {};
    if(wierszea == kolumnyb){
      for (int row = 0; row < kolumnya; row++) {
        for (int col = 0; col < wierszeb; col++) {
            for (int inner = 0; inner < wierszea; inner++) {
                Matrix[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
            }
            std::cout << Matrix[row][col] << "  ";
        }
        std::cout << "\n";
      }
    } else {
      std::cout << "Nie mozna mnozyc tych maciezy";
    }


}
