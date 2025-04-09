#include "tokenization.h"

vector<vector<string>> asm_to_vector(const string& path)
{
    vector<vector<string>> result;
    ifstream file{path};
    string line;
    while(getline(file, line))
    {
        vector<string> temp;
        stringstream ss{ line };
        string token;
        while (ss >> token)
        {
            if (token[token.size() - 1] == ':')
            {
                label_table.insert({ token, result.size() });
            }
            else if (token[token.size() - 1] == ',')
            {
                temp.push_back(token.substr(0, token.size() - 1));
            }
            else if (token[0] == '#')
            {
                break;
            }
            else if (token[token.size() - 1] == ')')
            {
                int split = token.find('('), l = token.size();
                temp.push_back(token.substr(0, split));
                temp.push_back(token.substr(split + 1, l - split - 2));
            }
            else
            {
                temp.push_back(token);
            }
        }
        
        if (!temp.empty()) result.push_back(temp);
    }
    return result;
}
