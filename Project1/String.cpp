#include "String.h"

int c_str_len(const char* c_str)
{
	int s = 0;
	while (c_str[s] != 0) {
		s++;
	}
	return s;
}

const char* c_str_copy(const char* c_str) {
	int len = c_str_len(c_str);
	char* new_char = new char[len + 1];
	for (int i = 0; i < len; i++) {
		new_char[i] = c_str[i];
	}
	new_char[len] = 0; // null terminator
	return const_cast<const char*>(new_char);
}

String::String(const char* c_str)
{
	this->m_c_str = c_str_copy(c_str);
	this->m_size = c_str_len(this->m_c_str);
}

String::String() : String("")
{
}

const char* String::c_str() const
{
	return this->m_c_str;
}

int String::size() const
{
	return this->m_size;
}

String String::operator+(String const& other) const
{
	int len1 = this->size();
	int len2 = other.size();
	char* new_c_str = new char[len1 + len2 + 1];
	for (int i = 0; i < len1; i++) {
		new_c_str[i] = this->m_c_str[i];
	}
	for (int i = 0; i < len2; i++) {
		new_c_str[i + len1] = other.m_c_str[i];
	}
	new_c_str[len1 + len2] = 0; // null term
	return String(new_c_str);
	
}

char String::operator[](int index) const
{
	if (index < 0) {
		throw StringIndexException("negative index");
	}
	if (index >= this->m_size) {
		throw StringIndexException("index too big");
	}
	return this->m_c_str[index];
}

String::~String()
{
	delete[] this->m_c_str;
}

String String::unsafe(const char* c_str)
{
	String s;
	s.m_c_str = c_str;
	s.m_size = c_str_len(c_str);
	return s;
}
