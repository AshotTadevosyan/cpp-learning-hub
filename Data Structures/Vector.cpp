#include <iostream>

class Vector
{
    private: 
        int m_size;
        int m_capacity;
        int* m_elements;

    public:
        Vector();
        Vector(int size);
        Vector(int size, int value);
        Vector(Vector&& v);
        Vector(const Vector& v);
        Vector& operator=(const Vector& v);
        ~Vector();
        
        int size();
        int capacity();
        bool empty();
        int& at(int pos);
        int& operator[](int pos);
        void push_back(int value);
        void pop_back();
        void insert(int pos, int value);
        void erase(int pos);
        int& front();
        int& back();
        void clear();
        void swap(Vector& v);
        void print();
};

Vector::Vector() : m_size(0), m_capacity(0), m_elements(nullptr)
{
    std::cout << "Vector default constructor called." << std::endl;
}

Vector::Vector(int size) : m_size(size), m_capacity(size), m_elements(new int[size])
{
    std::cout << "Vector constructor called." << std::endl;
}

Vector::Vector(int size, int value) : m_size(size), m_capacity(size), m_elements(new int[size])
{
    for (int i = 0; i < size; i++)
    {
        m_elements[i] = value;
    }
}

Vector::Vector(Vector&& v) 
: m_size(v.m_size), m_capacity(v.m_capacity), m_elements(v.m_elements)
{
    v.m_size = 0;
    v.m_capacity = 0;
    v.m_elements = nullptr;
}

Vector::Vector(const Vector& v) : m_size(v.m_size), m_capacity(v.m_capacity), m_elements(new int[v.m_size])
{
    for (int i = 0; i < v.m_size; i++)
    {
        m_elements[i] = v.m_elements[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    if (this != &v)
    {
        delete[] m_elements;
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        m_elements = new int[v.m_size];
        for (int i = 0; i < v.m_size; i++)
        {
            m_elements[i] = v.m_elements[i];
        }
    }
    return *this;
}

Vector::~Vector()
{
    std::cout << "Vector destructor called." << std::endl;
    delete[] m_elements;
}

int Vector::size()
{
    return m_size;
}

int Vector::capacity()
{
    return m_capacity;
}

bool Vector::empty()
{
    return m_size == 0;
}

int& Vector::at(int pos)
{
    if (pos < 0 || pos >= m_size)
    {
        throw std::out_of_range("Index out of range.");
    }
    return m_elements[pos];
}

int& Vector::operator[](int pos) 
{
    return m_elements[pos];
}

void Vector::push_back(int value)
{
    if (m_size == m_capacity)
    {
        int* temp = new int[m_size];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_elements[i];
        }
        delete[] m_elements;
        m_capacity = m_capacity * 2;
        m_elements = new int[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_elements[i] = temp[i];
        }
        delete[] temp;
    }
    m_elements[m_size++] = value;
}

void Vector::pop_back()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Vector is empty.");
    }
    m_size--;
}

void Vector::insert(int pos, int value)
{
    if (pos < 0 || pos > m_size)
    {
        throw std::out_of_range("Index out of range.");
    }
    if (m_size == m_capacity)
    {
        int* temp = new int[m_size];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_elements[i];
        }
        delete[] m_elements;
        m_capacity = m_capacity * 2;
        m_elements = new int[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            m_elements[i] = temp[i];
        }
        delete[] temp;
    }
    for (int i = m_size; i > pos; i--)
    {
        m_elements[i] = m_elements[i - 1];
    }
    m_elements[pos] = value;
    m_size++;
}

void Vector::erase(int pos)
{
    if (pos < 0 || pos >= m_size)
    {
        throw std::out_of_range("Index out of range.");
    }
    for (int i = pos; i < m_size - 1; i++)
    {
        m_elements[i] = m_elements[i + 1];
    }
    m_size--;
}

int& Vector::front()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Vector is empty.");
    }
    return m_elements[0];
}

int& Vector::back()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Vector is empty.");
    }
    return m_elements[m_size - 1];
}

void Vector::clear()
{
    m_size = 0;
}

void Vector::swap(Vector& v)
{
    int tempSize = m_size;
    int tempCapacity = m_capacity;
    int* tempElements = m_elements;
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_elements = v.m_elements;
    v.m_size = tempSize;
    v.m_capacity = tempCapacity;
    v.m_elements = tempElements;
}

void Vector::print()
{
    for (int i = 0; i < m_size; i++)
    {
        std::cout << m_elements[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Vector v;
    std::cout << "Size of v: " << v.size() << std::endl;
    std::cout << "Capacity of v: " << v.capacity() << std::endl;
    std::cout << "Is v empty? " << std::boolalpha << v.empty() << std::endl;
    std::cout << std::endl;

    Vector v1(5);
    std::cout << "Size of v1: " << v1.size() << std::endl;
    std::cout << "Capacity of v1: " << v1.capacity() << std::endl;
    std::cout << "Is v1 empty? " << std::boolalpha << v1.empty() << std::endl;
    std::cout << std::endl;

    Vector v2(5, 10);
    std::cout << "Size of v2: " << v2.size() << std::endl;
    std::cout << "Capacity of v2: " << v2.capacity() << std::endl;
    std::cout << "Is v2 empty? " << std::boolalpha << v2.empty() << std::endl;
    std::cout << std::endl;

    Vector v3(v2);
    std::cout << "Size of v3: " << v3.size() << std::endl;
    std::cout << "Capacity of v3: " << v3.capacity() << std::endl;
    std::cout << "Is v3 empty? " << std::boolalpha << v3.empty() << std::endl;
    std::cout << std::endl;

    v1.print();
    
    std::cout << std::endl;

    v2.print();
}
