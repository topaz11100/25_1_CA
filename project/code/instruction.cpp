#include "instruction.h"

using namespace std;

unordered_map<string, vector<string>> ins_map = {
    // R-type  funct
    {"add",   {"R", "100000"}},
    {"sub",   {"R", "100010"}},
    {"and",   {"R", "100100"}},
    {"or",    {"R", "100101"}},
    {"xor",   {"R", "100110"}},
    {"nor",   {"R", "100111"}},
    {"slt",   {"R", "101010"}},
    {"sll",   {"R", "000000"}},
    {"srl",   {"R", "000010"}},
    {"jr",    {"R", "001000"}},
    // I-type  opcode
    {"addi",  {"I", "001000"}},
    {"andi",  {"I", "001100"}},
    {"ori",   {"I", "001101"}},
    {"xori",  {"I", "001110"}},
    {"lw",    {"I", "100011"}},
    {"sw",    {"I", "101011"}},
    {"lui",   {"I", "001111"}},
    {"slti",  {"I", "001010"}},
    {"beq",   {"I", "000100"}},
    {"bne",   {"I", "000101"}},
    // J-type  opcode
    {"j",     {"J", "000010"}},
    {"jal",   {"J", "000011"}}
};

string str_to_5bit(const string& s)
{
    bitset<5> bin{s};
    return bin.to_string();
}

string str_to_16bit(const string& s)
{
    bitset<16> bin{s};
    return bin.to_string();
}


void R::parse(const vector<string>& v)
{
    bool is_shift = v[0] == "sll" || v[0] == "srl" || v[0] == "sra";

    funct = ins_map[v[0]][1];
    rs = regi_table.at(v[1]);

    if (v[0] == "jr")
    {
        rt = str_to_5bit("0");
        return;
    }

    rt = regi_table.at(v[2]);
    
    if(!is_shift) rd = regi_table.at(v[3]);
    else shamt = str_to_5bit(v[3]);
}

string R::bin()
{
    return op + rs + rt + rd + shamt + funct;
}

void I::parse(const vector<string>& v)
{
    op = ins_map[v[0]][1];
    constant = str_to_16bit(v[3]);
}

string I::bin()
{
    return op + rs + rt + constant;
}

