#include <exception>

class StringIndexException : public std::exception {
	using std::exception::exception;
};

class String {
public:

	explicit String(const char* c_str);
	String();
	const char* c_str() const;
	int size() const;
	String operator+(String const& other) const;
	char operator[](int index) const;
	~String();
	static String unsafe(const char* c_str);

private:
	const char* m_c_str;
	int m_size;
};