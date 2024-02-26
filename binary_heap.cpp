#include <iostream>
#include <vector>

template <typename T, typename P>
class NodeHeap
{
public:
    T data;
    P priority;

    NodeHeap(T data_arg, P priority_arg) : data(data_arg), priority(priority_arg) {}
    ~NodeHeap() = default;
};

template <typename T, typename P>
class BinaryHeap
{
private:
    std::vector<NodeHeap<T, P>> heap;
    size_t size;

    void heapify_up(int index);
    void heapify_down(int index);

public:
    BinaryHeap() : size(0) {}
    ~BinaryHeap() = default;

    bool is_empty() const;
    void insert(T data_arg, P priority_arg);
    void remove_root();
    void display() const;
    bool search(T data_arg) const;
    size_t get_size() const;
};

template <typename T, typename P>
void BinaryHeap<T, P>::heapify_up(int index)
{
    if (index == 0)
    {
        return;
    }

    int parent_index = (index - 1) / 2;
    if (heap[parent_index].priority > heap[index].priority)
    {
        std::swap(heap[parent_index], heap[index]);
        heapify_up(parent_index);
    }
}

template <typename T, typename P>
void BinaryHeap<T, P>::heapify_down(int index)
{
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    if (left_child_index < heap.size() && heap[left_child_index].priority < heap[index].priority)
    {
        std::swap(heap[index], heap[left_child_index]);
        heapify_down(left_child_index);
    }

    if (right_child_index < heap.size() && heap[right_child_index].priority < heap[index].priority)
    {
        std::swap(heap[index], heap[right_child_index]);
        heapify_down(right_child_index);
    }
}

template <typename T, typename P>
bool BinaryHeap<T, P>::is_empty() const
{
    return heap.empty();
}

template <typename T, typename P>
void BinaryHeap<T, P>::insert(T data_arg, P priority_arg)
{
    NodeHeap<T, P> new_NodeHeap(data_arg, priority_arg);
    heap.push_back(new_NodeHeap);
    heapify_up(heap.size() - 1);
    size++;
}

template <typename T, typename P>
void BinaryHeap<T, P>::remove_root()
{
    if (!is_empty())
    {
        heap[0] = std::move(heap.back());
        heap.pop_back();
        heapify_down(0);
        size--;
    }
}

template <typename T, typename P>
void BinaryHeap<T, P>::display() const
{
    for (const auto &NodeHeap : heap)
    {
        std::cout << "(" << NodeHeap.data << ", " << NodeHeap.priority << ") ";
    }
    std::cout << std::endl;
}

template <typename T, typename P>
bool BinaryHeap<T, P>::search(T data_arg) const
{
    for (const auto &NodeHeap : heap)
    {
        if (NodeHeap.data == data_arg)
        {
            return true;
        }
    }
    return false;
}

template <typename T, typename P>
size_t BinaryHeap<T, P>::get_size() const
{
    return size;
}