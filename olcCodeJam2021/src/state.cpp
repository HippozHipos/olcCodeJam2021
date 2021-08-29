#include "state.h"

const State::States& State::GetCurrentState() noexcept
{
	return current;
}

void State::SetCurrentState(State::States toState) noexcept
{
	current = toState;
}

State::States State::current = State::States::MENU;