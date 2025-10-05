#pragma once

#include <cstdlib>

namespace SmartPointers {
	template<class T>
	class SmartPtr {
		T* pointer;
		size_t *counter;
		public:
			SmartPtr() : pointer(nullptr), counter(nullptr) {}
			SmartPtr(const T& item) {
				pointer = new T;
				*pointer = item;
				counter = new size_t(1);
			}

			SmartPtr(T* p_item) {
				pointer = p_item;
				counter = new size_t(1);
			}

			SmartPtr(const SmartPtr<T>& ptr) {
				this->pointer = ptr.pointer;
				this->counter = ptr.counter;
				++*(this->counter);
			}

			SmartPtr(const SmartPtr<T>&& ptr) {
				this->pointer = ptr.pointer;
				this->counter = ptr.counter;
			}

			~SmartPtr() {
				--*(this->counter);
				if (*(this->counter) == 0) {
					delete (this->pointer);
					delete this->counter;
				}
			}

			int getCount() const {
				return *this->counter;
			}

			T& operator*() const {
				return *pointer;
			}

			T* operator->() const {
				return this->pointer;
			}

			SmartPtr& operator=(const SmartPtr& other) {
				pointer = other.pointer;
				counter = other.counter;
				return *this;
			}
			SmartPtr& operator=(SmartPtr&& other) {
				pointer = other.pointer;
				counter = other.counter;
				other.pointer = nullptr;
				other.counter = new size_t(1);
				return *this;
			}

			bool isEqual(const SmartPtr<T>& other) const {
				return other.pointer == this->pointer;
			}

			bool operator==(const SmartPtr<T>& other) const {
				return this->isEqual(other);
			}

			bool operator!=(const SmartPtr<T>& other) const {
				return !(this->isEqual(other));
			}
	};
}