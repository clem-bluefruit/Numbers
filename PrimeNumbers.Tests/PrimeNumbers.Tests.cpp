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
	ASSERT_TRUE(numbers.IsPrimeNumber(2))    << "Error: 2 IS a prime number";
	ASSERT_TRUE(numbers.IsPrimeNumber(3))    << "Error: 3 IS a prime number";
	ASSERT_FALSE(numbers.IsPrimeNumber(4))   << "Error: 4 is NOT a prime number";
	ASSERT_FALSE(numbers.IsPrimeNumber(30))  << "Error: 30 is NOT a prime number";
	ASSERT_TRUE(numbers.IsPrimeNumber(8011)) << "Error: 8011 IS a prime number";
}

TEST_F(TestPrimeNumbers, Generate_a_custom_length_sequence_of_prime_numbers)
{
	string expectedSequence = "2, 3, 5";
	ASSERT_EQ(expectedSequence, numbers.ShowPrimeSequence(3));

	string firstOneHundredPrimes =  "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, "
									"71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, "
									"151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, "
									"233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, "
									"317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, "
									"419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, "
									"503, 509, 521, 523, 541";
	ASSERT_EQ(firstOneHundredPrimes, numbers.ShowPrimeSequence(97));
}

TEST_F(TestPrimeNumbers, Generate_all_prime_numbers_up_to_a_specified_value)
{
	string primeNumbersTo1000 = "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, "
								"79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, "
								"167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, "
								"257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, "
								"353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, "
								"449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, "
								"563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, "
								"653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, "
								"761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, "
								"877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, "
								"991, 997";
	numbers.GeneratePrimesUpTo(1000);
	ASSERT_EQ(primeNumbersTo1000, numbers.ShowPrimeSequence());
}

TEST_F(TestPrimeNumbers, Returns_single_digit_prime_factors)
{
	int number = 2;
	string factor = "2";
	numbers.GeneratePrimesUpTo(number);
	ASSERT_EQ(factor, numbers.OutputPrimeFactors(number)) << "Error: prime factor of 2 is 2!";

	number = 3;
	factor = "3";
	numbers.GenerateNumberOfPrimes(number);
	ASSERT_EQ(factor, numbers.OutputPrimeFactors(number)) << "Error: prime factor of 3 is 3!";

	number = 5;
	ASSERT_EQ("5", numbers.OutputPrimeFactors(number));
}

TEST_F(TestPrimeNumbers, Returns_2_digitprime_factor_sequence)
{
	string factorSequence = "2 * 2";
	int number = 4;
	numbers.GenerateNumberOfPrimes(number);
	ASSERT_EQ(factorSequence, numbers.OutputPrimeFactors(number));

	factorSequence = "3 * 3";
	number = 9;
	ASSERT_EQ(factorSequence, numbers.OutputPrimeFactors(number));
}

TEST_F(TestPrimeNumbers, Returns_3_or_more_digit_prime_factors)
{
	string factorSequence = "2 * 2 * 3";
	int number = 12;
	ASSERT_EQ(factorSequence, numbers.OutputPrimeFactors(number));

	factorSequence = "2 * 2 * 5 * 5";
	number = 100;
	ASSERT_EQ(factorSequence, numbers.OutputPrimeFactors(number));
}