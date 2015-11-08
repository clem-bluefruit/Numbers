#ifndef PRIME_NUMBERS_DEFINED
#define PRIME_NUMBERS_DEFINED

typedef unsigned long long u128;

#include <vector>
#include <string>

class PrimeNumbers
{
public:
	bool IsPrimeNumber(const u128& number);
	std::string ShowPrimeSequence(const u128& numberOfPrimes = 0);
	std::string OutputPrimeFactors(const u128& number);
	void GenerateNumberOfPrimes(const u128& numberOfPrimes);
	void GeneratePrimesUpTo(const u128& number);
private:
	std::vector<const u128> m_PrimeNumbers;
	bool IsDivisibleBy(const u128& total, const int division);
	const unsigned long  m_minimumNumber = 1;
	const unsigned int m_smallestPrime = 2;
};

#endif