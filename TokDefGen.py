#!/usr/bin/env python

ftok = open("toklist.txt", "r");
fdef = open("Token_def.h", "w");

cnt = 1000

linelist = ftok.readlines()
for line in linelist:
    if (line.replace("\n", "") != ""):
        fdef.write("#define " + line.replace("\n", "") + " " + str(cnt) + "\n")
        cnt = cnt + 1

ftok.close()
fdef.close()
