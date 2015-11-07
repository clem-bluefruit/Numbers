#ifndef PRIME_NUMBERS_DEFINED
#define PRIME_NUMBERS_DEFINED

#include <vector>

class PrimeNumbers
{
public:
	PrimeNumbers();
	~PrimeNumbers();
	bool IsPrimeNumber(long&);
	unsigned int GetPrimeFactors(long&);
private:
	std::vector<long> m_PrimeNumbers;
};

#endif