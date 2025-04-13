#include "instruction.h"

//타입 설정
using exec_T = string(*) (const string&);
using exec_seq_T = vector<pair<exec_T, int>>;

//명령어에 따라 실행할 함수 정의
//opcode 인코딩
string opcode(const string& arg)
{
    return opcode_table.at(arg);
}
//레지스터 인코딩
string regi(const string& arg)
{
    return regi_table.at(arg);
}
//즉시값 5비트 인코딩
string const_5(const string& arg)
{
    bitset<5> bin( stoi(arg) );
    return bin.to_string();
}
//즉시값 16비트 인코딩
string const_16(const string& arg)
{
    bitset<16> bin( stoi(arg) );
    return bin.to_string();
}
//I형 명령어용 주소 인코딩(PC-related-addressing)
string label(const string& arg)
{
    int offset = label_table.at(arg) - (PC - 1);
    return const_16(to_string(offset));
}
//J형 명령어용 주소 인코딩(direct-jump-addressing)
string target(const string& arg)
{
    bitset<26> bin( label_table.at(arg) );
    return bin.to_string();
}
//0반환
string zero_5(const string& arg)
{
    return "00000";
}
string zero_6(const string& arg)
{
    return "000000";
}

//명령어에 종류에 따른 한 명령어 줄에 수행할(인코딩할) 함수열,
//실행할 함수와 명령어 한 줄의 토큰 중 어느번째 토큰을 인수로 가질지 정의
const exec_seq_T r_arith = {
    {zero_6, -1},  // opcode
    {regi, 2},     // rs = $s
    {regi, 3},     // rt = $t
    {regi, 1},     // rd = $d
    {zero_5, -1},  // shamt
    {opcode, 0}    // funct
};
const exec_seq_T r_shift = {
    {zero_6, -1},  // opcode
    {zero_5, -1},  // rs
    {regi, 2},     // rt = $t
    {regi, 1},     // rd = $d
    {const_5, 3},  // shamt
    {opcode, 0}    // funct
};
const exec_seq_T r_ja = {
    {zero_6, -1},  // opcode
    {regi, 1},     // rs
    {zero_5, -1},  // rt
    {zero_5, -1},  // rd
    {zero_5, -1},  // shamt
    {opcode, 0}    // funct
};
const exec_seq_T i_arith = {
    {opcode, 0},   // opcode
    {regi, 2},     // rs = $s
    {regi, 1},     // rt = $t
    {const_16, 3}  // immediate
};
const exec_seq_T i_label = {
    {opcode, 0},  // opcode
    {regi, 1},    // rs
    {regi, 2},    // rt
    {label, 3}    // label offset
};
const exec_seq_T i_mem = {
    {opcode, 0},  // opcode
    {regi, 3},    // rs = base ($s) → in offset()
    {regi, 1},    // rt = $t
    {const_16, 2}   // full offset($s) 처리
};
const exec_seq_T i_lui = {
    {opcode, 0},   // opcode
    {regi, 1},     // rt
    {zero_5, -1},  // rs = 0
    {const_16, 2}  // immediate
};
const exec_seq_T j = {
    {opcode, 0},  // opcode
    {target, 1}   // target address
};

//명령어와 실행할 함수열 정의
const unordered_map<string, exec_seq_T> exec_table = {
    {"add", r_arith},
    {"sub", r_arith},
    {"and", r_arith},
    {"or",  r_arith},
    {"xor", r_arith},
    {"nor", r_arith},
    {"slt", r_arith},
    {"sll", r_shift},
    {"srl", r_shift},
    {"jr",  r_ja},

    {"addi", i_arith},
    {"andi", i_arith},
    {"ori",  i_arith},
    {"xori", i_arith},
    {"lw",   i_mem},
    {"sw",   i_mem},
    {"lui",  i_lui},
    {"slti", i_arith},
    {"beq",  i_label},
    {"bne",  i_label},

    {"j",    j},
    {"jal",  j}
};

//명령어 한 줄을 받아 토큰들을 읽어가며 함수열(인코딩) 실행
string ins_encode(const vector<string>& token)
{
    string result;
    //실행 함수열 결정
    const exec_seq_T& ins = exec_table.at(token[0]);

    for (pair<exec_T, int> p : ins)
    {
        //정의된 함수와 인수로 인코딩
        if (p.second == -1) result += p.first("");
        else result += p.first(token[p.second]);
    }

    return result;
}
