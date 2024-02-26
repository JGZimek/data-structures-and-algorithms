#include <iostream>
#include <memory>

template <typename T>
class NodeList
{
public:
    T data;
    std::shared_ptr<NodeList<T>> next;
    std::shared_ptr<NodeList<T>> prev;

    NodeList(T data_arg) : data(data_arg), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    std::shared_ptr<NodeList<T>> head;
    std::shared_ptr<NodeList<T>> tail;
    size_t size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() = default;

    bool is_empty() const;
    void add_first(T data_arg);
    void remove_first();
    void add_last(T data_arg);
    void remove_last();
    void display() const;
    bool search(T data_arg) const;
    size_t get_size() const;
};

template <typename T>
bool LinkedList<T>::is_empty() const
{
    return size == 0;
}

template <typename T>
void LinkedList<T>::add_first(T data_arg)
{
    std::shared_ptr<NodeList<T>> new_NodeList = std::make_shared<NodeList<T>>(data_arg);
    if (is_empty())
    {
        head = tail = new_NodeList;
    }
    else
    {
        new_NodeList->next = head;
        head->prev = new_NodeList;
        head = new_NodeList;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove_first()
{
    if (!is_empty())
    {
        std::shared_ptr<NodeList<T>> temp = head;
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
void LinkedList<T>::add_last(T data_arg)
{
    std::shared_ptr<NodeList<T>> new_NodeList = std::make_shared<NodeList<T>>(data_arg);
    if (is_empty())
    {
        head = tail = new_NodeList;
    }
    else
    {
        new_NodeList->prev = tail;
        tail->next = new_NodeList;
        tail = new_NodeList;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove_last()
{
    if (!is_empty())
    {
        std::shared_ptr<NodeList<T>> temp = tail;
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
    std::shared_ptr<NodeList<T>> current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::search(T data_arg) const
{
    std::shared_ptr<NodeList<T>> current = head;
    while (current)
    {
        if (current->data == data_arg)
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