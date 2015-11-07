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
	void GenerateNumberOfPrimes(const int numberOfPrimes);
	void GeneratePrimesUpTo(const long& number);
private:
	std::vector<long> m_PrimeNumbers;
};

#endif