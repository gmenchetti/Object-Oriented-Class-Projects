#include <iostream>
#include <fstream>
#include "Model.h"
using namespace std;

#include <vector>
#include <string>

int main() {
    Model m = Model(10);
    std::cout << "Welcome to the MLS" << std::endl;
    int cont = 1;
    while (cont) {
        std::string inst;
        std::cout << "Insert instruction: ";
        std::cin >> inst;
        cont = m.execute(inst);
    }
}