#include "script.h"

Script::Script()
{
	script.push_back(s1);
	script.push_back(gloo1); 
	
	script.push_back(s2);
	script.push_back(gloo2);
	
	script.push_back(s3);
	script.push_back(gloo3);

	script.push_back(s4);
	script.push_back(gloo4);

	script.push_back(s5);

	script.push_back(s6);
}

const std::vector<std::string>& Script::GetScript() noexcept
{
	return script;
}

std::string Script::s1 = 
"Hello there Gloo, the blob monster.";

std::string Script::gloo1 = 
"Woow, what's that voice I hear in my head?";

std::string Script::s2 =
"I understand that you are consfused\n"
"right now, but we haven't got time\n"
"for that. You are in danger.";

std::string Script::gloo2 = 
"Me? What kind of danger?";

std::string Script::s3 = 
"Let me explain...\n"
"You are actually living in a simulation\n"
"and I am the creator of it. Recently I\n"
"accepted a pull request to the codebase\n"
"without realising that It had a bug in it...";

std::string Script::gloo3 = 
"Ok...? And I fit into all this how?";

std::string Script::s4 =
"The bug causes fluctuations in time\n"
"such that what you see and what you\n"
"experience are different. Currently,\n"
"your vision is two seconds into the\n"
"future and your physical body is lagging\n"
"two seconds behind that.";

std::string Script::gloo4 =
"What are you talking about? Who are you?";

std::string Script::s5 =
"As I said... we haven't got time for that\n"
"The time lag is increasing as we speak.\n"
"Shooting others seems to decrease the lag\n"
"although I cannot explain why this\n"
"happens myself. Be careful because there\n"
"will be others trying to shoot you too!\n"
"If you let the lag cross a certain-\n";

std::string Script::s6 = 
"threshold, which seems to be 5, you will\n"
"lose consciousness and die.\n"
"One last time, remember that you cannot\n"
"trust you eyes... \n\n\n"
"I will take my leave now. Good luck.";



