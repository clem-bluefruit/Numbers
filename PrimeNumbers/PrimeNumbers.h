#ifndef PRIME_NUMBERS_DEFINED
#define PRIME_NUMBERS_DEFINED

typedef unsigned long long u64;

#include <vector>
#include <string>

class PrimeNumbers
{
public:
	PrimeNumbers();
	bool IsPrimeNumber(const u64 number);
	std::string ShowPrimeSequence(const u64 numberOfPrimes = 0);
	std::string OutputPrimeFactors(const u64 number);
	void GenerateNumberOfPrimes(const u64 numberOfPrimes);
	void GeneratePrimesUpTo(const u64 number);
private:
	const unsigned long  m_minimumNumber = 1;
	const unsigned int m_smallestPrime   = 2;
	std::vector<const u64> m_PrimeNumbers;;
	bool IsDivisibleBy(const u64 total, const int division);
};

#endif