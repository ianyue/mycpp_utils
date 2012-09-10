/**
 *
 */
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/**
 *  HadoopUtils
 */

#include <string>
#include <vector>

#include <stdint.h>


std::string to_string(::int32_t);


int to_int(const std::string &, int &);


int to_float(const std::string &, float &);


std::vector<std::string> split_string(const std::string &, const char *);


std::string trim_begin(const std::string &);

std::string trim_end(const std::string &);

#endif
