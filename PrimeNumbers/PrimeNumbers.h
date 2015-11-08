#ifndef PRIME_NUMBERS_DEFINED
#define PRIME_NUMBERS_DEFINED

#include <vector>
#include <string>

class PrimeNumbers
{
public:
	PrimeNumbers();
	~PrimeNumbers();
	bool IsPrimeNumber(const long& number);
	std::string ShowPrimeSequence(const long& numberOfPrimes = 0);
	std::string OutputPrimeFactors(const long& number);
	void GenerateNumberOfPrimes(const long& numberOfPrimes);
	void GeneratePrimesUpTo(const long& number);
private:
	std::vector<long> m_PrimeNumbers;
	bool IsDivisibleBy(const long& total, const int division);
	const unsigned long  m_minimumNumber = 1;
	const unsigned int m_smallestPrime = 2;
};

#endif