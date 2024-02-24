#include <iostream>
#include <memory>

template <typename T>
class Node
{
public:
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() = default;

    bool is_empty() const;
    void add_first(T value);
    void remove_first();
    void add_last(T value);
    void remove_last();
    void display() const;
    bool search(T value) const;
    size_t get_size() const;
};

template <typename T>
bool LinkedList<T>::is_empty() const
{
    return size == 0;
}

template <typename T>
void LinkedList<T>::add_first(T value)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(value);
    if (is_empty())
    {
        head = tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove_first()
{
    if (!is_empty())
    {
        std::shared_ptr<Node<T>> temp = head;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        size--;
    }
}

template <typename T>
void LinkedList<T>::add_last(T value)
{
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(value);
    if (is_empty())
    {
        head = tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove_last() 
{
    if (!is_empty())
    {
        std::shared_ptr<Node<T>> temp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        size--;
    }
}

template <typename T>
void LinkedList<T>::display() const
{
    std::shared_ptr<Node<T>> current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
    std::shared_ptr<Node<T>> current = head;
    while (current)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;        
    }
    return false;
}

template <typename T>
size_t LinkedList<T>::get_size() const
{
    return size;
}