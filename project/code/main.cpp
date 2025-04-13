#include "base_include.h"
#include "label.h"
#include "tokenization.h"
#include "instruction.h"

int main()
{
    string file_path = "resource/token_test.asm";
    string out_path = "resource/bin_test.bin";

    ofstream bin{ out_path };

    vector<vector<string>> a = asm_to_vector(file_path);
    print_doubled(a);
    cout << endl;
    print_map(label_table);
    for (auto& v : a)
    {
        pc += 1;
        print(v);
        string i = ins_encode(v);
        cout << i << endl;
        bin << i << endl;
    }

    return 0;
}