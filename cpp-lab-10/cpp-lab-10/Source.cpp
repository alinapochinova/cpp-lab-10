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

    T pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            length--;
            T value = temp->data;
            delete temp;
            return value;
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
    //int
    std::cout << "int:" << std::endl;
    mypriorityqueue<int> queue1;

    queue1.push(5, 1);
    queue1.push(2, 3);
    queue1.push(3, 2);
    queue1.push(1, 4);

    std::cout << "Queue: " << queue1 << std::endl;
    std::cout << "Size: " << queue1.size() << std::endl;

    std::cout << "Peek: " << queue1.peek() << std::endl;
    std::cout << "After peek: " << queue1 << std::endl;

    std::cout << "Pop: " << queue1.pop() << std::endl;
    std::cout << "After pop: " << queue1 << std::endl;

    std::cout << std::endl;

    //char
    std::cout << "char:" << std::endl;
    mypriorityqueue<char> queue2;

    queue2.push('A', 1);
    queue2.push('C', 3);
    queue2.push('B', 2);
    queue2.push('D', 4);

    std::cout << "Queue: " << queue2 << std::endl;
    std::cout << "Size: " << queue2.size() << std::endl;

    std::cout << "Peek: " << queue2.peek() << std::endl;
    std::cout << "After peek: " << queue2 << std::endl;

    std::cout << "Pop: " << queue2.pop() << std::endl;
    std::cout << "After pop: " << queue2 << std::endl;

    return 0;
}