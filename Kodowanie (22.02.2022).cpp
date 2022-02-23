#include <iostream>

int main() {
    unsigned char tab[] = { 0x30, 0x30, 0x20, 0x3, 0x3, 0x3, 0x8, 0x10, 0x15, 0x15, 0x15, 0x0, 0x1, 0x0 };


    for (int i = 0; i < 15; i++) {
        int counter = 0;
        for (int j = i; j < 15; j++) {
            if (tab[i] != tab[j]) {
                std::cout << +tab[i] << " " << counter << " | ";
                i = j-1;
                break;
            }
            else {
                counter++;
            }
        }
    }
}
