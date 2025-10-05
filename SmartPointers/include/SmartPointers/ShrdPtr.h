#pragma once

#include <utility>

namespace SmartPointers {
	template<class T>
	class UnqPtr {
		T* ptr;
	public:
		UnqPtr() : ptr(new T()) {}
		UnqPtr(const T& val) : ptr(new T (val)) {}
		UnqPtr(T* ptr) {
			this->ptr = ptr;
		}
		UnqPtr(const UnqPtr<T>& p) : ptr(new T (*(p.ptr))) {}
		~UnqPtr() {
			delete ptr;
		}
		UnqPtr<T>& operator=(const UnqPtr<T>& b) {
			if (this != &b) {
				delete ptr;
				ptr = new T(*(b.ptr));
			}
			return *this;
		}
		T* operator->() const {
			return ptr;
		}
		T& operator*() const {
			return *ptr;
		}
	};

	template<class T>
	class ShrdPtr {
		UnqPtr<T>& ptr;
	public:
		ShrdPtr() : ptr(*(new UnqPtr<T>())) {}
		ShrdPtr(UnqPtr<T>& b) : ptr(b) {}
		UnqPtr<T>& operator->() const {
			return ptr;
		}
	};
}