#include "luanics/crypto/caesar_cipher.hpp"
#include "luanics/testing/unit.hpp"

namespace luanics::crypto::caesar_cipher {

BEGIN_TEST_SET(caesar_cipher)

TEST(valid_input) {
	int const key = 2;
	std::string const plaintext{"ilovecryptography"};
	std::string const ciphertext = encrypt(plaintext, key);
	EXPECT_EQ("knqxgetarvqitcrja", ciphertext);
	EXPECT_EQ(plaintext, decrypt(ciphertext, key));
}

// This version of the cipher requires strings be composed solely of lowercase letters.
TEST(invalid_input) {
	int const key = 2;

	EXPECT_THROW(encrypt("ThisHasUppercaseLetters", key));
	EXPECT_THROW(decrypt("ThisHasUppercaseLetters", key));

	EXPECT_THROW(encrypt("this has spaces", key));
	EXPECT_THROW(decrypt("this has spaces", key));

	EXPECT_THROW(encrypt("th1sh4snumb3rs", key));
	EXPECT_THROW(decrypt("th1sh4snumb3rs", key));

	EXPECT_THROW(encrypt("th!sh@sch@r@cter$", key));
	EXPECT_THROW(decrypt("th!sh@sch@r@cter$", key));
}

END_TEST_SET(caesar_cipher)

}
