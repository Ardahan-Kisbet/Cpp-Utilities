#pragma once

#include <iterator>

namespace Util
{
	template<class T, size_t N>
	class myArray
	{
		// array kullan
		// iterator yaz
		// raw pointer ile yada smart pointer fark etmez

		struct iterator : std::forward_iterator_tag
		{
			T* mPtr;

			iterator(T* ptr)
				: mPtr(ptr)
			{
			}

			// pre-increment
			iterator& operator++()
			{
				++mPtr;
				return *this;
			}

			// post-increment
			iterator operator++(int dummy)
			{
				auto temp = *this;
				++(*this);
				return temp;
			}

			bool operator==(const iterator& o)
			{
				return mPtr == o.mPtr;
			}

			bool operator!=(const iterator& o)
			{
				return !(mPtr == o.mPtr);
			}

			T& operator*()
			{
				return *mPtr;
			}

			T* operator->()
			{
				return mPtr;
			}
		};

	public:
		template <class... Tp>
		myArray(Tp... params)
			: mData{ params... }
		{
		}

		iterator begin()
		{
			return iterator(&mData[0]);
		}

		iterator end()
		{
			// end is actually pointing to next address after last valid index
			return iterator(mData + N);
		}

	private:
		T mData[N];

	};

}