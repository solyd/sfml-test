//
// Created by solyd on 11/2/16.
//

#ifndef SFML_TEST_LOG_H
#define SFML_TEST_LOG_H

#include <ostream>

#define LOG(ostream, prefix, ...) \
do {\
  output(ostream, prefix, __VA_ARGS__); \
} while(false)

#define LOG_err(...) LOG(std::cerr, "[ERROR]", __VA_ARGS__)
#define LOG_debug(...) LOG(std::cout, "[DEBUG]", __VA_ARGS__)
#define LOG_info(...) LOG(std::cout, "[INFO]", __VA_ARGS__)

template<typename T>
void output(std::ostream& out, T&& arg) {
	out << arg << "\n";
}

template<typename T, typename... Ts>
void output(std::ostream& out, T&& arg, Ts&&... rest) {
	out << arg << " ";
	output(out, rest...);
}


#endif //SFML_TEST_LOG_H
