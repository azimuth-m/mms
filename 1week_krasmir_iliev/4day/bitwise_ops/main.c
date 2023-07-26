#include <stdio.h>
#include <stdint.h>

void
SetBit(uint16_t *word, uint8_t bit)
{
	*word |= (1 << bit); /* Set bit-th bit of word. Use address of word as parameter */
}

uint8_t
CheckBit(uint16_t word, uint8_t bit)
{
	return (word & (1 << bit)) ? 1:0;
}

void
ClearBit(uint16_t *word, uint8_t bit)
{
	*word &= ~(1 << bit);
}

void
PrintWord(uint16_t word)
{
	for (int i = 15; i >= 0; i--)
		printf("%d", CheckBit(word, i));
	printf("\n");
}

int
main(void)
{
	uint16_t testWord = 0xFF01; 
	printf("\ntestWord = %b\n\n", testWord);

	printf("Clear 0 bit\n");
	ClearBit(&testWord, 0);
	PrintWord(testWord);

	printf("Set 0 bit\n");
	SetBit(&testWord, 0);
	PrintWord(testWord);

	/*
	 * nenujna proverka na CheckBit(), tui kato tq se polzva v PrintWord() (koqto raboti)
	 */
	return 0;
}
