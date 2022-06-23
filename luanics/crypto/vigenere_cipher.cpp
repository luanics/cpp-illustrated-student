#include "luanics/crypto/vigenere_cipher.hpp"

#include "luanics/crypto/helpers.hpp"
#include "luanics/testing/tutorial.hpp"

#include <cctype>

namespace luanics::crypto {

namespace {

std::string crypted(std::string s, std::string const & key, int multiplier) {
	// operate inplace on s
	std::size_t keyIndex = 0;
	for (char & ch: s) {
		if (std::isalpha(ch)) {
			ch = shift(ch, multiplier*(key[keyIndex++ % key.size()] - 'a'));
		}
	}
	return s;
}

}

vigenere_cipher::vigenere_cipher(std::string key) :
	_key{std::move(key)}
{}

std::string vigenere_cipher::encrypt(std::string decoded) const {
	CREATE
	
}

std::string vigenere_cipher::decrypt(std::string encoded) const {
	return crypted(std::move(encoded), _key, -1);
}

}
