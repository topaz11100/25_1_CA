#include "base_include.h"
#include "tokenization.h"
#include "instruction.h"
#include "register.h"

void print(vector<vector<string>> v)
{
    cout << endl;
    for (const vector<string>& a:v)
    {
        for (const string& s:a)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<string>> parsed = asm_to_vector("token_test.asm");
    print(parsed);

    cout << ins_map[parsed[0][0]][0] << ' ' << ins_map[parsed[0][0]][1];

    return 0;
}