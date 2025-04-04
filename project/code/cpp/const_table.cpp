#include "const_table.h"

const unordered_map<string, string> opcode_table = {
    // R-type
    {"add",  "100000"},
    {"sub",  "100010"},
    {"and",  "100100"},
    {"or",   "100101"},
    {"xor",  "100110"},
    {"nor",  "100111"},
    {"slt",  "101010"},
    {"sll",  "000000"},
    {"srl",  "000010"},
    {"jr",   "001000"},
    // I-type
    {"addi", "001000"},
    {"andi", "001100"},
    {"ori",  "001101"},
    {"xori", "001110"},
    {"lw",   "100011"},
    {"sw",   "101011"},
    {"lui",  "001111"},
    {"slti", "001010"},
    {"beq",  "000100"},
    {"bne",  "000101"},
    // J-type
    {"j",    "000010"},
    {"jal",  "000011"}
};

const unordered_map<string, string> regi_table = {
    {"$zero", "00000"},
    {"$at",   "00001"},
    {"$v0",   "00010"},
    {"$v1",   "00011"},
    {"$a0",   "00100"},
    {"$a1",   "00101"},
    {"$a2",   "00110"},
    {"$a3",   "00111"},
    {"$t0",   "01000"},
    {"$t1",   "01001"},
    {"$t2",   "01010"},
    {"$t3",   "01011"},
    {"$t4",   "01100"},
    {"$t5",   "01101"},
    {"$t6",   "01110"},
    {"$t7",   "01111"},
    {"$s0",   "10000"},
    {"$s1",   "10001"},
    {"$s2",   "10010"},
    {"$s3",   "10011"},
    {"$s4",   "10100"},
    {"$s5",   "10101"},
    {"$s6",   "10110"},
    {"$s7",   "10111"},
    {"$t8",   "11000"},
    {"$t9",   "11001"},
    {"$k0",   "11010"},
    {"$k1",   "11011"},
    {"$gp",   "11100"},
    {"$sp",   "11101"},
    {"$fp",   "11110"},
    {"$ra",   "11111"}
};