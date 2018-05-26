#ifndef STRCTBRHDEV_H_INCLUDED
#define STRCTBRHDEV_H_INCLUDED

#define ENTERED_WORDS 99 

typedef struct strctbrhDev {
	char inpBrh[13];
	char opDvn[10];
	int isLast;
	int isMinussable;
	int performMinusOne;
	int existAnother;
	int independantInvalid;

} strctbrhDev;

extern strctbrhDev strctbrhDev_array[ENTERED_WORDS];

#endif