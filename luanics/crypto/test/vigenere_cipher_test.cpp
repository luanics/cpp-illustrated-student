#include "luanics/crypto/vigenere_cipher.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::crypto {

BEGIN_TEST_SET(vigenere_cipher_tutorial)

TEST(all) {
	// Example borrowed from http://en.wikipedia.org/wiki/Classical_cipher#Substitution_ciphers
	vigenere_cipher cipher{"word"};
	auto const plaintext = "I LOVE CRYPTOGRAPHY";
	auto const ciphertext = cipher.encrypt("I LOVE CRYPTOGRAPHY");
	EXPECT_EQ("E ZFYA QIBLHFJNOGKU", ciphertext);
	EXPECT_EQ(plaintext, cipher.decrypt(ciphertext));
}

END_TEST_SET(vigenere_cipher_tutorial)

}
