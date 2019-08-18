#include <iostream>
#include <vector>
constexpr int c_size = 8;

void Merge(std::vector<int>& v, int begin, int end, int mid)
{
	int i, j, k;
	std::vector<int> temp(v.size());
	i = begin;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (v[i] < v[j])
		{
			temp[k] = v[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = v[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = v[i];
		k++;
		i++;
	}

	while (j <= end)
	{
		temp[k] = v[j];
		k++;
		j++;
	}


	for (i = begin; i <= end; i++)
	{
		v[i] = temp[i - begin];
	}
}


void MergeSort(std::vector<int>& v, int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		MergeSort(v, l, m);
		MergeSort(v, m + 1, r);

		Merge(v, l, r, m);
	}
}



int main(int argc, char* argv[])
{
	std::cout << "Merge sort with numbers" << std::endl;
	std::cout << "Enter numbers' count ";
	int size = 0;
	std::cin >> size;
	std::vector<int> numbers(size);
	
	std::cout << "Enter numbers you want to sort " << std::endl;
	int number = 0;
	int i = 0;
	for(int i = 0; i < size; ++i)
	{
		std::cin >> numbers[i];
	}

	MergeSort(numbers, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}

	return 0;
}
