#pragma once

#include "ShrdPtr.h"
#include <stdexcept>

namespace SmartPointers {
	template<class T>
	class MemorySpan {
		class MsPtr {
			MemorySpan<T>& origin;
			size_t index;
		public:
			MsPtr(MemorySpan<T>& origin, size_t index) : origin(origin), index(index) {}
			MsPtr(MsPtr& ptr) : origin(ptr.origin), index(index) {}
			MsPtr& operator=(MsPtr& other) {
				this->origin = other.origin;
				this->index = other.index;
				return *this;
			}
			T* operator->() const {
				return origin.pointerTo(index);
			}
			T& operator*() {
				return *(origin.pointerTo(index));
			}
			MsPtr& operator+(const size_t add) {
				if (index + add >= origin.count) {
					std::out_of_range("index out of MemorySpan range");
				}
				index = index + add;
				return *this;
			}
			MsPtr& operator-(const size_t sub) {
				if (sub > index) {
					std::out_of_range("negative index of MemorySpan range");
				}
				index = index - sub;
				return *this;
			}
		};
		T* span;
		size_t count;
	protected:
		T* pointerTo(size_t index) {
			if (index >= count) {
				std::out_of_range("index out of MemorySpan range");
			}
			return (span + index);
		}
	public:
		MemorySpan(size_t count) : span(new T[count]) {}
		MemorySpan(size_t count, T* list) : span(new T[count]) {
			for (size_t i = 0; i < count; ++i) {
				span[i] = list[i];
			}
		}
		~MemorySpan() {
			delete[] span;
		}

		UnqPtr<T> Copy(size_t index) {
			if (index >= count) {
				std::out_of_range("index out of MemorySpan range");
			}
			return UnqPtr<T>(new T(*(span + index)));
		}

		MsPtr Locate(size_t index) {
			if (index >= count) {
				std::out_of_range("index out of MemorySpan range");
			}
			return MsPtr(*this, index);
		}
	};
}