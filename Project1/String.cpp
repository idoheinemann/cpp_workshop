#include <string.h>
#include "String.h"

int count_matches(const char* c_str, const char* search) {
	int count = 0;
	int search_len = strlen(search);
	int c_len = strlen(c_str);
	for (int i = 0; i < c_len - search_len;) {
		if (strncmp(c_str + i, search, search_len) == 0) {
			count++;
			i += search_len; // skip over all this match
		}
		else {
			i++;
		}
	}
	return count;
}

const char* c_str_copy(const char* c_str) {
	int len = strlen(c_str);
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
	this->m_size = strlen(this->m_c_str);
}

String::String(const String& other) : String(other.m_c_str)
{
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
	return String(new_c_str, len1 + len2);
	
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

String& String::operator=(String const& other)
{
	if (this != &other) {
		this->m_c_str = c_str_copy(other.m_c_str);
		this->m_size = other.m_size;
	}
	return *this;
}

String String::replace(String substring, String newstring)
{
	int size = (newstring.m_size - substring.m_size) * count_matches(this->m_c_str, substring.m_c_str);
	size += this->m_size;
	char* new_str = new char[size + 1];
	for (int i = 0, o = 0; i < size;) {
		if (strncmp(this->m_c_str + o, substring.m_c_str, substring.m_size) == 0) {
			for (int j = 0; j < newstring.m_size; j++) {
				new_str[i + j] = newstring.m_c_str[j];
			}
			i += newstring.m_size;
			o += substring.m_size;
		}
		else {
			new_str[i++] = this->m_c_str[o++];
		}
	}
	new_str[size] = 0;
	return String(new_str, size);
}

String String::insert(String substring, int offset)
{
	if (offset > this->m_size) {
		throw StringIndexException("offset larger then string size");
	}
	if (offset < 0) {
		throw StringIndexException("offset negative");
	}
	int size = substring.m_size;
	size += this->m_size;
	char* new_str = new char[size + 1];
	int i = 0, o = 0, c = 0;
	for (;i < offset;) {
		new_str[i++] = this->m_c_str[o++];
	}
	for (; c < substring.m_size && i < size;) {
		// to me it is obvious that i < size if always true
		// to the compiler, not so much
		new_str[i++] = substring.m_c_str[c++];
	}
	for (; i < size;) {
		new_str[i++] = this->m_c_str[o++];
	}
	new_str[size] = 0;
	return String(new_str, size);
}


String::String(const char* c_str, int size)
{
	this->m_c_str = c_str;
	this->m_size = size;
}

