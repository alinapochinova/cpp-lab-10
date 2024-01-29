#include <iostream>

template<typename T>
class mypriorityqueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;

        Node(const T& item, int p) : data(item), priority(p), next(nullptr) {}
    };

    Node* head;
    int length;

public:
    mypriorityqueue() : head(nullptr), length(0) {}

    ~mypriorityqueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& item, int priority) {
        Node* newNode = new Node(item, priority);

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && priority <= current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        length++;
    }

    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    const T& peek() const {
        if (head != nullptr) {
            return head->data;
        }
        throw std::runtime_error("Queue is empty");
    }

    int size() const {
        return length;
    }
    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const mypriorityqueue<T>& queue) {
        typename mypriorityqueue<T>::Node* current = queue.head;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};



int main() {
    mypriorityqueue<int> queue;

    queue.push(5, 1);
    queue.push(2, 3);
    queue.push(3, 2);
    queue.push(1, 4);

    std::cout << "Queue: " << queue << std::endl;
    std::cout << "Size: " << queue.size() << std::endl;

    std::cout << "Peek: " << queue.peek() << std::endl;
    queue.pop();
    std::cout << "After pop: " << queue << std::endl;

    return 0;
}