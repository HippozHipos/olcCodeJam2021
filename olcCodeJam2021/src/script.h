#pragma once
#include <vector>
#include <string>

//gloo = player
//s = simulator

struct Script
{
public:
	Script();
	static const std::vector<std::string>& GetScript() noexcept;

private:
	static std::vector<std::string> script;

private:
	static std::string gloo1;
	static std::string s1;
	static std::string gloo2;
	static std::string s2;
	static std::string gloo3;
	static std::string s3;
};