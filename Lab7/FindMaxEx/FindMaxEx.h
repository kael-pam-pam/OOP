#pragma once
#include <vector>

template <typename T, typename Less>
bool FindMaxEx(const std::vector<T>& arr, T& maxValue, const Less& less)
{
	size_t n = arr.size();

	if (n == 0)
	{
		return false;
	}

	const T* max = &arr[0];
	for (size_t i = 0; i < n; i++)
	{
		if (less(*max, arr[i]))
		{
			max = &arr[i];
		}
	}
	maxValue = *max;
	return true;
}