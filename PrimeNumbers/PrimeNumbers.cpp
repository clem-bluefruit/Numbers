#include "PrimeNumbers.h"
#include <sstream>

using namespace ::std;

bool PrimeNumbers::IsPrimeNumber(const u128& number)
{
	for (int i = m_smallestPrime; i < number; i++)
	{
		if (number %i == NULL)
			return false;
	}
	return true;
}

bool PrimeNumbers::IsDivisibleBy(const u128& total, const int division)
{
	return (total %division == NULL) ? true : false;
}

string PrimeNumbers::ShowPrimeSequence(const u128& numberOfPrimes)
{
	stringstream outputStream;
	if (numberOfPrimes > NULL)
	{
		GenerateNumberOfPrimes(numberOfPrimes);
	}
	if (m_PrimeNumbers.size() > NULL)
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

string PrimeNumbers::OutputPrimeFactors(const u128& number)
{
	stringstream factors;
	GeneratePrimesUpTo(number);
	u128 total = number;
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
				u128 newTotal = total - (total / n);
				total -= (newTotal > m_minimumNumber) ? newTotal : total;
				break;
			}
		}
	}
	return factors.str();
}

void PrimeNumbers::GenerateNumberOfPrimes(const u128& numberOfPrimes)
{
	u128 sequenceFrom = (m_PrimeNumbers.size() > NULL) ? m_PrimeNumbers.back() : m_minimumNumber;
	const unsigned long totalPrimeSize = (m_PrimeNumbers.size() + numberOfPrimes);
	while (static_cast<long>(m_PrimeNumbers.size()) < totalPrimeSize)
	{
		sequenceFrom++;
		if (IsPrimeNumber(sequenceFrom))
		{
			m_PrimeNumbers.push_back(sequenceFrom);
		}
	}
}

void PrimeNumbers::GeneratePrimesUpTo(const u128&  number)
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