#pragma once
#include <exception>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct MemoryBlock {
	bool is_allocated;
	size_t size;
	MemoryBlock* next_block;
};

_NODISCARD _Ret_notnull_ _Post_writable_byte_size_(size) _VCRT_ALLOCATOR
void* __cdecl operator new(std::size_t size);

_NODISCARD _Ret_notnull_ _Post_writable_byte_size_(size) _VCRT_ALLOCATOR
void* __cdecl operator new[](std::size_t size);

void operator delete(void* addr);

void operator delete[](void* addr);

void print_allocations();