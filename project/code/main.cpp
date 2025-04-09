#include "base_include.h"
#include "label.h"
#include "tokenization.h"
#include "instruction.h"

void print(const vector<vector<string>>& v)
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

void printsingle(const vector<string>& v)
{
    for(const string& c : v)
    {
        cout << c << " ";
    }
    cout << endl;
}

void print_label(const unordered_map<string, int>& l)
{
    for (auto& x : l)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    string file_path = "resource/token_test.asm";
    vector<vector<string>> file = asm_to_vector(file_path);
    print(file);
    print_label(label_table);

    
    for (const vector<string>& v : file)
    {
        printsingle(v);
        string s = ins_encode(v);
        cout << s << endl;
    }
    

    return 0;
}