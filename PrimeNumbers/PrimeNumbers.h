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
	unsigned int GetPrimeFactors(const long& number);
	std::string ShowPrimeSequence(const long& numberOfPrimes = 0);
private:
	std::vector<long> m_PrimeNumbers;
	void GeneratePrimeSeqeunce(const int numberOfPrimes);
};

#endif