#include "base_include.h"
#include "label.h"
#include "tokenization.h"
#include "instruction.h"

int main()
{
    string file_path = "resource/token_test.asm";
    
    for (auto& v : asm_to_vector(file_path))
    {
        pc += 1;
        print(v);
        cout << ins_encode(v) << endl;
    }

    return 0;
}