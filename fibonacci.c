/**
 * Program to count the n-th Fibonacci number and print it.
 */

#include <stdio.h>
#include <stdlib.h>

#define DIGITS 100000

// Define a data strubture to store the F numbers
typedef struct
{
	int digits[DIGITS];
	int length;
} digiti;

digiti fibonacci(int n, digiti* nums[]);
digiti new_digiti();
digiti add_digiti(digiti* n, digiti* m);
void print_digiti(digiti n);


int main(int argc, char* argv[])
{
	// Receive only one command line argument
	if (argc == 2)
	{
		int n = atoi(argv[1]);
		if (n < 1)
		{
			printf("Please input a positive integer\n");
		}
		else
		{
			// Initialize memory array			
			digiti* numbers[n+1];
			for (int i = 0; i < n+1; i++)
			{
				numbers[i] = malloc(sizeof(digiti));
			}			
			*numbers[0] = new_digiti();
			// Count the F numbers and print
			for (int i = 1; i < n+1; i++)
			{			
				*numbers[i] = new_digiti();
				printf("F%i = ", i);
				print_digiti(fibonacci(i, numbers));
			}
			// Free memory array
			for (int i = 0; i < n+1; i++)
			{
				free(numbers[i]);
			}
		}
	}
	else
	{
		printf("Usage: fibonacci n\n");
	}

	return 0;
}


/**
 * Helper function to initialize new digiti data struct.
 * Returns data struct digiti.
 */
digiti new_digiti()
{
	digiti new_digiti;
	// Set length to zero
	new_digiti.length = 0;
	// Set all digits to zero
	for (int i = 0; i < DIGITS+1; i++)
	{
		new_digiti.digits[i] = 0;
	}
	// Return new digiti
	return new_digiti;	
}

/**
 * Helper function to add two digits.
 * Returns data struct digiti.
 */

digiti add_digiti(digiti* n, digiti* m)
{
	int len;
	int s;
	digiti sum;
	sum = new_digiti();
	// Set the length
	if (n->length > m->length)
	{
		len = n->length;
	}
	else
	{
		len = m->length;
	}
	// Summate
	for (int i = 0; i < len; i++)
	{
		s = n->digits[i] + m->digits[i];
		if (sum.digits[i] == 0)
		{
			sum.length++;
		} 	
		sum.digits[i] += s;
		if (sum.digits[i] > 9)
		{
			sum.digits[i] = sum.digits[i] % 10;
			sum.digits[i+1] = 1;
			sum.length++;
		}
	}

	return sum;
}

/**
 * Helper function to print digiti.
 * Returns nothing.
 */

void print_digiti(digiti n)
{
	for (int i = n.length; i > 0; i--)
	{
		printf("%i", n.digits[i-1]);
	}
	printf("\n");
}	

/**
 * Function that counts n-th Fibonacci number recursively
 * storing values into global array.
 * Returns data struct digiti.
 */

digiti fibonacci(int n, digiti* nums[])
{
	// Set the first memory array values
	nums[1]->length = 1;
	nums[1]->digits[0] = 1;
	nums[2]->length = 1;
	nums[2]->digits[0] = 1;
	// Count Fibonacci numbers
	if (n == 1)
	{
		return *nums[1];
	}
	else if (n == 2)
	{
		return *nums[2];
	}
	else
	{
		if (nums[n-2]->length == 0)
		{
			*nums[n-2] = fibonacci(n-2, nums);
		}
		if (nums[n-1]->length == 0)
		{
			*nums[n-1] = fibonacci(n-1, nums);
		}
		*nums[n] = add_digiti(nums[n-1], nums[n-2]);
		return *nums[n];
	}
}

