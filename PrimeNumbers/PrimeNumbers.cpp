#include "PrimeNumbers.h"
#include <sstream>

using namespace ::std;

PrimeNumbers::PrimeNumbers()
{
	m_PrimeNumbers.push_back(m_smallestPrime);
}

bool PrimeNumbers::IsPrimeNumber(const u64 number)
{
	u64 largestPrime = sqrt(number);
	for (u64 i = m_smallestPrime; i <= largestPrime; i++)
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
	if (numberOfPrimes > 0)
	{
		u64 totalNumberOfPrimes = (numberOfPrimes - m_PrimeNumbers.size());
		GenerateNumberOfPrimes(totalNumberOfPrimes);
	}
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

string PrimeNumbers::Factorise(const u64 number)
{
	stringstream factors;
	u64 total = number;
	u64 maxPrime = (number >= 9) ? sqrt(total) : total;
	GeneratePrimesUpTo(number);
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

void PrimeNumbers::GenerateNumberOfPrimes(u64 numberOfPrimes)
{
	u64 sequenceFrom = m_PrimeNumbers.back();
	while (numberOfPrimes > 0)
	{
		sequenceFrom++;
		if (IsPrimeNumber(sequenceFrom))
		{
			m_PrimeNumbers.push_back(sequenceFrom);
			numberOfPrimes--;
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