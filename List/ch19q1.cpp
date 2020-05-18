#include <iostream>
using namespace std;
// implement the list class given in the book with templates
template <typename T>
class List {
private:
public:
    List():head(0), tail(0), theCount(0){}
    virtual ~List();
    void insert(T value);
    void append(T value);
    T is_present (T value) const;
    T is_empty() const {return head == 0;}
    T count() const {return theCount;}
private:
    class ListCell {
    public:
        ListCell(T value, ListCell *cell = 0): val(value), next(cell){}
        T val;
        ListCell *next;
    };
    ListCell *head;
    ListCell *tail;
    T theCount;
};


int main() {

    return 0;
}
