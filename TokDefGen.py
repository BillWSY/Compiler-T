#!/usr/bin/env python

import re

ftok = open("Lexicon.l", "r");
fdef = open("Token_def.h", "w");
ftokdes = open("Token_def.cpp", "w");

defBase = 1000;
cnt = 0

isFirst = 1
tokDes = ""
tokList = []
linelist = ftok.readlines()
for line in linelist:
    tokNames = re.findall("TOK_[A-Z0-9_]*;", line);
    for name in tokNames:
        tokenName = name.replace(";", "");
        if (tokList.count(tokenName)==0):
            tokList.append(tokenName)
            if (isFirst):
                isFirst = 0
            else:
                tokDes = tokDes + ",\n"
            fdef.write("#define " + tokenName + " " + str(defBase + cnt) + "\n")
            tokDes = tokDes + "    \"" + tokenName + "\""
            cnt = cnt + 1
fdef.write("\n#define CNT_TOKEN " + str(cnt) + "\n")
fdef.write("#define BASE_TOKEN " + str(defBase) + "\n")
fdef.write("\n#include <string>\n");
fdef.write("\nstd::string getTokenName(int tokenType);")
fdef.write("\n")

ftokdes.write("#include \"Token_def.h\"\n")
ftokdes.write("#include <cassert>\n")
ftokdes.write("const std::string tokenNameTable[] = {\n")
ftokdes.write(tokDes);
ftokdes.write("\n};\n\n");
ftokdes.write("std::string getTokenName(int tokenType)\n")
ftokdes.write("{\n")
ftokdes.write("    assert((tokenType >= BASE_TOKEN) && (tokenType < (BASE_TOKEN + CNT_TOKEN)));\n")
ftokdes.write("    return tokenNameTable[tokenType - BASE_TOKEN];\n")
ftokdes.write("}\n")
ftokdes.write("\n")

ftok.close()
fdef.close()
ftokdes.close()

