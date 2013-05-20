test : Tokeniser.c
	g++ Tokeniser.c Token_def.cpp -ll -o test

Tokeniser.c : Lexicon.l Token_def.h
	flex -v -o Tokeniser.c Lexicon.l 2>&1 | tee Lexicon.log

Token_def.h : Lexicon.l TokDefGen.py
	./TokDefGen.py

clean:
	rm *.log
	rm Token_def.h
	rm Tokeniser.c
	rm test
