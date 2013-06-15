test : Parser.cpp Tokeniser.cpp main.cpp utilities.cpp
	g++ Parser.cpp Tokeniser.cpp main.cpp utilities.cpp -ll -o test -g

.PHONY : run
run : test merge_formater.tig merge.tig
	cat merge.tig | ./test > merge_formater.tig

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
