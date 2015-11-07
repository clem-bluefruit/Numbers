#include "PrimeNumbers.h"
#include <sstream>

using namespace ::std;

PrimeNumbers::PrimeNumbers()
{
	m_PrimeNumbers.clear();
}

PrimeNumbers::~PrimeNumbers()
{
	m_PrimeNumbers.clear();
}

bool PrimeNumbers::IsPrimeNumber(const long& number)
{
	for (int i = 2; i < number; i++)
	{
		if (number %i == 0)
			return false;
	}
	return true;
}

void PrimeNumbers::GeneratePrimeSeqeunce(const int numberOfPrimes)
{
	int sequenceFrom = (m_PrimeNumbers.size() > 0) ? m_PrimeNumbers.back() : 1;
	int totalPrimeSize = (m_PrimeNumbers.size() + numberOfPrimes);
	while (m_PrimeNumbers.size() < totalPrimeSize)
	{
		sequenceFrom++;
		if (IsPrimeNumber(sequenceFrom))
			m_PrimeNumbers.push_back(sequenceFrom);
	}
}

string PrimeNumbers::ShowPrimeSequence(const long& numberOfPrimes)
{
	if (numberOfPrimes > 0)
		GeneratePrimeSeqeunce(static_cast<int>(numberOfPrimes));
	stringstream outputStream;
	if (m_PrimeNumbers.size() > 0)
	{
		for (auto n : m_PrimeNumbers)
		{
			outputStream << n;
			if (n != m_PrimeNumbers.back())
				outputStream << ", ";
		}
	}
	return outputStream.str();
}