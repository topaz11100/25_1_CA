#include "instruction.h"

using namespace std;

using ins_func_type = string (*) (const string &);

const vector<pair<ins_func_type, int>> r_arith = {
    {zero_6, -1},  // opcode
    {regi, 2},     // rs = $s
    {regi, 3},     // rt = $t
    {regi, 1},     // rd = $d
    {zero_5, -1},  // shamt
    {opcode, 0}    // funct
};
const vector<pair<ins_func_type, int>> r_shift = {
    {zero_6, -1},  // opcode
    {zero_5, -1},  // rs
    {regi, 2},     // rt = $t
    {regi, 1},     // rd = $d
    {const_5, 3},  // shamt
    {opcode, 0}    // funct
};
const vector<pair<ins_func_type, int>> r_ja = {
    {zero_6, -1},  // opcode
    {regi, 1},     // rs
    {zero_5, -1},  // rt
    {zero_5, -1},  // rd
    {zero_5, -1},  // shamt
    {opcode, 0}    // funct
};
const vector<pair<ins_func_type, int>> i_arith = {
    {opcode, 0},   // opcode
    {regi, 2},     // rs = $s
    {regi, 1},     // rt = $t
    {const_16, 3}  // immediate
};
const vector<pair<ins_func_type, int>> i_label = {
    {opcode, 0},  // opcode
    {regi, 1},    // rs
    {regi, 2},    // rt
    {label, 3}    // label offset
};
const vector<pair<ins_func_type, int>> i_mem = {
    {opcode, 0},  // opcode
    {regi, 3},    // rs = base ($s) → in offset()
    {regi, 1},    // rt = $t
    {const_16, 2}   // full offset($s) 처리
};
const vector<pair<ins_func_type, int>> i_lui = {
    {opcode, 0},   // opcode
    {regi, 1},     // rt
    {zero_5, -1},  // rs = 0
    {const_16, 2}  // immediate
};
const vector<pair<ins_func_type, int>> j = {
    {opcode, 0},  // opcode
    {target, 1}   // target address
};


const unordered_map< string, pair< string, vector<pair<ins_func_type, int>> > > ins_table = {
    // R-type  funct
    {"add", {"100000", r_arith}},
    {"sub", {"100010", r_arith}},
    {"and", {"100100", r_arith}},
    {"or",  {"100101", r_arith}},
    {"xor", {"100110", r_arith}},
    {"nor", {"100111", r_arith}},
    {"slt", {"101010", r_shift}},
    {"sll", {"000000", r_shift}},
    {"srl", {"000010", r_shift}},
    {"jr",  {"001000", r_ja}},

    // I-type  opcode
    {"addi", {"001000", i_arith}},
    {"andi", {"001100", i_arith}},
    {"ori",  {"001101", i_arith}},
    {"xori", {"001110", i_arith}},
    {"lw",   {"100011", i_mem}},
    {"sw",   {"101011", i_mem}},
    {"lui",  {"001111", i_lui}},
    {"slti", {"001010", i_arith}},
    {"beq",  {"000100", i_label}},
    {"bne",  {"000101", i_label}},

    // J-type  opcode
    {"j",   {"000010", j}},
    {"jal", {"000011", j}}
};

string target(const string& arg)
{
    bitset<22> bin{ static_cast<long long unsigned int>(stoi(arg)) };
    return bin.to_string();
}

string opcode(const string &arg)
{
    return ins_table.at(arg).first;
}
string regi(const string &arg)
{
    return regi_table.at(arg);
}
string const_5(const string &arg)
{
    bitset<5> bin{static_cast<long long unsigned int>(stoi(arg))};
    return bin.to_string();
}
string const_16(const string &arg)
{
    bitset<16> bin{static_cast<long long unsigned int>(stoi(arg))};
    return bin.to_string();
}
string label(const string &arg)
{

}
string target(const string &arg)
{

}
string zero_5(const string &arg)
{
    return "00000";
}
string zero_6(const string &arg)
{
    return "000000";
}

string ins_encode(const vector<string>& token)
{
    string result;
    const vector<pair<ins_func_type, int>>& ins = ins_table.at(token[0]).second;

    for (pair<ins_func_type, int> p : ins)
    {
        if (p.second == -1) result += p.first("");
        else result += p.first(token[p.second]);
    }

    return result;
}
