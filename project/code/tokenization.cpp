#include "tokenization.h"

vector<string> line_parsing(string s)
{
    vector<string> result;
    stringstream ss{s};
    string temp_str; char temp_char;
    while(ss >> temp_str)
    {
        if (temp_str[temp_str.size() - 1] == ',')
        {
            result.push_back(temp_str.substr(0, temp_str.size() - 1));
        }
        else if(temp_str[0] == '#')
        {
            return result;
        }
        else if(temp_str[temp_str.size() - 1] == ')')
        {
            int split = temp_str.find('('), l = temp_str.size();
            result.push_back(temp_str.substr(0, split));
            result.push_back(temp_str.substr(split + 1, l - split - 2));
        }
        else
        {
            result.push_back(temp_str);
        }
    }
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
