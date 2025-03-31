#include "tokenization.h"

vector<string> line_parsing(string s)
{
    vector<string> result;
    stringstream ss{s};
    string temp_str; char temp_char;
    while(ss.get(temp_char))
    {
        switch (temp_char)
        {
        case ' ':
            result.push_back(temp_str);
            temp_str.clear();
            break;
        case ',':
            continue;
        case '#':
            temp_str.clear();
            return result;
        default:
            temp_str += temp_char;
        }
    }
    if (!temp_str.empty()) result.push_back(temp_str);
    return result;
}

vector<vector<string>> asm_to_vector(const string& path)
{
    vector<vector<string>> result;
    ifstream file{path};
    string line;
    while(getline(file, line))
    {
        vector<string> temp = line_parsing(line);
        if (!temp.empty()) result.push_back(temp);
    }
    return result;
}
