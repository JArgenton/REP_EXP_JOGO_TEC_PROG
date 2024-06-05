#pragma once 
template <typename T>
class Node {
    private:
        T* data;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node();
        ~Node();

        void setData;
        void setNext;
        void setPrev;
        
        T* getData;
        T* getNext;
        T* getPrev;

};


namespace List{

    template <typename T>
    class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        List() : head(nullptr), tail(nullptr), size(0) {}
        ~List() {
            clear();
        }
        void push(const T* elem) {
            Node<T>* newNode = new Node<T>(value);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            size++;
        }
        void clear() {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* next = current->next;
                delete current;
                current = next;
            }

            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        int getsize() {

            return size;
        }
        
        T* pop(T* elem){
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return nullptr;
            }

            Node<T>* current = head;
            Node<T>* prev = nullptr;
            while (current != nullptr) {
                if (current->getData() == elem) {
                    if (prev == nullptr) {
                        head = current->next;
                    } else {
                        prev->next = current->next;
                    }

                    if (current == tail) {
                        tail = prev;
                    }

                    T* data = current->getData();
                    delete current;
                    size--;
                    return data;
                }

                prev = current;
                current = current->next;
            }

            cout << "Element not found" << endl;
            return nullptr;
        }
        T* pop(int index) {
            if (index < 0 || index >= size) {
                cout << "Index out of bounds" << endl;
                return nullptr;
            }

            Node<T>* current = head;
            Node<T>* prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            if (current == tail) {
                tail = prev;
            }

            T* data = current->getData();
            delete current;
            size--;
            return data;
        }
        
        T* operator[](int index) {
            if (index < 0 || index >= size) {
                cout << "Index out of bounds" << endl;
                return nullptr;
            }

            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            return current->getData();
        }
        


        }; // class List
} // namespace List