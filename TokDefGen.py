#!/usr/bin/env python

import re

flex = open("Lexicon.l", "r");
ftokLst = open("TokenList.txt", "w");
fdef = open("Token_def.h", "w");
ftokdes = open("Token_def.cpp", "w");

defBase = 258;
cnt = 0

isFirst = 1
tokDes = ""
tokList = []
fdef.write("#ifndef TOKEN_DEF_H\n#define TOKEN_DEF_H\n")
fdef.write("#include \"Parser.h\"\n")
linelist = flex.readlines()
for line in linelist:
    tokNames = re.findall("TOK_[A-Z0-9_]*", line);
    for tokenName in tokNames:
        if (tokList.count(tokenName)==0):
            tokList.append(tokenName)
            if (isFirst):
                isFirst = 0
                ftokLst.write("%token ");
            else:
                tokDes = tokDes + ",\n"
                if (cnt % 5 == 0):
                    ftokLst.write("\n%token ");
                else:
                    ftokLst.write(" ");
            ftokLst.write(tokenName);
            # fdef.write("#define " + tokenName + " " + str(defBase + cnt) + "\n")
            tokDes = tokDes + "    \"" + tokenName + "\""
            cnt = cnt + 1
ftokLst.write("\n");
fdef.write("\n#define CNT_TOKEN " + str(cnt) + "\n")
fdef.write("#define BASE_TOKEN " + str(defBase) + "\n")
fdef.write("\n#include <string>\n");
fdef.write("#include <vector>\n");
fdef.write("\nextern std::vector<std::string> strList;\n")
fdef.write("extern int strListCnt;\n")
fdef.write("\nstd::string getTokenName(int tokenType);\n")
fdef.write("#endif")
fdef.write("\n")

ftokdes.write("#include \"Token_def.h\"\n")
ftokdes.write("#include <cassert>\n")
ftokdes.write("\nstd::vector<std::string> strList;\n")
ftokdes.write("\nint strListCnt;\n")
ftokdes.write("const std::string tokenNameTable[] = {\n")
ftokdes.write(tokDes);
ftokdes.write("\n};\n\n");
ftokdes.write("std::string getTokenName(int tokenType)\n")
ftokdes.write("{\n")
ftokdes.write("    assert((tokenType >= BASE_TOKEN) && (tokenType < (BASE_TOKEN + CNT_TOKEN)));\n")
ftokdes.write("    return tokenNameTable[tokenType - BASE_TOKEN];\n")
ftokdes.write("}\n")
ftokdes.write("\n")

flex.close()
fdef.close()
ftokdes.close()

