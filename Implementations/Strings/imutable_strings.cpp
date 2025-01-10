#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

/*
Immutable strings refer to strings that cannot be modified after they are created. C++ does not have built-in support for immutable strings, but you can simulate immutability using certain techniques, such as using const, custom classes or by copying the std::string in a way that prevents modification.

In this example, we will use the const keyword to create an immutable string. We will also demonstrate how to create a custom class that simulates an immutable string.
*/

// Custom class to simulate immutable string
class ImmutableString {
private:
    string str;

public:
    ImmutableString(const string& s) : str(s) {}

    string get() const {
        return str;
    }
};

int main() {
    const string immuStr = "This is an immutable string";
    cout << immuStr << endl;

    ImmutableString immutableStr("This is a custom immutable string");
    cout << immutableStr.get() << endl;

    return 0;
}