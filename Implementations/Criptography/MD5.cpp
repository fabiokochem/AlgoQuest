#include <iostream>
#include <openssl/md5.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::hex;
using std::setfill;
using std::setw;

/*
    MD5 (Message-Digest Algorithm 5) is a widely used cryptographic hash function that produces a 128-bit (16-byte) hash value from an input message.
    It was designed by Ronald Rivest in 1991 and is commonly used for data integrity verification.

    However, MD5 is no longer considered secure due to vulnerabilities like collision attacks, where two different inputs produce the same hash.
    It should not be used for cryptographic security but is still useful for checksums and non-cryptographic purposes.

    MD5 operates by processing input data in 512-bit chunks, using bitwise operations and modular addition.
    The algorithm follows these steps:

    1. Padding the message to ensure its length is congruent to 448 modulo 512.
    2. Appending the original message length as a 64-bit integer.
    3. Initializing MD5 buffer with four 32-bit words.
    4. Processing message blocks in four non-linear functions.
    5. Outputting the final hash value.

    Time Complexity:
    - Hashing an input: O(n), where n is the length of the input message.
*/

string md5(const string& input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setfill('0') << setw(2) << static_cast<int>(digest[i]);
    }
    return ss.str();
}

int main() {
    string message = "Hello, World!";
    cout << "MD5 Hash of '" << message << "': " << md5(message) << endl;
    return 0;
}
