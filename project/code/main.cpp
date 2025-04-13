#include "base_include.h"
#include "label.h"
#include "tokenization.h"
#include "instruction.h"

/*
기본 원리
1. .asm파일을 파싱해서 이차원 벡터에 넣는다
2. 한 줄( = 토큰의 벡터) 씩 읽는다 이때 토큰에 적용할 함수(토큰이 어떻게 인코딩 되는지)
가 미리 정의되어있어 잘 수행된다
3. 인코딩 결과를 .bin에 쓴다
4. 이차원 벡터원소 모두에 2,3을 수행한다

실행 상수
file_path = .asm파일 경로
out_path  = .bin저장 경로
debug     = 콘솔로 자세한 정보 출력할지 결정, 보고싶으면 true, .bin만 출력하려면 false
*/

string file_path = "resource/token_test.asm";
string out_path  = "resource/token_test.bin";
bool debug = true;

//모드 실행
void execute_0(const vector<vector<string>>& ins, ofstream& bin)
{
    for (auto& v : ins)
    {
        PC += 1;
        bin << ins_encode(v) << endl;
    }
}

void execute_1(const vector<vector<string>>& ins, ofstream& bin)
{
    cout << endl << "parsed instruction" << endl;
    print_doubled(ins);
    cout << endl << ".asm label_table\nlabel PC <- table format" << endl;
    print_map(label_table);
    cout << "ins to bin, PC is increased before encoded" << endl;
    for (auto& v : ins)
    {
        PC += 1;
        print(v);
        cout << "  (PC : " << PC << ")" << endl;
        string i = ins_encode(v);
        cout << i << endl;
        bin << i << endl;
    }
    cout << endl << "encode complete .bin created " << out_path << endl << endl;
}

//메인 실행
int main()
{
    //변수 설정
    ofstream bin{ out_path };
    //파싱된 명령어 모음
    vector<vector<string>> parsed_ins = asm_to_vector(file_path);
    //상수에 따라 실행
    if (debug) execute_1(parsed_ins, bin);
    else       execute_0(parsed_ins, bin);

    return 0;
}