#ifndef WORD_H

	#define WORD_H

	typedef struct word Word;

	Word * createWord(char *str);
	char * getWord(Word *wrd);
	void updateOccurrences(Word *wrd);
	int getOccurrences(Word *wrd);
	Word * searchWord(Word *wrd, char *str);
	Word * insertWord(Word *word_list, Word *wrd);
	int countWordList(Word *wrd);
	void printWord(Word *wrd);
	void freeWordList(Word *wrd);

#endif
