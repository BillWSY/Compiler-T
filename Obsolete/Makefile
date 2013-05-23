test : Tokeniser.cpp
	g++ Tokeniser.cpp Token_def.cpp Parser.cpp -ll -o test

.PHONY : Tokeniser
Tokeniser : Tokeniser.cpp

Tokeniser.cpp : Lexicon.l Token_def.h Parser.h
	flex -v -o Tokeniser.cpp --header-file=Tokeniser.h Lexicon.l 2>Lexicon.log

Token_def.h : Lexicon.l TokDefGen.py
	./TokDefGen.py

.PHONY : Parser
Parser : Parser.cpp Parser.h

Parser.cpp Parser.h : Grammar.y
	bison -v --defines=Parser.h -o Parser.cpp Grammar.y 
	mv Parser.output Parser.log

clean:
	rm *.log
	rm Token_def.h
	rm Token_def.cpp
	rm Tokeniser.cpp
	rm Parser.h
	rm Parser.cpp
	rm test
