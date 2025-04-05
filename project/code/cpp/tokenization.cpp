#include "tokenization.h"

vector<string> line_parsing(string s)
{
    vector<string> result;
    stringstream ss{s};
    string token;
    while(ss >> token)
    {
        if (token[token.size() - 1] == ':')
        {
            label_table.insert({ token, result.size() });
        }
        else if (token[token.size() - 1] == ',')
        {
            result.push_back(token.substr(0, token.size() - 1));
        }
        else if(token[0] == '#')
        {
            return result;
        }
        else if(token[token.size() - 1] == ')')
        {
            int split = token.find('('), l = token.size();
            result.push_back(token.substr(0, split));
            result.push_back(token.substr(split + 1, l - split - 2));
        }
        else
        {
            result.push_back(token);
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
