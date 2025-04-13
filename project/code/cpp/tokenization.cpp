#include "tokenization.h"

vector<vector<string>> asm_to_vector(const string& path)
{
    //결과
    vector<vector<string>> result;
    ifstream file{path};
    string line;
    //한줄 씩 읽음
    while (getline(file, line))
    {
        //한 줄 에 대응하는 벡터
        vector<string> temp;
        stringstream ss{ line };
        string token;
        //특정 줄에서 스트림으로 읽음
        while (ss >> token)
        {
            //라벨 토큰일 경우
            if (token[token.size() - 1] == ':')
            {
                //라벨테이블에 몇번째 명령어인지 추가
                label_table.insert({ token.substr(0, token.size() - 1), result.size() });
            }
            //$s0, 같이 일반토큰 + ,가 마지막인 경우
            else if (token[token.size() - 1] == ',')
            {
                //임시 벡터 추가 , 제거
                temp.push_back(token.substr(0, token.size() - 1));
            }
            //주석인 경우
            else if (token[0] == '#')
            {
                //건너뜀
                break;
            }
            //4($sp) 같은 오프셋 토큰인 경우
            else if (token[token.size() - 1] == ')')
            {
                //오프셋과 레지스터 분리, 저장
                int split = token.find('('), l = token.size();
                temp.push_back(token.substr(0, split));
                temp.push_back(token.substr(split + 1, l - split - 2));
            }
            //add같은 일반 토큰은 그냥 저장
            else
            {
                temp.push_back(token);
            }
        }
        // 4 같은 즉시값 있으면 저장
        if (!temp.empty()) result.push_back(temp);
    }
    return result;
}
