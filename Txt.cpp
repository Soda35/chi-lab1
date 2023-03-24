#include "Txt.h"

using namespace l1;

Txt::Txt() : strings(nullptr), count(0)
{
}

Txt::Txt(const std::string& file_name) : strings(nullptr), count(0)
{
	std::ifstream file(file_name);
	std::string line; 
	if (file.is_open())
	{
		while (getline(file, line))
		{
			count++;
		}
		strings = new std::string[count];
		file.clear();
		file.seekg(0);
		int i = 0;
		while (getline(file, line))
		{
			strings[i] = line;
		}
		file.close();
	}
	else
	{
		std::cerr << "File hasn't been opened" << std::endl;
	}
}

Txt::Txt(const Txt& other)
{
	strings = new std::string[other.count];
	for (int i = 0; i < other.count; i++)
	{
		strings[i] = other.strings[i];
	}
	count = other.count;
}

Txt::Txt(Txt&& other) noexcept
{
	strings = other.strings;
	count = other.count;

	other.strings = nullptr;
	other.count = 0;
}

Txt Txt::operator=(const Txt& other)
{
	if (this != &other)
	{
		delete[] strings;
		strings = new std::string[other.count];
		for (int i = 0; i < other.count; i++)
		{
			strings[i] = other.strings[i];
		}
		count = other.count;
	}

	return *this;
}

Txt Txt::operator=(Txt&& other) noexcept
{
	delete[] strings;
	strings = other.strings;
	count = other.count;

	other.count = 0;
	other.strings = nullptr;
	
	return *this;
}

Txt::~Txt()
{
	delete[] strings;
}

size_t Txt::size() const 
{
	return count;
}