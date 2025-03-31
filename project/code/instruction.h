#pragma once

#include "base_include.h"
#include "register.h"

class Ins
{
public:
    //virtual void init(vector<string> ins) = 0;
};

extern unordered_map<string, vector<string>> ins_map;

class R : public Ins
{
public:
    void parse(const vector<string>& v);
    string bin();
private:
    inline static const string op{"000000"};
    string rs;
    string rt;
    string rd{"00000"};
    string shamt{"00000"};
    string funct;
};

class I : public Ins
{
public:
    void parse(const vector<string>& v);
    string bin();
private:
    string op;
    string rs;
    string rt;
    string constant;
};

class J : public Ins
{
public:
    void parse(const vector<string>& v);
    string bin();
private:
    string op;
    string addr;
};