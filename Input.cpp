#include "Input.hpp"

/* ############################################################################################## */

/**
 * @file Input.cpp
 * @brief Implementation of the Input class.
 * 
 * This file contains the function implementations for the Input class,
 * which provides user input handling and validation.
 * 
 * @author aheitz
 * @date Created: 2025-02-14
 * @date Last Modified: 2025-02-17
 */

/* ############################################################################################## */

/*
 * This file is part of the Input library.
 *
 * Copyright (C) 2025 aheitz <alexy.pa.heitz@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

/* ############################################################################################## */

/**
 * @brief Constructs an Input object and retrieves user input.
 * @param prompt The message displayed before input request.
 */
Input::Input(const std::string &prompt) : _userInput(setUserInput(prompt)) {}

/**
 * @brief Copy constructor.
 * @param source Input object to copy from.
 */
Input::Input(const Input &source) : _userInput(source._userInput) {}

/**
 * @brief Assignment operator.
 * @param source Input object to assign from.
 * @return Reference to the assigned object.
 */
Input &Input::operator=(const Input &source) {
	if (this != &source)
		_userInput = source._userInput;
	return *this;
}

/**
 * @brief Destructor.
 */
Input::~Input(void) {}

/* ############################################################################################## */

/**
 * @brief Reads and sanitizes user input.
 * 
 * This function continuously prompts the user for input until a valid entry is provided.
 * It removes leading and trailing whitespace and handles input errors gracefully.
 * The function allows empty input unless modified.
 * 
 * @param prompt The message displayed before input request.
 * @return std::string The cleaned input string.
 * 
 * @throws std::runtime_error If input is interrupted (e.g., Ctrl+D).
 */
std::string Input::setUserInput(const std::string &prompt) {
	while (true) {
		std::string input;

		// 🔹 Displays prompt if not empty
		if (!prompt.empty())
			std::cout << prompt << std::endl;

		// 🔹 Recovers user input
		std::getline(std::cin, input);

		// 🔹 Checks if input interrupted (Ctrl+D)
		if (std::cin.eof())
			throw std::runtime_error("❌ Input interrupted (Ctrl+D).");

		// 🔹 Checks for input errors
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "❗ Error retrieving user data. Please try again." << std::endl;
			continue;
		}

		// 🔹 Prevents input of control characters (directional arrows, etc.)
		if (input.find('\033') != std::string::npos) {
			std::cerr << "❗ The input should not be a signal. Please try again." << std::endl;
			continue;
		}

		// 🔹 Cleans spaces/tabs at beginning and end
		size_t start = input.find_first_not_of(" \t");
		size_t end	 = input.find_last_not_of(" \t");

		// 🔹 Returns cleaned input
		return start != std::string::npos ? input.substr(start, end - start + 1) : "";
	}
}

/* ############################################################################################## */

/**
 * @brief Returns the cleaned user input as a string.
 * 
 * This function returns the sanitized input string.
 * 
 * @return const std::string& The cleaned input.
 */
const std::string &Input::stringFormat(void) const { return _userInput; }

/**
 * @brief Converts and validates user input as an unsigned integer.
 * 
 * This function ensures the input is a valid unsigned integer.
 * If the input is invalid, it throws an appropriate exception.
 * 
 * @return unsigned int The converted number if valid.
 * 
 * @throws std::invalid_argument If the input is not a valid unsigned integer.
 * @throws std::out_of_range If the number exceeds `unsigned int` limits.
 */
unsigned int Input::unsignedIntegerFormat(void) const {
	// 🔹 Checks if the entry is empty or just a “+”
	if (_userInput.empty() || (_userInput.size() == 1 && _userInput[0] == '+'))
		throw std::invalid_argument("❗ Input is not a valid unsigned integer (empty or only '+').");

	// 🔹 Checks that all characters are digits
	for (size_t i = (_userInput[0] == '+' ? 1 : 0); i < _userInput.size(); i++)
		if (!std::isdigit(_userInput[i]))
			throw std::invalid_argument("❗ Input contains non-numeric characters.");

	// 🔹 Converts input to `unsigned long`
	errno					 = 0;
	char		  *endptr	 = NULL;
	unsigned long conversion = strtoul(_userInput.c_str(), &endptr, 10);

	// 🔹 Checks if conversion failed
	if (errno == ERANGE || *endptr)
		throw std::invalid_argument("❗ Input conversion failed: Not a valid number.");

	// 🔹 Checks that conversion is within `unsigned int` limits
	if (conversion > std::numeric_limits<unsigned int>::max())
		throw std::out_of_range("❗ Input is too large for an unsigned int.");

	// ✅ Returns the validated conversion directly
	return static_cast<unsigned int>(conversion);
}