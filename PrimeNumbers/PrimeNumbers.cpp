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

bool PrimeNumbers::IsDivisibleBy(const long& total, const int division)
{
	if (total %division == 0)
		return true;
	return false;
}

string PrimeNumbers::ShowPrimeSequence(const long& numberOfPrimes)
{
	stringstream outputStream;
	if (numberOfPrimes > 0)
		GenerateNumberOfPrimes(static_cast<int>(numberOfPrimes));
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

string PrimeNumbers::CalculatePrimeFactors(const long& number)
{
	if (!IsPrimeNumber(number))
		return to_string(number) + " is NOT a prime number";
	stringstream factors;
	GeneratePrimesUpTo(number);
	long total = number;
	while (total > static_cast<long>(minimumNumber))
	{
		for (auto n : m_PrimeNumbers)
		{
			if ((n <= number) && (IsDivisibleBy(total, n)))
			{
				factors << n;
				total -= (total / n);
			}
		}
		total = 0;
	}
	return factors.str();
}

void PrimeNumbers::GenerateNumberOfPrimes(const int numberOfPrimes)
{
	int sequenceFrom = (m_PrimeNumbers.size() > 0) ? m_PrimeNumbers.back() : minimumNumber;
	long totalPrimeSize = (m_PrimeNumbers.size() + numberOfPrimes);
	while (static_cast<long>(m_PrimeNumbers.size()) < totalPrimeSize)
	{
		sequenceFrom++;
		if (IsPrimeNumber(sequenceFrom))
			m_PrimeNumbers.push_back(sequenceFrom);
	}
}

void PrimeNumbers::GeneratePrimesUpTo(const long&  number)
{
	if (m_PrimeNumbers.size() < minimumNumber)
		m_PrimeNumbers.push_back(2);
	while (m_PrimeNumbers.back() <= number)
		GenerateNumberOfPrimes(minimumNumber);
	if (m_PrimeNumbers.back() >= number)
		m_PrimeNumbers.pop_back();
}