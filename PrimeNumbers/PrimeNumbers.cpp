#include "PrimeNumbers.h"
#include <sstream>

using namespace ::std;

PrimeNumbers::PrimeNumbers() :
	m_PrimeNumbers(0)
{
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

bool PrimeNumbers::IsDivisibleBy(const long& total, const int division)
{
	return (total %division == 0) ? true : false;
}

string PrimeNumbers::ShowPrimeSequence(const long& numberOfPrimes)
{
	stringstream outputStream;
	if (numberOfPrimes > 0)
	{
		GenerateNumberOfPrimes(numberOfPrimes);
	}
	if (m_PrimeNumbers.size() > 0)
	{
		for (auto n : m_PrimeNumbers)
		{
			outputStream << n;
			if (n != m_PrimeNumbers.back())
			{
				outputStream << ", ";
			}
		}
	}
	return outputStream.str();
}

string PrimeNumbers::OutputPrimeFactors(const long& number)
{
	stringstream factors;
	GeneratePrimesUpTo(number);
	long total = number;
	while (total > static_cast<long>(m_minimumNumber))
	{
		for (auto n : m_PrimeNumbers)
		{
			if ((n <= total) && (IsDivisibleBy(total, n)))
			{
				if (factors.str().size() >= m_minimumNumber)
				{
					factors << " * ";
				}
				factors << n;
				int newTotal = total - (total / n);
				total -= (newTotal > m_minimumNumber) ? newTotal : total;
				break;
			}
		}
	}
	return factors.str();
}

void PrimeNumbers::GenerateNumberOfPrimes(const int numberOfPrimes)
{
	int sequenceFrom = (m_PrimeNumbers.size() > 0) ? m_PrimeNumbers.back() : m_minimumNumber;
	long totalPrimeSize = (m_PrimeNumbers.size() + numberOfPrimes);
	while (static_cast<long>(m_PrimeNumbers.size()) < totalPrimeSize)
	{
		sequenceFrom++;
		if (IsPrimeNumber(sequenceFrom))
		{
			m_PrimeNumbers.push_back(sequenceFrom);
		}
	}
}

void PrimeNumbers::GeneratePrimesUpTo(const long&  number)
{
	if (m_PrimeNumbers.size() < m_minimumNumber)
	{
		m_PrimeNumbers.push_back(m_smallestPrime);
	}
	while (m_PrimeNumbers.back() <= number)
	{
		GenerateNumberOfPrimes(m_minimumNumber);
	}
	if (m_PrimeNumbers.back() >= number)
	{
		m_PrimeNumbers.pop_back();
	}
}