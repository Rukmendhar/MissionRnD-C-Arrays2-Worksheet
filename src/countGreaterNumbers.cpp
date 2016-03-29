/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	
	int year[5];
	int month[5];
	int adate[5];
	int ryear;
	int rmonth;
	int rdate;
	int index,count=0,res=0;

	ryear = ((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + (date[9] - '0');
	rmonth = ((date[3] - '0') * 10) + (date[4] - '0');
	rdate = ((date[0] - '0') * 10) + (date[1] - '0');

	for (index = 0; index < len; index++)
	{
		year[index] = (((Arr[index].date[6] - '0') * 1000) + ((Arr[index].date[7] - '0') * 100) + ((Arr[index].date[8] - '0') * 10) + (Arr[index].date[9] - '0'));
		month[index] = (((Arr[index].date[3] - '0') * 10) + (Arr[index].date[4] - '0'));
		adate[index] = (((Arr[index].date[0] - '0') * 10) + (Arr[index].date[1] - '0'));
	}

	for (index = 0; index < len; index++)
	{
		if ((year[index] == ryear) && (month[index] == rmonth) && (adate[index] == rdate))
		{
			res = len - (index + 1);
		}
	}
			
	

	
	return res;
}
