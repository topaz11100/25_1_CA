#include "instruction.h"

using namespace std;

const vector<string> r_arith = {"000000", "regi", "regi", "regi"};
const vector<string> r_shift = {"000000", "regi", "regi", "const_5"};
const vector<string> r_ja = {"000000", "regi", "00000", "00000"};

const vector<string> i_arith = {"opcode", "regi", "regi", "const_16"};
const vector<string> i_label = {"opcode", "regi", "regi", "label"};
const vector<string> i_memory = {"opcode", "regi", "offset_regi"};
const vector<string> i_lui = {"opcode", "regi", "000000", "label"};

const vector<string> j = {"opcode", "target"};

const unordered_map<string, vector<string>> ins_map = {
    // R-type  funct
    {"add",   r_arith},
    {"sub",   r_arith},
    {"and",   r_arith},
    {"or",    r_arith},
    {"xor",   r_arith},
    {"nor",   r_arith},
    {"slt",   r_shift},
    {"sll",   r_shift},
    {"srl",   r_shift},
    {"jr",    r_ja},
    // I-type  opcode
    {"addi",  i_arith},
    {"andi",  i_arith},
    {"ori",   i_arith},
    {"xori",  i_arith},
    {"lw",    i_memory},
    {"sw",    i_memory},
    {"lui",   i_lui},
    {"slti",  i_arith},
    {"beq",   i_label},
    {"bne",   i_label},
    // J-type  opcode
    {"j",     j},
    {"jal",   j}
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

