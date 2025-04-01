#include "instruction.h"

using namespace std;

const vector<string> r_arith = {"zero_6", "regi", "regi", "regi", "opcode"};
const vector<string> r_shift = {"zero_6", "regi", "regi", "const_5", "opcode"};
const vector<string> r_ja = {"zero_6", "regi", "zero_5", "zero_5", "opcode"};

const vector<string> i_arith = {"opcode", "regi", "regi", "const_16"};
const vector<string> i_label = {"opcode", "regi", "regi", "label"};
const vector<string> i_mem = {"opcode", "regi", "offset"};
const vector<string> i_lui = {"opcode", "regi", "zero_6", "label"};

const vector<string> j = {"opcode", "target"};

const unordered_map<string, pair<string, vector<string>>> ins_table = {
    // R-type  funct
    {"add", {"100000", r_arith}},
    {"sub", {"100010", r_arith}},
    {"and", {"100100", r_arith}},
    {"or", {"100101", r_arith}},
    {"xor", {"100110", r_arith}},
    {"nor", {"100111", r_arith}},
    {"slt", {"101010", r_shift}},
    {"sll", {"000000", r_shift}},
    {"srl", {"000010", r_shift}},
    {"jr", {"001000", r_ja}},

    // I-type  opcode
    {"addi", {"001000", i_arith}},
    {"andi", {"001100", i_arith}},
    {"ori", {"001101", i_arith}},
    {"xori", {"001110", i_arith}},
    {"lw", {"100011", i_mem}},
    {"sw", {"101011", i_mem}},
    {"lui", {"001111", i_lui}},
    {"slti", {"001010", i_arith}},
    {"beq", {"000100", i_label}},
    {"bne", {"000101", i_label}},

    // J-type  opcode
    {"j", {"000010", j}},
    {"jal", {"000011", j}}};

void opcode(string &code, const string &arg)
{
    code += ins_table.at(arg).first;
}
void regi(string &code, const string &arg)
{
    code += regi_table.at(arg);
}
void const_5(string &code, const string &arg)
{
    bitset<5> bin{static_cast<long long unsigned int>(stoi(arg))};
    code += bin.to_string();
}
void const_16(string &code, const string &arg)
{
    bitset<16> bin{static_cast<long long unsigned int>(stoi(arg))};
    code += bin.to_string();
}
void offset(string &code, const string &arg)
{
    int split = arg.find('('), l = arg.size();
    bitset<16> bin{static_cast<long long unsigned int>(stoi(arg.substr(0, split)))};
    string offnum = bin.to_string();
    string regi = arg.substr(split + 1, l - split - 2);
    code += offnum + regi_table.at(regi);
}
void label(string &code, const string &arg)
{
}
void target(string &code, const string &arg)
{
}
void zero_5(string &code, const string &arg) { code += "00000"; }
void zero_6(string &code, const string &arg) { code += "000000"; }

const unordered_map<string, void (*)(std::string &, const std::string &)> ins_func = {{"opcode", opcode},
                                                                                      {"regi", regi},
                                                                                      {"const_5", const_5},
                                                                                      {"offset", offset},
                                                                                      {"const_16", const_16},
                                                                                      {"label", label},
                                                                                      {"target", target},
                                                                                      {"zero_5", zero_5},
                                                                                      {"zero_6", zero_6}};



string parse(const vector<string>& token)
{
    string result;
    const vector<string>& ins = ins_table.at(token[0]).second;
    for (int i = 0; i < token.size(); i += 1)
    {
        ins_func.at(ins[i])(result, token[i]);
    }
    return result;
}
