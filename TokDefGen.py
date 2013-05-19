#!/usr/bin/env python

import re

ftok = open("Lexicon.l", "r");
fdef = open("Token_def.h", "w");
ftokdes = open("Token_def.cpp", "w");

defBase = 1000;
cnt = 0

isFirst = 1
tokDes = ""
linelist = ftok.readlines()
for line in linelist:
    tokNames = re.findall("TOK_.*;", line);
    for name in tokNames:
        if (isFirst):
            isFirst = 0
        else:
            tokDes = tokDes + ",\n"
        tokenName = name.replace(";", "");
        fdef.write("#define " + tokenName + " " + str(defBase + cnt) + "\n")
        tokDes = tokDes + "    std::make_pair(" + tokenName + ", \"" + tokenName + "\")"
        cnt = cnt + 1
fdef.write("\n#define CNT_TOKEN " + str(cnt) + "\n")
fdef.write("\n#include <string>\n")
fdef.write("#include <map>\n\n")
fdef.write("typedef std::map<int, std::string> TokDesMap_t;\n")
fdef.write("extern const TokDesMap_t tokDesMap;")

ftokdes.write("#include \"Token_def.h\"\n")
ftokdes.write("\ntypedef std::map<int, std::string> TokDesMap_t;\n")
ftokdes.write("\nconst TokDesMap_t::value_type TokDesMap_const[] = {\n");
ftokdes.write(tokDes);
ftokdes.write("\n};\n\n");
ftokdes.write("const TokDesMap_t tokDesMap(TokDesMap_const, TokDesMap_const + CNT_TOKEN);")

ftok.close()
fdef.close()
ftokdes.close()

