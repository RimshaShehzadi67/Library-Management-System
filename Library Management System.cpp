#include <iostream>
#include <string>
using namespace std;

// Struct for user data
struct UserData {
    string username;
    string password;
    UserData* next;
};

// Struct for book data
struct Book {
    int id;
    string title;
    string author;
    string genre;
    Book* next;
};

// Global variables
UserData* userHead = NULL;
Book* bookHead = NULL;

// Function declarations
void menu();
void addBook();
void displayBooks();
void deleteBook();
void searchByGenre();
void searchByAuthor();
void SignUp();
void Login();
void AuthenticationMenu();

// Sign-up function
void SignUp() {
    cout << "\n--- Sign Up ---\n";
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    UserData* newUser = new UserData;
    newUser->username = username;
    newUser->password = password;
    newUser->next = NULL;

    if (!userHead) {
        userHead = newUser;
    } else {
        UserData* temp = userHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newUser;
    }

    cout << "Sign-up successful! Please log in.\n";
    Login();
}

// Login function
void Login() {
    cout << "\n--- Login ---\n";
    if (!userHead) {
        cout << "No users found. Please sign up first.\n";
        SignUp();
        return;
    }

    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    UserData* temp = userHead;
    while (temp) {
        if (temp->username == username && temp->password == password) {
            cout << "\nLogin successful!\n";
            menu();
            return;
        }
        temp = temp->next;
    }

    cout << "Invalid credentials. Please try again.\n";
    Login();
}

// Library management menu
void menu() {
    int choice;
    do {
        cout << "\n--- Library Management ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Search Book by Genre\n";
        cout << "5. Search Book by Author\n";
        cout << "0. Log Out\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                searchByGenre();
                break;
            case 5:
                searchByAuthor();
                break;
            case 0:
                cout << "Logging out...\n";
                AuthenticationMenu();
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

// Function to add a book
void addBook() {
    int id;
    string title, author, genre;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Book Author: ";
    getline(cin, author);
    cout << "Enter Book Genre: ";
    getline(cin, genre);

    Book* newBook = new Book;
    newBook->id = id;
    newBook->title = title;
    newBook->author = author;
    newBook->genre = genre;
    newBook->next = NULL;

    if (!bookHead) {
        bookHead = newBook;
    } else {
        Book* temp = bookHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    cout << "Book added successfully.\n";
}

// Function to display all books
void displayBooks() {
    if (!bookHead) {
        cout << "No books available.\n";
        return;
    }

    cout << "\n--- List of Books ---\n";
    Book* temp = bookHead;
    while (temp) {
        cout << "ID: " << temp->id 
             << ", Title: " << temp->title 
             << ", Author: " << temp->author 
             << ", Genre: " << temp->genre << "\n";
        temp = temp->next;
    }
}

// Function to delete a book by ID
void deleteBook() {
    if (!bookHead) {
        cout << "No books available to delete.\n";
        return;
    }

    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    Book* temp = bookHead;
    Book* prev = NULL;

    while (temp) {
        if (temp->id == id) {
            if (prev) {
                prev->next = temp->next;
            } else {
                bookHead = temp->next;
            }
            delete temp;
            cout << "Book deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Book with ID " << id << " not found.\n";
}

// Function to search books by genre
void searchByGenre() {
    if (!bookHead) {
        cout << "No books available.\n";
        return;
    }

    string genre;
    cin.ignore();
    cout << "Enter Genre to search: ";
    getline(cin, genre);

    Book* temp = bookHead;
    bool found = false;

    while (temp) {
        if (temp->genre == genre) {
            cout << "ID: " << temp->id 
                 << ", Title: " << temp->title 
                 << ", Author: " << temp->author 
                 << ", Genre: " << temp->genre << "\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No books found in the genre \"" << genre << "\".\n";
    }
}

// Function to search books by author
void searchByAuthor() {
    if (!bookHead) {
        cout << "No books available.\n";
        return;
    }

    string author;
    cin.ignore();
    cout << "Enter Author to search: ";
    getline(cin, author);

    Book* temp = bookHead;
    bool found = false;

    while (temp) {
        if (temp->author == author) {
            cout << "ID: " << temp->id 
                 << ", Title: " << temp->title 
                 << ", Author: " << temp->author 
                 << ", Genre: " << temp->genre << "\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No books found by author \"" << author << "\".\n";
    }
}

// Authentication menu
void AuthenticationMenu() {
    int choice;
    do {
        cout << "\n--- User Authentication ---\n";
        cout << "1. Sign Up\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                SignUp();
                return;
            case 2:
                Login();
                return;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Main function
int main() {
    cout << "Welcome to the Library Management System\n";
    AuthenticationMenu();
    return 0;
}

