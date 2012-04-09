#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1

// Colors
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define TEAL    "\033[1;36m"
#define RESET   "\033[0m"

// Logging
#define POS __FILE__ << "::" << __FUNCTION__ << "() line " << __LINE__

#ifdef DEBUG
#include <iostream>
#define LOG(s)   std::cout << BLUE   << "  [LOG] " << RESET << POS << ":\t" << s << RESET << std::endl
#define WARN(s)  std::cout << YELLOW << " [WARN] " << RESET << POS << ":\t" << s << RESET << std::endl
#define ERROR(s) std::cout << RED    << "[ERROR] " << RESET << POS << ":\t" << s << RESET << std::endl
#else
#define LOG(s) ;
#define WARN(s) ;
#define ERROR(s) ;
#endif

#endif