#ifndef __INVALSTATE_H
#define __INVALSTATE_H
#include <exception>
#include <string>

class InvalidScan {
    std::string message;

    public:
    InvalidScan(std::string message): message{message} {};

    const std::string what() const { return message; };
};
#endif