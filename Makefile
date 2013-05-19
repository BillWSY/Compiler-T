test : Tokeniser.c
	g++ Tokeniser.c -ll -o test

Tokeniser.c : Lexicon.l Token_def.h
	flex -v -o Tokeniser.c Lexicon.l 2> Lexicon.log

Token_def.h : toklist.txt TokDefGen.py
	./TokDefGen.py

clean:
	rm *.log
	rm Token_def.h
	rm Tokeniser.c
	rm test
