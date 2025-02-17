#pragma once

/* ############################################################################################## */

/**
 * @file Input.hpp
 * @brief Declaration of the Input class for handling user input.
 * 
 * The Input class provides methods to retrieve, clean, and validate user input.
 * It supports conversion to an unsigned integer with error handling.
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

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>

/* ############################################################################################## */

/**
 * @brief Handles user input retrieval and conversion.
 * 
 */
class Input {
	private:
		std::string _userInput;

		/**
		 * @brief Reads and sanitizes user input.
		 * @param prompt The message displayed before input request.
		 * @return The cleaned input.
		 */
		std::string setUserInput(const std::string &prompt);
	public:
		explicit Input(const std::string &prompt = "");
		Input(const Input &source);
		Input &operator=(const Input &source);
		~Input(void);

		/**
		 * @brief Returns input as a cleaned string.
		 */
		const std::string &stringFormat(void) const;

		/**
		 * @brief Converts user input to an unsigned integer.
		 * @throws std::invalid_argument If input is not a valid number.
		 * @throws std::out_of_range If the number exceeds `unsigned int` limits.
		 */
		unsigned int unsignedIntegerFormat(void) const;
};