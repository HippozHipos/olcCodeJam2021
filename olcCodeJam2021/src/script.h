#pragma once
#include <vector>
#include <string>

struct Script
{
public:
	Script();
	const std::vector<std::string>& GetScript() noexcept;

private:
	std::vector<std::string> script;

private:
	static std::string s1;
	static std::string gloo1;
	static std::string s2;
	static std::string gloo2;
	static std::string s3;
	static std::string gloo3;
	static std::string s4;
	static std::string gloo4;
	static std::string s5;
	static std::string s6;
};