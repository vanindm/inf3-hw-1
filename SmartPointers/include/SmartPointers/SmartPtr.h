#pragma once

#include <cstdlib>

namespace SmartPointers {
	template<class T>
	class SmartPtr {
		T* pointer;
		int *counter;
		public:
			SmartPtr(T& item) {
				pointer = malloc(sizeof(T));
				*pointer = item;
				counter = new int(1);
			}

			SmartPtr(T&& item) {
			}

			SmartPtr(SmartPtr<T>& const ptr) {
				this->pointer = ptr.pointer;
				this->counter = ptr.counter;
				*(this->counter)++;
			}

			~SmartPtr() {
				*(this->counter)--;
				if (*(this->counter) == 0) {
					delete this->pointer;
					delete this->counter;
				}
			}
			T* operator->() {
				return this->pointer;
			}

			bool operator==(SmartPtr<T>& other) {
				return other.pointer == this->pointer;
			}

			bool operator!=(SmartPtr<T>& other) {
				return other.pointer != this->pointer;
			}
	};
}