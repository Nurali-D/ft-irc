#include "Color.hpp"

	const char Color::c = 3;
	const std::string Color::code(1, c);
	const std::string Color::BLUE = code + "2";
	const std::string Color::DGREEN = code + "3";
	const std::string Color::RED = code + "4";
	const std::string Color::BROWN = code + "5";
	const std::string Color::VIOLET = code + "6";
	const std::string Color::ORANGE = code + "7";
	const std::string Color::YELLOW = code + "8";
	const std::string Color::LGREEN = code + "9";
	const std::string Color::SKYBLUE = code + "10";
	const std::string Color::PINK = code + "13";

	Color::Color() {}

	Color::~Color() {}

	std::string Color::turnBlue(const std::string &text) {
		return (BLUE + text);
	}

	std::string Color::turnDGreen(const std::string &text) {
		return DGREEN + text;
	}

	std::string Color::turnRed(const std::string &text) {
		return RED + text;
	}

	std::string Color::turnBrown(const std::string &text) {
		return BROWN + text;
	}

	std::string Color::turnViolet(const std::string &text) {
		return VIOLET + text;
	}

	std::string Color::turnOrange(const std::string &text) {
		return ORANGE + text;
	}

	std::string Color::turnYellow(const std::string &text) {
		return YELLOW + text;
	}

	std::string Color::turnLGreen(const std::string &text) {
		return LGREEN + text;
	}

	std::string Color::turnSkyBlue(const std::string &text) {
		return SKYBLUE + text;
	}

	std::string Color::turnPink(const std::string &text) {
		return PINK + text;
	}
