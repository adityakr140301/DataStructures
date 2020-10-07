// singly linked list implementation
#include "iostream"

using namespace std;

// node structure
template<typename T>
struct node
    {
        T data;
        node *next;
    };

template <class T>
class singly_linked
{
private:
    int size;
    node<T> *temp, *head;

public:
    node<T> *iterator;
    singly_linked();
    void add_element(T);
    void remove_element(T);
    void pop_element();
    void display();
};
template <class T>
singly_linked<T>::singly_linked()
{
    size = 0;
    head = NULL;
}
template <class T>
void singly_linked<T>::add_element(T d)
{
    temp = new node<T>;
    temp->data = d;
    temp->next = head;
    head = temp;
    temp = NULL;
    size++;
}
template <class T>
void singly_linked<T>::remove_element(T d)
{
    temp = head;
    node<T> *temp1 = head->next;
    bool found = false;
    while (temp1 != NULL)
    {
        if (temp1->data == d)
        {
            temp->next = temp1->next;
            temp1->next = NULL;
            size--;
            found = true;
        }
        temp1 = temp1->next;
        temp = temp->next;
    }
}
template <class T>
void singly_linked<T>::pop_element()
{
    if (head != NULL)
    {
        temp = head->next;
        head->next = NULL;
        head = temp;
        size--;
    }
}
template<class T>
void singly_linked<T>::display(){
    temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    singly_linked<int> sl;
    for (int i = 0; i < 50; i++)
    {
        sl.add_element(i);
    }
    sl.display();
    for (int i = 0; i < 20; i++)
    {
        sl.remove_element(i*2);
    }
    sl.display();

    return 0;
}
