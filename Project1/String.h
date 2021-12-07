#include <exception>

/// <summary>
/// exception in accessing a string by index
/// </summary>
class StringIndexException : public std::exception {
	using std::exception::exception;
};

/// <summary>
/// a class representing a constant string
/// which can be manipulated
/// </summary>
class String {
public:
	/// <summary>
	/// creates a string from a c-style string (char*)
	/// </summary>
	/// <param name="c_str">the c style string</param>
	explicit String(const char* c_str);
	/// <summary>
	/// copy constructor
	/// </summary>
	/// <param name="other">the string to copy</param>
	String(const String& other);
	/// <summary>
	/// empty constructor, creates an empty string ("")
	/// </summary>
	String();
	/// <summary>
	/// returns this string as a c-style string (char*)
	/// </summary>
	/// <returns>the c-style string</returns>
	const char* c_str() const;
	/// <returns>the size of this string</returns>
	int size() const;
	/// <summary>
	/// concatenates this string with another string
	/// </summary>
	/// <param name="other">the other string</param>
	/// <returns>the two strings concatenated (with this being first)</returns>
	String operator+(String const& other) const;
	/// <summary>
	/// gets the char at a specific index
	/// </summary>
	/// <param name="index">the index to retreive the char from</param>
	/// <returns></returns>
	char operator[](int index) const;
	~String();
	/// <summary>
	/// assignment copy
	/// </summary>
	/// <param name="other">the assigned string</param>
	/// <returns></returns>
	String& operator=(const String& other);
	/// <summary>
	/// replaces all occurences of "substring" with "newstring"
	/// </summary>
	/// <param name="substring">the search string</param>
	/// <param name="newstring">the replace string</param>
	/// <returns>a copy of this string, with all occurances of substring replaced
	/// by newstring</returns>
	String replace(String substring, String newstring);
	/// <summary>
	/// inserts substring into this string at the index
	/// similar to splitting the string into two (at offset) and adding substring
	/// in the middle
	/// </summary>
	/// <param name="substring">the string to add</param>
	/// <param name="offset">where to add the string</param>
	/// <returns></returns>
	String insert(String substring, int offset);

private:
	String(const char* c_str, int size);
	const char* m_c_str;
	int m_size;
};