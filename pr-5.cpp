#include <iostream>
#include <string>
using namespace std;

#define MAX_ITEMS 100

// ===== Abstract Base Class =====
class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    // Constructor
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d) {}

    // Getters (FIXED: const added)
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    // Setters
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

// ===== Derived Class: Book =====
class Book : public LibraryItem {
public:
    Book(string t, string a, string d)
        : LibraryItem(t, a, d) {}

    void checkOut() override {
        cout << "Book \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "Book \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "[Book] Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", Due Date: " << getDueDate() << endl;
    }
};

// ===== Derived Class: DVD =====
class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d), duration(dur) {}

    void checkOut() override {
        cout << "DVD \"" << getTitle() << "\" checked out.\n";
    }

    void returnItem() override {
        cout << "DVD \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override {
        cout << "[DVD] Title: " << getTitle()
             << ", Author: " << getAuthor()
             << ", Duration: " << duration << " mins"
             << ", Due Date: " << getDueDate() << endl;
    }
};

// ===== Library System =====
class Library {
private:
    LibraryItem* items[MAX_ITEMS];
    int count;

public:
    Library() {
        count = 0;
    }

    void addItem(LibraryItem* item) {
        if (count >= MAX_ITEMS)
            throw "Library is full!";
        items[count++] = item;
        cout << "Item added successfully!\n";
    }

    void displayAll() {
        if (count == 0) {
            cout << "No items available.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            items[i]->displayDetails();
        }
    }

    void searchItem(string name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (items[i]->getTitle() == name) {
                items[i]->displayDetails();
                found = true;
            }
        }
        if (!found)
            cout << "Item not found.\n";
    }

    void checkOutItem(string name) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getTitle() == name) {
                items[i]->checkOut();
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void returnItemFunc(string name) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getTitle() == name) {
                items[i]->returnItem();
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Destructor (memory release)
    ~Library() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
    }
};

// ===== MAIN FUNCTION =====
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Display Items\n";
        cout << "4. Search Item\n";
        cout << "5. Check Out\n";
        cout << "6. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string title, author, date;

                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> date;

                lib.addItem(new Book(title, author, date));
            }
            else if (choice == 2) {
                string title, author, date;
                int duration;

                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Due Date: ";
                cin >> date;
                cout << "Enter Duration: ";
                cin >> duration;

                if (duration <= 0)
                    throw "Invalid duration!";

                lib.addItem(new DVD(title, author, date, duration));
            }
            else if (choice == 3) {
                lib.displayAll();
            }
            else if (choice == 4) {
                string name;
                cout << "Enter title to search: ";
                cin >> name;
                lib.searchItem(name);
            }
            else if (choice == 5) {
                string name;
                cout << "Enter title to checkout: ";
                cin >> name;
                lib.checkOutItem(name);
            }
            else if (choice == 6) {
                string name;
                cout << "Enter title to return: ";
                cin >> name;
                lib.returnItemFunc(name);
            }
        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    } while (choice != 0);

    return 0;
}
