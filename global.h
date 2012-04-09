#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1

// Logging
#ifdef DEBUG
#include <iostream>
#define LOG(s) std::cout << "\033[1;31m[LOG]\033[0m " << __FILE__ << "::" << __FUNCTION__ << "() line " << __LINE__ << ":\t" << s << std::endl
#else
#define LOG(s) ;
#endif

#endif