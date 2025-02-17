# 📥 Input Library

A simple C++ class for handling, cleaning, and validating user input.  
Supports **string formatting** and **unsigned integer conversion** with error handling.

## 📌 Features

✔️ Clean user input by removing leading/trailing spaces.  
✔️ Detect and handle invalid inputs (non-numeric characters, out-of-range values).  
✔️ Convert user input to `unsigned int` safely.  
✔️ Exception-based error management.  

---

## 🚀 Installation

### Clone the repository:
```sh
git clone https://github.com/Holistisme/InputLib.git
cd InputLib
```

### Compile your project:
Make sure to **include Input.hpp** in your C++ project and link the corresponding source files.

```sh
g++ -std=c++98 main.cpp Input.cpp -o my_program
```

---

## 📜 Usage

### **1️⃣ Basic String Input**
```cpp
#include "Input.hpp"
#include <iostream>

int main() {
    Input userInput("Enter your name: ");
    std::cout << "Hello, " << userInput.stringFormat() << "!" << std::endl;
    return 0;
}
```

---

### **2️⃣ Unsigned Integer Conversion**
```cpp
#include "Input.hpp"
#include <iostream>

int main() {
    try {
        Input userInput("Enter a positive number: ");
        unsigned int number = userInput.unsignedIntegerFormat();
        std::cout << "You entered: " << number << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```

---

## 📖 API Reference

### `Input::Input(const std::string &prompt = "")`
- Constructs an `Input` object and retrieves user input.
- **Example:**  
  ```cpp
  Input userInput("Enter your text:");
  ```

### `std::string Input::stringFormat(void) const`
- Returns cleaned user input (without leading/trailing spaces).

### `unsigned int Input::unsignedIntegerFormat(void) const`
- Converts input into an `unsigned int`.
- **Throws:**
  - `std::invalid_argument` → If input is not a valid number.
  - `std::out_of_range` → If the number exceeds `unsigned int` limits.

---

## 📝 License

This project is licensed under the **GNU GPL v3**.  
See [LICENSE](https://www.gnu.org/licenses/gpl-3.0.html) for details.

---

## 👤 Author

**Alexy Heitz** ([@Holistisme](https://github.com/holistisme))  
📧 Email: alexy.pa.heitz@gmail.com  
📆 Created: **2025-02-14** | Last Updated: **2025-02-17**

---

## ⭐ Contributing

If you find any **issues or improvements**, feel free to open a **pull request** or **submit an issue**.

---