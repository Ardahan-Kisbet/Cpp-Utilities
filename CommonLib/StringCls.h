#pragma once
class StringCls
{
private:
	char* m_str = nullptr;
	size_t m_strLen = 0;


public:
	// constructors
	StringCls();						// default constructor
	StringCls(const char * s);			// c-string constructor
	StringCls(const StringCls& s);		// copy constructor
	StringCls(StringCls&& s) noexcept;	// move constructor
	~StringCls();						// desctructor

	// data management

	// operators

	// comparison operators

	// conversion operators

	// utility methods

	// find and replace methods

	// split methods


};

