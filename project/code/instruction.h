#pragma once

#include "base_include.h"
#include "register.h"

extern const unordered_map<string, vector<string>> ins_map;

string ins_encode(const vector<string>& token);

string opcode(const string &arg);

string regi(const string &arg);

string const_5(const string &arg);

string const_16(const string &arg);

string offset(const string &arg);

string label(const string &arg);

string target(const string &arg);

string zero_5(const string &arg);

string zero_6(const string &arg);