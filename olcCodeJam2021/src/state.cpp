#include "state.h"

const State::States& State::GetCurrentState() noexcept
{
	return current;
}

void State::SetCurrentState(State::States current) noexcept
{
	current = current;
}

State::States State::current = State::States::MENU;