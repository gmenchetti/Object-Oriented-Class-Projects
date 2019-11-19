#include <iostream>
#include <fstream>
#include "Model.h"
using namespace std;

#include <vector>
#include <string>

int main() {
	int song_number = 10; // Number of songs to fetch from clips folder
    Model m = Model(song_number);
    std::cout << "Welcome to the MLS" << std::endl;
    int cont = 1;
    while (cont) {
        std::string inst;
        std::cout << "Insert instruction: ";
        std::cin >> inst;
        cont = m.execute(inst);
    }
}