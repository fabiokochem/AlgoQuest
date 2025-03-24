#include <iostream>
#include <string>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

/* 
SHA-256 is a cryptographic hash function that takes an input and produces a 256-bit (32-byte) hash value. It's very simple to use, and it's efficient enough for most purposes. In this article, we'll take a look at how to use SHA-256 in C++. We'll also take a look at how to use SHA-256 to hash a string and hash a file's contents. So, let's get started!

The implementation of SHA-256 without a library is quite complex, so we'll use the Crypto++ library to make things easier. Crypto++ is a free C++ class library of cryptographic schemes. It's a very powerful library that provides a wide range of cryptographic algorithms, including SHA-256. To use Crypto++, you need to download the library from the official website and include it in your project. Once you've done that, you can start using SHA-256 in your C++ code.

Here's a simple example of how to use SHA-256 in C++ using Crypto++:
    - Install the Crypto++ library on your system: vcpkg install cryptopp
    - First, include the necessary headers:
        #include <iostream>
        #include <string>
        #include <cryptopp/sha.h>
        #include <cryptopp/hex.h>
        #include <cryptopp/filters.h>
    - Next, create a function that takes a string as input and returns the SHA-256 hash value of that string:
    
Time Complexity: O(n)
*/

std::string sha256(const std::string& input) {
    CryptoPP::SHA256 hash;
    std::string digest;

    CryptoPP::StringSource(input, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest), false)));

    return digest;
}

int main() {
    std::string input;
    std::cout << "Enter a string to hash: ";
    std::getline(std::cin, input);

    std::string hashValue = sha256(input);
    std::cout << "SHA-256 hash: " << hashValue << std::endl;

    return 0;
}

