#include "script.h"

Script::Script()
{
	script.push_back(s1);
	script.push_back(gloo1); 
	
	script.push_back(s2);
	script.push_back(gloo2);
	
	script.push_back(s3);
	script.push_back(gloo3);
}

const std::vector<std::string>& Script::GetScript() noexcept
{
	return script;
}

std::vector<std::string> Script::script;

std::string Script::s1 = "";

std::string Script::gloo1 = "";

std::string Script::s2 = "";

std::string Script::gloo2 = "";

std::string Script::s3 = "";

std::string Script::gloo3 = "";



