test : Tokeniser.cpp
	g++ Tokeniser.cpp Token_def.cpp Parser.cpp -ll -o test

.PHONY : Tokeniser
Tokeniser : Tokeniser.cpp

Tokeniser.cpp : Lexicon.l Parser.h
	flex -v -o Tokeniser.cpp --header-file=Tokeniser.h Lexicon.l 2>Lexicon.log

.PHONY : Parser
Parser : Parser.cpp Parser.h

Parser.pdf : Parser.dot
	dot -Tpdf -o Parser.pdf Parser.dot

Parser.cpp Parser.h Parser.dot : Grammar.y
	bison -v -g -k --defines=Parser.h -o Parser.cpp Grammar.y 
	mv Parser.output Parser.log

clean:
	rm *.log
	rm token_def.h
	rm Token_def.cpp
	rm Parser.h
	rm Parser.cpp
	rm Tokeniser.cpp
	rm test
