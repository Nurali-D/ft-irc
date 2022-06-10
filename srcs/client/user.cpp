#include "user.hpp"
#include "../libraryHeaders.hpp"

User::User(int fd, struct sockaddr_in address) : fd(fd), address(address) {}

User::~User() {}



