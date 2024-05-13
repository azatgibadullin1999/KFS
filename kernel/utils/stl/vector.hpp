/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:30:45 by larlena           #+#    #+#             */
/*   Updated: 2024/05/27 19:36:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_VECTOR_HPP__
# define __KFS_KERNEL_UTILS_STL_VECTOR_HPP__

# include "memory_resource.hpp"
# include "memory.hpp"
# include "utility.hpp"
# include "move.hpp"

namespace ktl::pmr {

template <typename T> class vector;
template <typename T> void	swap(vector<T> &lhs, vector<T> &rhs);


namespace deteils {

template <typename T>
class vector_impl {
public:
	using value_type = T;
	using allocator_type = ktl::pmr::polymorphic_allocator;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using reference = typename allocator_type::reference;
	using const_reference = typename allocator_type::const_reference;
	using pointer = typename allocator_type::pointer;
	using const_pointer = typename allocator_type::const_pointer;
	using iterator = pointer;
	using const_iterator = ;
	using reverse_iterator = ktl::reverse_iterator<iterator>;
	using const_reverse_iterator = ktl::reverse_iterator<const_iterator>;
protected:
	size_type	mSize;
	size_type	mCapacity;
	pointer		mArray;
	allocator_type	mAllocator;
public:
	constexpr vector_impl() noexcept(noexcept(allocator_type())) :
	mSize(0),
	mCapacity(0),
	mArray(nullptr),
	mAllocator(allocator_type()) { }
	
	constexpr explicit vector_impl(const allocator_type &alloc) noexcept :
	mSize(0),
	mCapacity(0),
	mArray(nullptr),
	mAllocator(alloc) { }

	constexpr explicit vector_impl(size_type count, allocator_type alloc = allocator_type()) :
	mSize(0),
	mAllocator(alloc) {
		mArray = alloc.allocate(count * sizeof(value_type));
		mCapacity = count;
	}

	constexpr vector_impl(vector_impl &&other) noexcept :
	mSize(ktl::move(other.mSize())),
	mCapacity(ktl::move(other.mCapacity())),
	mArray(ktl::move(other.mArray())),
	mAllocator(ktl::move(other.mAllocator())) { }

	constexpr ~vector_impl() {
		for (size_type i = 0; i != mSize; i++)
			ktl::destroy_at(&mArray[i]);
		mAllocator.deallocate(mArray, mCapacity * sizeof(value_type));
	}

	vector_impl	&operator = (vector_impl &&other) noexcept(noexcept(ktl::declval<T>()(ktl::move(ktl::declval<T>())))) {
		mSize = ktl::move(other.mSize);
		mCapacity = ktl::move(other.mCapacity);
		mArray = ktl::move(other.mArray);
		mAllocator = ktl::move(other.mAllocator);
		return *this;
	} 

};

}


template <typename T>
class vector : public deteils::vector_impl<T> {
public :
	using value_type = typename vector_impl<T>::value_type;
	using allocator_type = typename vector_impl<T>::allocator_type;
	using size_type = typename vector_impl<T>::size_type;
	using difference_type = typename vector_impl<T>::difference_type;
	using reference = typename vector_impl<T>::reference;
	using const_reference = typename vector_impl<T>::const_reference;
	using pointer = typename vector_impl<T>::pointer;
	using const_pointer = typename vector_impl<T>::const_pointer;
	using iterator = typename vector_impl<T>::iterator;
	using const_iterator = typename vector_impl<T>::const_iterator;
	using reverse_iterator = typename vector_impl<T>::reverse_iterator;
	using const_reverse_iterator = typename vector_impl<T>::const_reverse_iterator;

public :

	constexpr vector() noexcept(noexcept(vector_impl())) :
	vector_impl() { }

	constexpr explicit vector(const allocator_type &alloc) noexcept :
	vector_impl(alloc) { }

	constexpr explicit vector(size_type count, const_reference value = T(), allocator_type alloc = allocator_type()) :
	vector_impl(count, alloc) {
		for (;mSize != count; ++mSize) {
			ktl::construct_at(&mArray[mSize], value);
		}
	}

	explicit vector(size_type count, const allocator_type &alloc = allocator_type()) :
	vector_impl(count, alloc) { }



	// template <typename InputIt>
	// constexpr vector(
	// 	InputIt first,
	// 	InputIt last,
	// 	const allocator_type alloc = allocator_type()) :
	// mAllocator(alloc) {
	// 	typedef typename ktl::is_integral<InputIt>::type		integral;
	// 	__hidden_constructor(first, last, integral());
	// }

	constexpr vector(const vector &other) :
	vector_impl(other.mCapacity, other.mAllocator) {
		for (; mSize != other.mSize(); ++mSize)
			ktl::construct_at(&mArray[mSize], other[mSize]);
	}

	constexpr vector(vector &&other) noexcept :
	vector_impl(ktl::move(other)) { }

	constexpr ~vector() { }

	// constexpr vector	&operator = (const vector &other) {
	// 	for (size_type i = 0; i < mSize; i++)
	// 		mAllocator.destroy(&mArray[i]);
	// 	mSize = 0;
	// 	insert(begin(), other.begin(), other.end());
	// 	return *this;
	// }

	vector	&operator = (vector &&other) noexcept(noexcept(ktl::declval<T>()(ktl::move(ktl::declval<T>())))) {
		return vector_impl::operator = (ktl::move(other));
	}

	// constexpr void	assign(size_type count, const_reference value) {
	// 	__hidden_assign(count, value, true_type());
	// }

	// template <typename InputIt>
	// void	assign(InputIt first, InputIt last) {
	// 	typedef typename ktl::is_integral<InputIt>::type		integral;
	// 	__hidden_assign(first, last, integral());
	// }

			//	ELEMENT ACCESS

	// constexpr reference	at(size_type pos) {
	// 	if (pos >= mSize)
	// 		throw ktl::out_of_range("you go out of range");
	// 	return mArray[pos];
	// }

	// constexpr const_reference	at(size_type pos) const {
	// 	if (pos >= mSize)
	// 		throw ktl::out_of_range("you go out of range");
	// 	return mArray[pos];
	// }

	constexpr reference	operator [] (size_type pos) {
		return mArray[pos];
	}

	constexpr const_reference	operator [] (size_type pos) const {
		return mArray[pos];
	}

	constexpr reference	front() {
		return mArray[0];
	}

	constexpr const_reference	front() const {
		return mArray[0];
	}

	constexpr reference	back() {
		return mArray[mSize - 1];
	}

	constexpr const_reference	back() const {
		return mArray[mSize - 1];
	}

	constexpr pointer		data() {
		return (mArray);
	}

	constexpr const_pointer	data() const {
		return (mArray);
	}

			//	ITERATORS

	constexpr iterator	begin() {
		return iterator(mArray);
	}

	constexpr const_iterator	begin() const {
		return const_iterator(mArray);
	}

	constexpr const_iterator	cbegin() const noexcept {
		return const_iterator(mArray);
	}


	constexpr iterator	end() {
		return iterator(&mArray[mSize]);
	}

	constexpr const_iterator	end() const {
		return const_iterator(&mArray[mSize]);
	}

	constexpr const_iterator	cend() const noexcept {
		return const_iterator(&mArray[mSize]);
	}

	constexpr reverse_iterator	rbegin() {
		return reverse_iterator(end());
	}

	constexpr const_reverse_iterator	rbegin() const {
		return const_reverse_iterator(end());
	}

	constexpr const_reverse_iterator	crbegin() const {
		return const_reverse_iterator(end());
	}

	constexpr reverse_iterator	rend() {
		return reverse_iterator(begin());
	}

	constexpr const_reverse_iterator	rend() const {
		return const_reverse_iterator(begin());
	}

	constexpr const_reverse_iterator	crend() const noexcept {
		return const_reverse_iterator(begin());
	}
			//	CAPACITY

	constexpr bool		empty() const noexcept {
		return !static_cast<bool>(mSize);
	}

	constexpr size_type	size() const noexcept {
		return mSize;
	}

	// constexpr size_type	max_size() const noexcept {
	// 	return ktl::min((size_type) ktl::numeric_limits<difference_type>::max(),
	// 				ktl::numeric_limits<size_type>::max() / sizeof(value_type));
	// }


	// void		reserve(size_type new_cap) {
	// 	vector		new_vec(new_cap);

	// 	if (new_cap > mCapacity) {
	// 		new_vec = mAllocator.allocate(new_cap);
	// 		for (size_type i = 0; i < mSize; i++)
	// 			mAllocator.construct(&new_vec[i], mArray[i]);
	// 		for (size_type i = 0; i < mSize; i++)
	// 			mAllocator.destroy(&mArray[i]);
	// 		mAllocator.deallocate(mArray, mCapacity);
	// 		mArray = new_vec;
	// 		mCapacity = new_cap;
	// 	}
	// }

		size_type	capacity() const {
			return mCapacity;
		}

			//	MODIFIERS

		void		clear() {
			for (size_type i = 0; i < mSize; i++) {
				mAllocator.destroy(&mArray[i]);
			}
			mSize = 0;
		}

		iterator	insert(iterator pos, const_reference value) {
			difference_type	diff = ktl::distance(begin(), pos);

			insert(pos, 1, value);
			return begin() + diff;
		}

		// void		insert(iterator pos, size_type count, const_reference value) {
		// 	__hidden_insert(pos, count, value, true_type());
		// }

	template <typename InputIt>
	void		insert(iterator pos, InputIt first, InputIt last) {
		typedef typename is_integral<InputIt>::type		integral;
		__hidden_insert(pos, first, last, integral());
	}

		iterator	erase(iterator pos) {
			erase(pos, pos + 1);
			return pos;
		}

		iterator	erase(iterator first, iterator last) {
			difference_type	count = ktl::distance(first, last);
			difference_type diff = ktl::distance(begin(), first);


			__insert(&mArray[diff], &mArray[count + diff], &mArray[mSize - 1]);
			for (size_type i = mSize - count - 1; i < mSize; i++)
				mAllocator.destroy(&mArray[i]);
			mSize -= count;
			return first;
		}

		void		push_back(const_reference value) {
			insert(end(), value);
		}

		void		pop_back() {
			mAllocator.destroy(&mArray[--mSize]);
		}

		void		resize(size_type count, value_type value = T()) {
			if (count > mCapacity)
				reserve(mCapacity << 1 > count ? mCapacity << 1 : count);
			if (count > mSize) {
				for (size_type i = mSize; i < count; i++)
					mAllocator.construct(&mArray[i], value);
			} else {
				for (size_type i = count; i < mSize; i++)
					mAllocator.destroy(&mArray[i]);
			}
			mSize = count;
		}

		void		swap(vector &other) {
			ktl::swap(mCapacity, other.mCapacity);
			ktl::swap(mSize, other.mSize);
			ktl::swap(mArray, other.mArray);
		}

	private :

		void	__reverse_insert(pointer dst, pointer src_begin, pointer src_end) {
			while (src_begin >= src_end) {
				mAllocator.construct(dst, *src_begin);
				--src_begin;
				--dst;
			}
		}

		void	__insert(pointer dst, pointer src_begin, pointer src_end) {
			while (src_begin <= src_end) {
				mAllocator.construct(dst, *src_begin);
				++src_begin;
				++dst;
			}
		}

		// void	__hidden_constructor(size_type count, const_reference value, true_type) {
		// 	mSize = count;
		// 	mCapacity = count;
		// 	mArray = mAllocator.allocate(mCapacity);
		// 	for (size_type i = 0; i < mSize; i++)
		// 		mAllocator.construct(&mArray[i], value);
		// }

		// template <typename InputIt>
		// void	__hidden_constructor(InputIt first, InputIt last, false_type) {
		// 	difference_type	count = ktl::distance(first, last);
		// 	mSize = count;
		// 	mCapacity = count;
		// 	mArray = mAllocator.allocate(mCapacity);
		// 	for (size_type i = 0; i < static_cast<size_type>(count); i++)
		// 		mAllocator.construct(&mArray[i], *first++);
		// }

		void	__hidden_insert(iterator pos, size_type count, const_reference value, true_type) {
			difference_type	diff = ktl::distance(begin(), pos);

			if (count + mSize > mCapacity)
				reserve(mCapacity << 1 > mSize + count ? mCapacity << 1 : mSize + count);
			__reverse_insert(&mArray[count + mSize - 1], &mArray[mSize - 1], &mArray[diff]);
			for (size_type i = diff; i < diff + count; i++) {
				mAllocator.construct(&mArray[i], value);
			}
			mSize += count;
		}

		template <typename InputIt>
		void	__hidden_insert(iterator pos, InputIt first, InputIt last, false_type) {
			difference_type count = ktl::distance(first, last);
			difference_type	diff = ktl::distance(begin(), pos);

			if (count + mSize > mCapacity)
				reserve(mCapacity << 1 > mSize + count ? mCapacity << 1 : mSize + count);
			__reverse_insert(&mArray[count + mSize - 1], &mArray[mSize - 1], &mArray[diff]);
			for (size_type i = diff; i < static_cast<size_type>(count) + diff; i++) {
				mAllocator.construct(&mArray[i], *first++);
			}
			mSize += count;
		}

		void	__hidden_assign(size_type count, const_reference value, true_type) {
			for (size_type i = 0; i < mSize; i++)
				mAllocator.destroy(&mArray[i]);
			mSize = 0;
			reserve(count);
			for (size_type i = 0; i < count; i++)
				mAllocator.construct(&mArray[i], value);
			mSize = count;
		}

		template <typename InputIt>
		void	__hidden_assign(InputIt first, InputIt last, false_type) {
			difference_type	count = ktl::distance(first, last);

			for (size_type i = 0; i < mSize; i++)
				mAllocator.destroy(&mArray[i]);
			mSize = 0;
			reserve(count);
			for (size_type i = 0; i < static_cast<size_type>(count); i++)
				mAllocator.construct(&mArray[i], *first++);
			mSize = count;
		}

		friend void	ktl::swap<T>(vector<T> &lhs, vector<T> &rhs);


} ;

} // namespcae ktl::pmr

template <typename T>
bool	operator == (const ktl::pmr::vector<T> &lhs, const ktl::pmr::vector<T>&rhs) {
	return ktl::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size());
}

template <typename T>
bool	operator != (const ktl::pmr::vector<T> &lhs, const ktl::pmr::vector<T>&rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool	operator < (const ktl::pmr::vector<T> &lhs, const ktl::pmr::vector<T>&rhs) {
	return ktl::lexicographic_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool	operator > (const ktl::pmr::vector<T> &lhs, const ktl::pmr::vector<T>&rhs) {
	return (rhs < lhs);
}

template <typename T>
bool	operator >= (const ktl::pmr::vector<T> &lhs, const ktl::pmr::vector<T>&rhs) {
	return !(lhs < rhs);
}

template <typename T>
bool	operator <= (const ktl::pmr::vector<T> &lhs, const ktl::pmr::vector<T>&rhs) {
	return !(lhs > rhs);
}

template <typename T>
void	swap(ktl::pmr::vector<T> &lhs, ktl::pmr::vector<T> &rhs) {
	ktl::swap(lhs.mSize, rhs.mSize);
	ktl::swap(lhs.mCapacity, rhs.mCapacity);
	ktl::swap(lhs.mArray, rhs.mArray);
	ktl::swap(lhs.mAllocator, rhs.mAllocator);
}


#endif // __KFS_KERNEL_UTILS_STL_VECTOR_HPP__
