#pragma once

#include "base_include.h"
#include "label.h"

//.asm을 이차원벡터로 토큰화
vector<vector<string>> asm_to_vector(const string& path);