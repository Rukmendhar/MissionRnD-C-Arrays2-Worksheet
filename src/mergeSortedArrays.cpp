/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	struct transaction *result = NULL;

	result = (struct transaction*)malloc((sizeof(struct transaction))*(ALen+BLen));
	int ayear[10], amonth[10], adate[10], byear[10], bmonth[10], bdate[10];
	int index, index2, res,i=0,j=0,k=0;

	for (index = 0; index < ALen; index++)
	{
		ayear[index] = (((A[index].date[6] - '0') * 1000) + ((A[index].date[7] - '0') * 100) + ((A[index].date[8] - '0') * 10) + (A[index].date[9] - '0'));
		amonth[index] = (((A[index].date[3] - '0') * 10) + (A[index].date[4] - '0'));
		adate[index] = (((A[index].date[0] - '0') * 10) + (A[index].date[1] - '0'));
	}

	for (index = 0; index < BLen; index++)
	{
		byear[index] = (((B[index].date[6] - '0') * 1000) + ((B[index].date[7] - '0') * 100) + ((B[index].date[8] - '0') * 10) + (B[index].date[9] - '0'));
		bmonth[index] = (((B[index].date[3] - '0') * 10) + (B[index].date[4] - '0'));
		bdate[index] = (((B[index].date[0] - '0') * 10) + (B[index].date[1] - '0'));
	}

	while (i < ALen && j < BLen)
	{
		if ((ayear>byear) || ((ayear == byear) && amonth > bmonth) || ((ayear == byear) && (amonth == bmonth) && (adate > bdate)))
		{
			result[k++] = B[j];
			j++;
		}
		else
		{
			result[k++] = A[i];
			i++;
		}
	}
	while (i < ALen)
	{
		result[k++] = A[i];
		i++;

	}
	while (j < BLen)
	{
		result[k++] = B[j];
		j++;
	}



	return result;
}