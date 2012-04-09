#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1

#define POS __FILE__ << "::" << __FUNCTION__ << "() line " << __LINE__

// Logging
#ifdef DEBUG
#include <iostream>
#define LOG(s)   std::cout << "  \033[1;34m[LOG]\033[0m " << POS << ":\t" << s << std::endl
#define WARN(s)  std::cout << " \033[1;33m[WARN]\033[0m " << POS << ":\t" << s << std::endl
#define ERROR(s) std::cout << "\033[1;31m[ERROR]\033[0m " << POS << ":\t" << s << std::endl
#else
#define LOG(s) ;
#define WARN(s) ;
#define ERROR(s) ;
#endif

#endif