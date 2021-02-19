#include <iostream>

class String
{
	constexpr size_t MAXLEN = 16;
	
	char* buffer;
	char sso[MAXLEN];
	size_t len;
	
public:
    ...
    ...
    
}

// Each StringListNode must have a String (defined above) and a pointer to the next StringListNode.
// The last StringListNode must have a nullptr as next node.
struct StringListNode
{
	...
};

// The StringList has a pointer to the first node on the list and other one to the last node.
class StringList
{
	StringListNode* first;
	StringListNode* last;
	size_t len;
	
public:
	...
	...
};

void testString()
{
	String s1 { "Hola" };
	String s2 = "mundo";
	
	String s3 = s1 + " " + s2;
	
	s3.print();
	
	String s4 = "Hola mundo";
	
	if (s3 == s4)
		std::cout << "SON IGUALES\n";
		
	s4 += " de programadores de C++";
	String s5 = s4;
	
	if (s5 == "Hola mundo de programadores de C++")
		std::cout << "PERFECTO";
		
	std::cout << "Length: " << s5.length() << "\n";
	
	for (size_t i = 0; i < s5.length(); i++)
	{
		std::cout << s5.getCharAt(i);
	}
	
	std::cout << "\n" << s5.getCharArray() << "\n";
}

void testStringLinkedList()
{
	StringList ss;

	ss.push_back("a");
	ss.push_back("test");
	ss.push_back("of");
	ss.push_back("a");
	ss.push_back("string");
	ss.push_back("linked");
	ss.push_back("list");
	ss.push_front("is");	
	ss.push_front("This");	

	String r = ss.join(", ");
	std::cout << r << "\n"; // This is a test of a string linked list
	
	std::cout << ss.size() << "\n"; // 9
	
	String ss2;
	ss2.add("one");
	ss2.add("two");
	ss2.add("three");
	ss2.print();
	
	ss2 = ss;
	String r2 = ss2.join(", ");
	
	if (r2 == r)
	{
		std::cout << "LISTAS IGUALES\n";
	}
	
	if (ss == ss2)
	{
		std::cout << "LISTAS IGUALES\n";
	}
	
	ss2.push_back("in C++");
	
	if (ss != ss2)
		std::cout << "TODO BIEN\n";
		
	String r3 =ss2.join(" ");
	r3.print(); // This is a test of a string linked list in C++
}

int main()
{
	testString();
	testStringLinkedList();
	return 0;
}
