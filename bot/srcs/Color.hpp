#include "../headers/libraryHeaders.hpp"

#ifndef COLOR_HPP
# define COLOR_HP

class Color
{
private:
	static const char c;
	static const std::string code;
	static const std::string BLUE;
	static const std::string DGREEN;
	static const std::string RED;
	static const std::string BROWN;
	static const std::string VIOLET;
	static const std::string ORANGE;
	static const std::string YELLOW;
	static const std::string LGREEN;
	static const std::string SKYBLUE;
	static const std::string PINK;

public:
	Color();
	~Color();
	static std::string turnBlue(const std::string &text);
	static std::string turnDGreen(const std::string &text);
	static std::string turnRed(const std::string &text);
	static std::string turnBrown(const std::string &text);
	static std::string turnViolet(const std::string &text);
	static std::string turnOrange(const std::string &text);
	static std::string turnYellow(const std::string &text);
	static std::string turnLGreen(const std::string &text);
	static std::string turnSkyBlue(const std::string &text);
	static std::string turnPink(const std::string &text);

};

#endif