#include "PrimeNumbers.h"

using namespace ::std;

PrimeNumbers::PrimeNumbers()
{
	m_PrimeNumbers.reserve(3);
}

PrimeNumbers::~PrimeNumbers()
{
	m_PrimeNumbers.clear();
}

bool PrimeNumbers::IsPrimeNumber(long& number)
{
	for (int i = 2; i < number; i++)
	{
		if (number %i == 0)
			return false;
	}
	return true;
}