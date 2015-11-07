#include "PrimeNumbers.h"
#include <gtest\gtest.h>
#include <string>

using namespace ::std;
using namespace ::testing;

class TestPrimeNumbers : public PrimeNumbers, public ::testing::Test
{
public:
	PrimeNumbers numbers;
};

TEST_F(TestPrimeNumbers, Check_if_number_is_a_prime)
{
	ASSERT_TRUE(numbers.IsPrimeNumber(2));
	ASSERT_TRUE(numbers.IsPrimeNumber(3));
	ASSERT_FALSE(numbers.IsPrimeNumber(4));
	ASSERT_FALSE(numbers.IsPrimeNumber(30));
	ASSERT_TRUE(numbers.IsPrimeNumber(8011));
}

TEST_F(TestPrimeNumbers, Generate_a_custom_length_sequence_of_prime_numbers)
{
	string expectedSequence = "2, 3, 5";
	ASSERT_EQ(expectedSequence, numbers.ShowPrimeSequence(3));

	string firstOneHundredPrimes = "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541";
	ASSERT_EQ(firstOneHundredPrimes, numbers.ShowPrimeSequence(97));
}