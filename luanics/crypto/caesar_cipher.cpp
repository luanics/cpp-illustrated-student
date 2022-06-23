#include "luanics/crypto/caesar_cipher.hpp"
#include "luanics/crypto/helpers.hpp"
#include "luanics/logging/contract.hpp"

namespace luanics::crypto::caesar_cipher {

std::string encrypt(std::string const & plaintext, int const key) {
	std::string result{plaintext};
	for (char ch: result) {
		ch = shift(ch, key);
	}
	return result;
}

std::string decrypt(std::string const & ciphertext, int const key) {
	return encrypt(ciphertext, -key);
}

}
