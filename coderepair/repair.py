#!/usr/bin/env python

fprefix = "MiscClass"
fp = open("../" + fprefix + ".h")
fh = open(fprefix + ".h", "w");
fcpp = open(fprefix + ".cpp", "w");

OUT = 0
INCLASS = 1
INFUNC = 2

curlNesting = 0

curState = OUT

def countSpaceHead(s):
    return s.find(s.lstrip())

fList = fp.readlines()
recList = [];
className = ""
spaceDel = 0
clsNesting = 0

for fLine in fList:
    curlNesting += fLine.count("{") - fLine.count("}")
    if (curState == OUT):
        if (fLine.find("class") >= 0):
            fh.write(fLine)
            curState = INCLASS;
            fLine.replace(":", " ")
            fLine.replace("{", " ")
            fLine = fLine.strip()
            t = fLine.split(' ')
            className = t[1]
        else:
            fh.write(fLine)
            fcpp.write(fLine)
    elif (curState == INCLASS):
        if (fLine.find("(") >= 0):
            curState = INFUNC;
            lhfile = fLine;
            if ((lhfile.find(':') >= 0) and (lhfile.find('::') <= 0)):
                lhfile = lhfile[0:lhfile.find(':')]
            else:
                lhfile = lhfile[0:lhfile.find('{')]
            lhfile.rstrip()
            fh.write(lhfile + ";\n")
            lcfile = fLine
            spaceDel = countSpaceHead(lcfile)
            lcfile = lcfile.lstrip()
            lcfile = className + "::" + lcfile
            fcpp.write(lcfile)
            clsNesting = curlNesting
        else:
            lhfile = fLine;
            fh.write(lhfile + "\n")
        if (curlNesting == 0):
            curState = OUT
    else:
        lcfile = fLine
        if (lcfile[0:spaceDel] == (' ' * spaceDel)):
            lcfile = lcfile[spaceDel:]
        fcpp.write(lcfile)
        if (curlNesting == clsNesting - 1):
            curState = INCLASS

fh.close()
fcpp.close()









