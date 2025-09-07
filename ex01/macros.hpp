#ifndef MACROS_HPP
#define MACROS_HPP

#include <iostream>

#define CLEAR_SCREEN "\033[2J\033[H"
#define BOLD_TEXT(text) "\033[1m" text "\033[0m"
#define ENTER(text) BOLD_TEXT("Enter " text ": " )

std::string getInput(const std::string& prompt);
std::string truncateString(const std::string& str, size_t width);

#endif