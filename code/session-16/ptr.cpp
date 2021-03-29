#include <iostream>
#include <cstdlib>

struct N
{
	int n;
	
	~N() { std::cout << "Destroying " << n << "\n"; }
	
	void print() const { std::cout << n << "\n"; }
};

template <typename T>
struct NewDeleter
{
	void operator()(T* obj)
	{
		delete obj;
	}
};

template <typename T, typename Deleter = NewDeleter<T>>
class ptr
{
	T* obj;
	Deleter deleter;
	
public:
	explicit ptr(T* obj = nullptr) : obj{obj} { }
	~ptr() { deleter(obj); }
	
	T* operator->()
	{
		return obj;
	}
	
	T& operator*()
	{
		return *obj;
	}
	
	bool operator==(nullptr_t) const
	{
		return obj == nullptr;
	}
	
	//ptr(const ptr<T, Deleter>& ) = delete;
	//ptr(ptr<T, Deleter>&& ) = delete;
	
	//ptr<T, Deleter>& operator=(const ptr<T, Deleter>& ) = delete;
	//ptr<T, Deleter>& operator=(ptr<T, Deleter>&& ) = delete;
	
};

struct Point
{
	int x;
	int y;
};

void print(const Point& p)
{
	std::cout << "(" << p.x << ", " << p.y << ")\n";
}

struct MallocDeleter
{
	void operator()(void* p)
	{
		free(p);
		std::cout << "freed\n";
	}
};

template <typename T, typename... Args>
ptr<T> make_ptr(Args&&... args)
{
	return ptr<T> { new T { std::forward<Args>(args)... } };
}

void f()
{
	//ptr<N> n { new N { 10 } };
	//ptr<N> o { new N { 20 } };
	//ptr<N> p { new N { 30 } };
	
	auto n = make_ptr<N>(10);
	auto o = make_ptr<N>(20);
	auto p = make_ptr<N>(30);
	
	
	n->print();
	o->print();
	p->print();
	
	(*n).print();
	
	ptr<N> q;
	if (q == nullptr)
		std::cout << "Null pointer\n";
		
	ptr<Point, MallocDeleter> p1 { static_cast<Point*>(malloc(sizeof(Point))) };
	ptr<Point, MallocDeleter> p2 { static_cast<Point*>(malloc(sizeof(Point))) };
	
	p1->x = 25;
	p1->y = 40;
	
	p2->x = 100;
	p2->y = 200;
	
	print(*p1);
	print(*p2);
	
}

int main()
{
	try
	{
		f();
	}
	catch(...) { }

}
