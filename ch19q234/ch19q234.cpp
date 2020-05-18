#include <iostream>
#include <iterator>
using namespace std;
// implement the list class given in the book with templates

class Cat {
private:
    string name;
public:
    friend ostream& operator<<(ostream& os, const Cat& rhs) {
        os << rhs.name;
        return os;
    }
    friend bool operator==(const Cat& lhs, const Cat& rhs) {
        return (lhs == rhs);
    }
    Cat(string name) : name(name) {}
};
template <typename T>
class List {
public:
    List():head(nullptr), tail(nullptr), theCount(0) {}

    virtual ~List() {};
    void insert(T value);
    void append(T value);
    int is_present (T value) const;
    T is_empty() const {return head == 0;}
    int count() const {return theCount;}
    void showList() const;
private:
    class ListCell {
    public:
        ListCell(T value, ListCell *cell = nullptr): val(value), next(cell){}
        T val;
        ListCell *next;

    };
    ListCell *head;
    ListCell *tail;
    int theCount;
};
template <typename T>
void List<T>::showList() const {
    ListCell* current = this->head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
template <typename T>
void List<T>::insert(T value) {
    auto *toInsert = new ListCell(value, head);
    if (head == nullptr) {
        tail = toInsert;
    }
    head = toInsert;
    theCount++;
}
template <typename T>
void List<T>::append(T value) {
    auto *toPush = new ListCell(value);
    if (head == nullptr) {
        head = toPush;
    } else {
        tail->next = toPush;
    }
    tail = toPush;
    theCount++;

}
template <typename T>
int List<T>::is_present(T value) const {
    if (head == nullptr) {
        return 0;
    }
    if (head->val == value || tail->val == value) {
        return 1;
    }
    ListCell* current = this->head;
    while (current->next != nullptr) {
        if (current->next->val == value) {
            return 1;
        } else {
            current = current->next;
        }
    }
}

int main() {
    cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "TRYING TEMPLATE FOR INT TYPE PARAMETER..." << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
    List<int> newlist;
    cout << "~Insert at the beginning...~" << endl;
    newlist.insert(2);
    newlist.showList();
    newlist.insert(1);
    newlist.showList();
    newlist.insert(10);
    newlist.showList();
    cout << endl;

    cout << "~push_back...~" << endl;
    newlist.append(90);
    newlist.showList();
    newlist.append(23);
    newlist.showList();
    newlist.append(34);
    newlist.showList();
    cout << endl;

    cout << "~insert at the beginning again...~" << endl;
    newlist.insert(67);
    newlist.showList();
    int num;
    cout << endl;
    cout << "Enter a number to check if it's in the list. " << endl;
    cin >> num;
    if (newlist.is_present(num) == 0) {
        cout << "This number " << num << " is not in the list." << endl;
    } else {
        cout << "The number "<< num <<" does exist in the list!" << endl;
    }
    cout << "There are " << newlist.count() << " items in this list." << endl;
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "TRYING TEMPLATE FOR STRING TYPE PARAMETER..." << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
    List<string> strList;
    strList.append("goodbye");
    strList.append("au revoir");
    strList.append("adios");
    cout << "~print out contents of str list...~" << endl;
    strList.showList();
    cout << endl;
    cout << "~using the insert method...~" << endl;
    strList.insert("wait");
    strList.showList();
    cout << endl;

    string word;
    cout << "Enter a string to check if it's in the list. " << endl;
    cin >> word;

    if (strList.is_present(word) == 0) {
        cout << "This word " << word << " is not in the list." << endl;
    } else {
        cout << "The word "<< word <<" does exist in the list!" << endl;
    }
    cout << endl;

    cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "TRYING TEMPLATE FOR CAT CLASS TYPE PARAMETER..." << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
    cout << endl;

    List<Cat> litter;
    Cat alfie("Alfie");
    Cat josie("Josie");
    Cat irma("Irma");
    Cat dolly("Dolly");
    cout << "Appending the litter list..." << endl;
    litter.append(alfie);
    litter.showList();
    litter.append(josie);
    litter.showList();
    cout << endl;

    cout << "Putting some cats in the front..." << endl;
    litter.insert(irma);
    litter.showList();
    litter.insert(dolly);
    litter.showList();

    cout << "HI "<< litter.is_present(dolly) << endl;

    return 0;
}
