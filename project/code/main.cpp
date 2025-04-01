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
            cout << s << ";";
        }
        cout << endl;
    }
}

void printsingle(vector<string> v)
{
    for(const string& c : v)
    {
        cout << c << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<string>> file = asm_to_vector("token_test.asm");
    print(file);
    cout << endl;
    
    for(const vector<string>& v: file)
    {
        printsingle(v);
        string s = ins_encode(v);
        cout << s << endl;
    }
        
    return 0;
}