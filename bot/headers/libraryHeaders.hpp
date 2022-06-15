#ifndef LIBRARYHEADERS_HPP
# define LIBRARYHEADERS_HPP

# include <sys/socket.h>
# include <sys/un.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
#if defined(__linux__)
	# include </usr/include/kqueue/sys/event.h> //Linux
#elif
	# include <sys/event.h> //Macos
#endif
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <cstdlib>
# include <cstring>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <string>
# include <iterator>
# include <algorithm>
# include <vector>
# include <map>
# include <sstream>
# include <ctime>

# include "rpl_codes.hpp"

#endif
