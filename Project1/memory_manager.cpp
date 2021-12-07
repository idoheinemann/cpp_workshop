#include <stdlib.h>
#include <iostream>

#include "memory_manager.h"

MemoryBlock* first_block = nullptr;
MemoryBlock* last_block = nullptr;

MemoryBlock* new_mem_block(size_t size)
{
	MemoryBlock* mem = static_cast<MemoryBlock*>(malloc(sizeof(MemoryBlock) + size));
	if (mem == nullptr) {
		throw std::bad_alloc();
	}
	mem->is_allocated = true;
	mem->next_block = nullptr;
	mem->prev_block = nullptr;
	mem->size = size;
	return mem;
}

void* allocate(size_t size)
{
	if (first_block == nullptr) {
		first_block = new_mem_block(size);
		last_block = first_block;
		return static_cast<void*>(first_block + 1);
	}
	MemoryBlock* block = new_mem_block(size);
	last_block->next_block = block;
	block->prev_block = last_block;
	last_block = block;
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
	if (block == last_block) {
		last_block = block->prev_block;
	}
	if (block == first_block) {
		first_block = block->next_block;
	}
	if (block->prev_block != nullptr) {
		block->prev_block->next_block = block->next_block;
	}
	if (block->next_block != nullptr) {
		block->next_block->prev_block = block->prev_block;
	}
	free(static_cast<void*>(block));
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
		std::cout << "Memory Block at " << block << ": <size - " << block->size << ">" << std::endl;
		block = block->next_block;
	}
}