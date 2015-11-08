#include "PrimeNumbers.h"
#include <sstream>

using namespace ::std;

PrimeNumbers::PrimeNumbers()
{
	m_PrimeNumbers.push_back(m_smallestPrime);
}

bool PrimeNumbers::IsPrimeNumber(const u64 number)
{
	for (int i = m_smallestPrime; i < number; i++)
	{
		if (number %i == 0)
			return false;
	}
	return true;
}

bool PrimeNumbers::IsDivisibleBy(const u64 total, const long division)
{
	return (total %division == 0) ? true : false;
}

string PrimeNumbers::ShowPrimeSequence(const u64 numberOfPrimes)
{
	stringstream outputStream;
	unsigned long totalNumberOfPrimes = (numberOfPrimes - m_PrimeNumbers.size());
	GenerateNumberOfPrimes(totalNumberOfPrimes);
	for (auto n : m_PrimeNumbers)
	{
		outputStream << n;
		if (n != m_PrimeNumbers.back())
		{
			outputStream << ", ";
		}
	}
	return outputStream.str();
}

string PrimeNumbers::OutputPrimeFactors(const u64 number)
{
	stringstream factors;
	GeneratePrimesUpTo(number);
	u64 total = number;
	while (total > 1)
	{
		for (auto n : m_PrimeNumbers)
		{
			if (!IsDivisibleBy(total, n))
				continue;

			if (!factors.str().empty())
				factors << " * ";

			factors << n;
			u64 newTotal = total - (total / n);
			total -= (newTotal > 1) ? newTotal : total;
			break;
		}
	}
	return factors.str();
}

void PrimeNumbers::GenerateNumberOfPrimes(const u64 numberOfPrimes)
{
	u64 sequenceFrom = m_PrimeNumbers.back();
	const unsigned long totalPrimeSize = (m_PrimeNumbers.size() + numberOfPrimes);
	while (m_PrimeNumbers.size() < totalPrimeSize)
	{
		sequenceFrom++;
		if (IsPrimeNumber(sequenceFrom))
		{
			m_PrimeNumbers.push_back(sequenceFrom);
		}
	}
}

void PrimeNumbers::GeneratePrimesUpTo(const u64 number)
{
	while (m_PrimeNumbers.back() < number)
	{
		GenerateNumberOfPrimes(1);
	}
	if (m_PrimeNumbers.back() > number)
	{
		m_PrimeNumbers.pop_back();
	}
}