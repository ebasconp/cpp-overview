#include <iostream>

template <typename T>
struct my_less
{
	bool is_less_than(const T& a, const T& b) const
	{
		return a < b;
	}
};

//Less is a policy
template <typename T, typename Less = my_less<T>>
class bst
{
	struct bst_node
	{
		T elem;
		bst_node* left;
		bst_node* right;
	};
	
	Less less;
	bst_node* root = nullptr;
	
public:
	~bst()
	{
	}
	
	void add(const T& elem)
	{
		add(root, elem);
	}
	
	void print() const
	{
		print(root);
	}
	
private:
	void print(const bst_node* node) const
	{
		if (node == nullptr) return;
		
		print(node->left);
		std::cout << node->elem << "\n";
		print(node->right);
	}

	void add(bst_node*& node, const T& elem)
	{
		if (node == nullptr)
		{
			node = new bst_node { elem, nullptr, nullptr };
			return;
		}
		
		if (less.is_less_than(elem, node->elem))
		{
			add(node->left, elem);
		}
		else
		{
			add(node->right, elem);
		}
	}
};

struct Complex
{
	double real;
	double im;
};

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "(" << c.real << "; " << c.im << ")";
	return os;
}

struct ComplexLess
{
	bool is_less_than(const Complex& a, const Complex& b)
	{
		if (a.real < b.real)
			return true;
			
		return a.im < b.im;
	}
};


int main()
{
	bst<int> b;
	b.add(25); b.add(50); b.add(48); b.add(72);
	b.add(12); b.add(0);
	
	b.print();

	bst<Complex, ComplexLess> c;
	c.add({ 10, 1 });
	c.add({ 12, 4 });
	c.add({ 5, -2 });
	c.print();
}


