#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <sys/time.h>

void	mergeDeque(std::deque<int> &array, int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	std::deque<int> leftArray(subArrayOne);
	std::deque<int> rightArray(subArrayTwo);
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];
	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
		{
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
	{
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
	{
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void	mergeSortDeque(std::deque<int> &array, int begin, int end)
{
	if (begin >= end)
		return;
    int mid = begin + (end - begin) / 2;
    mergeSortDeque(array, begin, mid);
    mergeSortDeque(array, mid + 1, end);
    mergeDeque(array, begin, mid, end);
}

void	mergeVec(std::vector<int> &array, int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	std::vector<int> leftArray(subArrayOne);
	std::vector<int> rightArray(subArrayTwo);
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];
	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
		{
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
	{
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
	{
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void	mergeSortVec(std::vector<int> &array, int begin, int end)
{
	if (begin >= end)
		return;
    int mid = begin + (end - begin) / 2;
    mergeSortVec(array, begin, mid);
    mergeSortVec(array, mid + 1, end);
    mergeVec(array, begin, mid, end);
}

int	main(int ac, char **av)
{
	int i = 1;
	int tmp;
	std::vector<int> arrayVec; 
	std::deque<int> arrayDeque;
	if (ac < 2) 
	{
		std::cout << "Error: not enough arguments" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		std::istringstream checkInt(av[i]);
		checkInt >> tmp;
		if (checkInt.fail() || !checkInt.eof() || tmp < 0)
		{
			std::cout << "Error: not a valid list of integers" << std::endl;
			return (0);
		}
		arrayVec.push_back(tmp);
		arrayDeque.push_back(tmp);
		i++;
	}
	struct timeval  tv1, tv2;
	std::cout << "Before sorting with vector:";
	for (int i = 0; i < arrayVec.size();i++)
		std::cout << " " << arrayVec[i];
	std::cout << std::endl;
	gettimeofday(&tv1, NULL);
	mergeSortVec(arrayVec, 0, arrayVec.size() - 1);
	gettimeofday(&tv2, NULL);
	std::cout << "After Vector:";
	for (int i = 0; i < arrayVec.size();i++)
		std::cout << " " << arrayVec[i];
	printf("\nTime taken in execution = %f seconds\n",
     	(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
     	(double) (tv2.tv_sec - tv1.tv_sec));
	
	std::cout << "\nBefore sorting with deque:";
	for (int i = 0; i < arrayDeque.size();i++)
		std::cout << " " << arrayDeque[i];
	std::cout << std::endl;
	mergeSortDeque(arrayDeque, 0, arrayDeque.size() - 1);
	std::cout << "\nAfter Deque:";
	for (int i = 0; i < arrayDeque.size();i++)
		std::cout << " " << arrayDeque[i];
	return (0);
}