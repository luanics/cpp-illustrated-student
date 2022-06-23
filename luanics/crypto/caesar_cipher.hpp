#pragma once

#include <string>

namespace luanics::crypto::caesar_cipher {

/// @pre plaintext composed solely of lowercase letters
std::string encrypt(std::string const & plaintext, int key);

/// @pre ciphertext composed solely of lowercase letters
std::string decrypt(std::string const & ciphertext, int key);

}
