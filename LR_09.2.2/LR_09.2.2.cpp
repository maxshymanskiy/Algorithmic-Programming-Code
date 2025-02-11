#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>

#define SIZE 10
#define USE_NUM_ARRAY b
#define BEGIN {
#define END }

void countRepeats(int data[], int size);
void findSymbolPosition(char data[], int size, char symbol);

int main(void)
BEGIN
#if USE_NUM_ARRAY
int data[SIZE] = { 1, 2, 3, 2, 4, 1, 2, 3, 4, 5 };
puts("Counting repetitions in integer array:");
countRepeats(data, SIZE);
#else
char data[SIZE] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
char symbol;

puts("Enter a character to find its position:");
symbol = _getch();
printf("\nSearching for symbol '%c' in character array:\n", symbol);

findSymbolPosition(data, SIZE, symbol);
#endif

puts("\nPress any key to exit.");
_getch();
END

void countRepeats(int data[], int size)
BEGIN
int i, j, count;
int checked[SIZE] = { 0 };

for (i = 0; i < size; i++)
	BEGIN
	if (checked[i]) continue;
count = 1;

for (j = i + 1; j < size; j++)
	BEGIN
	if (data[i] == data[j])
		BEGIN
		count++;
checked[j] = 1;
END;
END;
printf("Number %d occurs %d times\n", data[i], count);
END;
END

void findSymbolPosition(char data[], int size, char symbol)
BEGIN
int i;
int found = 0;

for (i = 0; i < size; i++)
	BEGIN
	if (data[i] == symbol)
		BEGIN
		printf("Symbol '%c' found at position %d\n", symbol, i);
found = 1;
break;
END;
END;

if (!found)
printf("Symbol '%c' not found in array\n", symbol);
END