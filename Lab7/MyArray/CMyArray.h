#pragma once

#include <algorithm>

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	CMyArray(CMyArray&& arr)
		: m_begin(arr.m_begin)
		, m_end(arr.m_end)
		, m_endOfCapacity(arr.m_endOfCapacity)
	{
		arr.m_begin = nullptr;
		arr.m_end = nullptr;
		arr.m_endOfCapacity = nullptr;
	}

	void Resize(size_t newSize)
	{
		size_t currentSize = GetSize();

		if (newSize < currentSize)
		{
			DestroyItems(m_begin + newSize, m_end);
			m_end = m_end - (currentSize - newSize);
		}
		else if (newSize > currentSize && newSize <= GetCapacity())
		{
			T* oldEnd = m_end;
			try
			{
				for (size_t i = 0; i < newSize - currentSize; ++i)
				{
					Append(T());
				}
			}
			catch (...)
			{
				DeleteItems(oldEnd + 1, m_end);
				m_end = oldEnd;
				throw;
			}
		}
		else if (newSize > GetCapacity())
		{
			auto newBegin = RawAlloc(newSize);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}

			DeleteItems(m_begin, m_end);

			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newSize;

			try
			{
				for (size_t i = GetSize(); i < GetCapacity(); ++i)
				{
					Append(T());
				}
			}
			catch (...)
			{
				DeleteItems(newEnd, m_end);
				m_end = newEnd;
				throw;
			}

		}
	}

	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity) 
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				new (newEnd) T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else 
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	CMyArray& operator=(CMyArray const& rhs)
	{
		if (this != std::addressof(rhs))
		{
			CMyArray newArr(rhs);

			std::swap(m_begin, newArr.m_begin);
			std::swap(m_end, newArr.m_end);
			std::swap(m_endOfCapacity, newArr.m_endOfCapacity);
		}
		return *this;
	}

	CMyArray& operator=(CMyArray&& rhs) 
	{
		if (&rhs != this)
		{
			Clear();
			m_begin = rhs.m_begin;
			m_end = rhs.m_end;
			m_endOfCapacity = rhs.m_endOfCapacity;

			rhs.m_begin = nullptr;
			rhs.m_end = nullptr;
			rhs.m_endOfCapacity = nullptr;
		}
		return *this;
	}

	T& operator[](size_t position)
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range");
		}

		return m_begin[position];
	}

	const T& operator[](size_t position) const
	{
		if (position >= GetSize())
		{
			throw std::out_of_range("Element is out of range");
		}

		return m_begin[position];
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}

	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			new (dstEnd)T(*srcBegin);
		}
	}

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	static T* RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T* p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void DeleteItems(T* begin, T* end)
	{
		DestroyItems(begin, end);
		RawDealloc(begin);
	}

	static void DestroyItems(T* from, T* to)
	{
		while (to != from)
		{
			--to;
			to->~T();
		}
	}

	static void RawDealloc(T* p)
	{
		free(p);
	}

	void Clear()
	{
		DestroyItems(m_begin, m_end);
		m_end = m_begin;
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}
private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};