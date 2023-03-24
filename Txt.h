#pragma once
#include<fstream>
#include<iostream>
#include<string>

namespace l1 {
	class Txt
	{
	private:
		std::string* strings;
		size_t count;

	public:
		Txt();
		~Txt();

		explicit Txt(const std::string& file_name);

		Txt(const Txt& other);
		Txt(Txt&& other) noexcept;
		Txt operator=(const Txt& other);
		Txt operator=(Txt&& other) noexcept;

		size_t size() const;
	};
}