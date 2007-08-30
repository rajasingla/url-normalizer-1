#ifndef __PSE_URLNORMALIZATION_H__
#define __PSE_URLNORMALIZATION_H__
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <assert.h>

using namespace std;

class PseUrlNormalization{
    public:
        PseUrlNormalization();
	~PseUrlNormalization();
	void to_lower_case(string &word_str);
	string & add_trailing(string &url, size_t &url_len);
        string &remove_all(string &url);
	string &remove_www(string &url);
	bool url_normalizer(string &url, size_t &url_len);
};

#endif

