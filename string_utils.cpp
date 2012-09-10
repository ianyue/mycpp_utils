#include "string_utils.h"

#include <vector>
#include <string>
#include <cctype>

#include <stdint.h>
#include <stdio.h>

using std::vector;
using std::string;

using std::isspace;

typedef string::const_reverse_iterator const_s_rev_iter;
typedef string::const_iterator const_s_iter;
typedef string::size_type s_size_t;

string to_string(int32_t x)
{
    char str[64];
    sprintf(str, "%d", x);
    return str;
}


int to_int(const string &val, int &result)
{
    char trash;
    int num = sscanf(val.c_str(), "%d%c", &result, &trash);
    
    return 1 == num ? 0 : 1;
}


int to_float(const std::string &val, float &result)
{
    char trash;
    int num = sscanf(val.c_str(), "%f%c", &result, &trash);

    return 1 == num ? 0 : 1;
}


vector<string> split_string(const string &str, const char *separator)
{
    vector<string> result;
    s_size_t prev_pos = 0;
    s_size_t pos = 0;

    while((pos = str.find_first_of(separator, prev_pos)) != string::npos) {
        if(prev_pos < pos) {
            result.push_back(str.substr(prev_pos, pos-prev_pos));
        }
        prev_pos = pos + 1;
    }

    if(prev_pos < str.size()) {
        result.push_back(str.substr(prev_pos));
    }
    return result;
}


string trim_begin(const std::string &str)
{
    
    const_s_iter it;
    for(it = str.begin(); it != str.end(); it++) {
        if(!isspace(*it)) break;
    }

    string result;
    if(it != str.end()) {
        result = string(it, str.end());
    }

    return result;
}


string trim_end(const std::string &str)
{
    const_s_rev_iter r_it;
    for(r_it = str.rbegin(); r_it != str.rend(); r_it++) {
        if(!isspace(*r_it)) break;
    }

    string result;
    if(r_it == str.rend()) return result;
    
    const_s_iter it = r_it.base();
    result = string(str.begin(), it);
    return result;
}
