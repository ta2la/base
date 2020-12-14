//
// Copyright (C) 2020 Petr Talla. [petr.talla@gmail.com]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//		      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=============================================================================
#include "T2lFileInfo.h"

#include <fstream>
#include <algorithm>

using namespace T2l;
using namespace std;

//=============================================================================
std::string FileInfo::normalize(const char* filePath)
{
    string result(filePath);
    replace(result.begin(), result.end(), '\\', '/');
    return result;
}

//=============================================================================
std::string FileInfo::fileName(const char* filePath)
{
    string fp = normalize(filePath);

    const size_t last_slash_idx = fp.rfind("/");
    return fp.substr(last_slash_idx+1, fp.length());
}

//=============================================================================
std::string FileInfo::filePath(const char* filePath)
{
    string fp = normalize(filePath);

    const size_t last_slash_idx = fp.rfind("/");
    return fp.substr(0, last_slash_idx);
}

//=============================================================================
std::string FileInfo::baseName(const char* filePath)
{
    string fn = fileName(filePath);

    const size_t first_dot_idx = fn.find(".");
    return fn.substr(0, first_dot_idx);
}

//=============================================================================
bool FileInfo::exists(const char* filePath)
{
    ifstream infile(filePath);
    return infile.good();
}

//=============================================================================
