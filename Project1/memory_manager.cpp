#include <stdlib.h>
#include <iostream>

#include "memory_manager.h"

MemoryBlock* first_block = nullptr;

MemoryBlock* new_mem_block(size_t size)
{
	MemoryBlock* mem = static_cast<MemoryBlock*>(malloc(sizeof(MemoryBlock) + size));
	if (mem == nullptr) {
		throw std::bad_alloc();
	}
	mem[0].is_allocated = true;
	mem[0].next_block = nullptr;
	mem[0].size = size;
	return mem;
}

void* allocate(size_t size)
{
	if (first_block == nullptr) {
		first_block = new_mem_block(size);
		return static_cast<void*>(first_block + 1);
	}
	MemoryBlock* prev_block = nullptr;
	MemoryBlock* block = first_block;
	while (block != nullptr) {
		if ((!block->is_allocated) && block->size >= size) {
			block->is_allocated = true;
			return static_cast<void*>(block + 1);
		}
		prev_block = block;
		block = block->next_block;
	}
	block = new_mem_block(size);
	prev_block->next_block = block;
	return static_cast<void*>(block + 1);
}

_NODISCARD _Ret_notnull_ _Post_writable_byte_size_(size) _VCRT_ALLOCATOR
void* __cdecl operator new(std::size_t size)
{
	return allocate(size);
}

_NODISCARD _Ret_notnull_ _Post_writable_byte_size_(size) _VCRT_ALLOCATOR
void* __cdecl operator new[](std::size_t size)
{
	return allocate(size);
}

void deallocate(void* addr) {
	MemoryBlock* block = static_cast<MemoryBlock*>(addr) - 1;
	block->is_allocated = false;
}

void operator delete(void* addr)
{
	deallocate(addr);
}

void operator delete[](void* addr)
{
	deallocate(addr);
}


void print_allocations() {
	MemoryBlock* block = first_block;
	while (block != nullptr) {
		std::cout << "Memory Block at " << block << ": <size - " << block->size << ", allocated - "
			<< (block->is_allocated ? "true" : "false") << ">" << std::endl;
		block = block->next_block;
	}
}