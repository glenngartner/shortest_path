#include <iostream>


struct Object {
    int id;
    std::string name;
};

int main() {

    bool runApp = true;
    char input;

    int a = 5;
    int b = a;
    b++;
    a--;

    Object object1;
    object1.id = 1;
    object1.name = "Clifford";

    Object object2;
    object2 = object1;

    while (runApp) {

        std:: cout << "a: " << a << " b: " << b << std::endl;
        std::cin >> input;

        std:: cout << "object 1 id: " << object1.id << ", name: " << object1.name << std::endl;
        std:: cout << "object 2 id: " << object2.id << ", name: " << object2.name << std::endl;

        // check for program close
        if (input == 'x') runApp = false;
    }
    return 0;
}