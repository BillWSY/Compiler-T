graph : Parser.cpp Tokeniser.cpp graph.cpp utilities.cpp
	g++ DecClass.cpp ExpClass.cpp LValClass.cpp MiscClass.cpp Parser.cpp Tokeniser.cpp graph.cpp utilities.cpp -ll -o graph -g -Wall

.PHONY: run
run : graph merge.tig
	./graph < merge.tig > merge.dot
	dot -Tpng merge.dot -o merge.png

formatter : Parser.cpp Tokeniser.cpp formatter.cpp utilities.cpp
	g++ DecClass.cpp ExpClass.cpp LValClass.cpp MiscClass.cpp Parser.cpp Tokeniser.cpp formatter.cpp utilities.cpp -ll -o formatter -g -Wall

.PHONY : format
format : test merge_formater.tig merge.tig
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
	rm formatter
	rm graph
	rm Token_def.cpp
	rm Parser.h
	rm Parser.cpp
	rm Tokeniser.cpp
	rm test
