#include <iostream>
#include <string>
#include <vector>

using namespace std;

class library
{
public:
    vector<string> books;
    vector<string> authors;
    vector<string> issue_books;
    vector<string> issue_book_author;

    void display_book()
    {
        if (books.empty())
        {
            cout << "No books available Please contact Admin for further information!!" << endl;
        }
        for (size_t i = 0; i < books.size(); i++)
        {
            cout << i + 1 << " " << books[i] << " written by: " << authors[i] << endl;
        }
        cout << "------------------------------------------\n";
    }

    void add_books(const string &book, const string &author)
    {
        for (size_t i = 0; i < books.size(); i++)
        {
            if (books[i] == book && authors[i] == author)
            {
                cout << "These book already exist in library\n";
                cout << "------------------------------------------\n";
                return;
            }
        }
        books.push_back(book);
        authors.push_back(author);
        cout << book << " Has added to the library. Written by: " << author << endl;
        cout << "------------------------------------------\n";
    }

    void remove_book(const string &book, const string &author)
    {
        for (size_t i = 0; i < books.size(); i++)
        {
            if (books[i] == book && authors[i] == author)
            {
                books.erase(books.begin() + i);
                authors.erase(authors.begin() + i);
                cout << book << "Has been removed written by: " << author << endl;
                cout << "------------------------------------------\n";
                return;
            }
        }
        cout << "Book not found!" << endl;
        cout << "------------------------------------------\n";
    }

    void issue_book(const string &book, const string &author)
    {
        bool book_found = false;
        for (size_t i = 0; i < books.size(); i++)
        {
            if (books[i] == book && authors[i] == author)
            {
                book_found = true;
                books.erase(books.begin() + i);
                authors.erase(authors.begin() + i);
                issue_books.push_back(book);
                issue_book_author.push_back(author);
                cout << book << " Written by:" << author << "has issued." << endl;
                cout << "------------------------------------------\n";
                cout << "Return the book in 30 days or else there will be penalty.\n";
                cout << "------------------------------------------\n";
                return;
            }
        }
        if(!book_found){
            cout << "Book not found!" << endl;
            cout << "------------------------------------------\n";
        }
    }

    void return_book(const string &book, const string &author)
    {
        for (size_t i = 0; i < issue_books.size(); i++)
        {
            if (issue_books[i] == book && issue_book_author[i] == author)
            {
                issue_books.erase(issue_books.begin() + i);
                issue_book_author.erase(issue_book_author.begin() + i);
                books.push_back(book);
                authors.push_back(author);
                cout << "Book has been returned to the library.\nThank you." << endl;
                cout << "------------------------------------------\n";
                return;
            }
        }
        cout << "Error wrong book has been discovered in the library. Please bring the correct book.\n";
        cout << "------------------------------------------\n";
    }
};

class Admin
{
protected:
    vector<string> student;
    vector<string> password;
    int student_number = 0;

public:
    void new_student();
    void remove_student();
    void check_student(const string &student_username, const string &student_password, library &lb);
    void options()
    {
        library lb;
        while (true)
        {
            int choice;
            string book;
            string author;
            cout << "------------------------------------------\n";
            cout << "Enter one of the choice:\n";
            cout << "1. Add new student.\n";
            cout << "2. Remove old student.\n";
            cout << "3. Total number of students.\n";
            cout << "4. Display all books.\n";
            cout << "5. Add new Book.\n";
            cout << "6. Remove old Book.\n";
            cout << "7. Back.\n";
            cout << "------------------------------------------\n";
            cin >> choice;

            if (choice == 1)
            {
                new_student();
            }
            else if (choice == 2)
            {
                remove_student();
            }
            else if (choice == 3)
            {
                cout << "Total number of students are: " << student_number << endl;
            }
            else if (choice == 4)
            {
                lb.display_book();
            }
            else if (choice == 5)
            {
                cout << "------------------------------------------\n";
                cout << "Enter the book name: ";
                cin.ignore();
                getline(cin, book);
                cout << "Enter the author name: ";
                getline(cin, author);
                cout << "------------------------------------------\n";
                lb.add_books(book, author);
            }
            else if (choice == 6)
            {
                cout << "------------------------------------------\n";
                cout << "Enter the book name: ";
                cin.ignore();
                getline(cin, book);
                cout << "Enter the author name: ";
                getline(cin, author);
                cout << "------------------------------------------\n";
                lb.remove_book(book, author);
            }
            else if (choice == 7)
            {
                break;
            }
            else
            {
                cout << "Invalid choice!\n";
            }
        }
    }
};

void Admin ::new_student()
{
    string student_2;
    string password_2;
    cout << "Enter the student Enrollment number: ";
    cin >> student_2;
    cout << "------------------------------------------\n";
    cout << "Enter the Password for the student " << student_2 << ": ";
    cin >> password_2;
    cout << "------------------------------------------\n";
    for (size_t i = 0; i < student.size(); i++)
    {
        if (student[i] == student_2)
        {
            cout << "Student is already exist.\n";
            cout << "------------------------------------------\n";
            return;
        }
    }
    student.push_back(student_2);
    password.push_back(password_2);
    cout << "Student " << student_2 << " added successfully!\n";
    student_number++;
    cout << "------------------------------------------\n";
}

void Admin ::remove_student()
{
    string student_3;
    cout << "Enter the Enrollment number of the student which you want to remove: ";
    cin >> student_3;
    cout << "------------------------------------------\n";
    bool student_found = false;
    for (size_t i = 0; i < student.size(); i++)
    {
        if (student[i] == student_3)
        {
            student.erase(student.begin() + i);
            password.erase(password.begin() + i);
            cout << "Student with Enrollment number " << student_3 << " Has been removed from the library." << endl;
            cout << "------------------------------------------\n";
            student_found = true;
            student_number--;
            break;
        }
    }
    if (!student_found)
    {
        cout << "Student not found!" << endl;
        cout << "------------------------------------------\n";
    }
}

void Admin ::check_student(const string &student_username, const string &student_password, library &lb)
{

    bool student_found = false;
    for (size_t i = 0; i < student.size(); i++)
    {
        if (student[i] == student_username && password[i] == student_password)
        {
            student_found = true;
            int select;
            while (true)
            {

                cout << "Select one of the option: \n";
                cout << "1. Issue a book." << endl;
                cout << "2. Return a book. " << endl;
                cout << "3. Display List of Books. " << endl;
                cout << "4. Exit. " << endl;
                cin >> select;

                if (select == 1)
                {
                    string book;
                    string author;
                    cout << "Enter the book Name: ";
                    cin.ignore();
                    getline(cin, book);
                    cout << "Enter the author Name: ";
                    getline(cin, author);
                    cout << "------------------------------------------\n";
                    lb.issue_book(book, author);
                }

                else if (select == 2)
                {
                    string book;
                    string author;
                    cout << "Enter the book name: ";
                    cin.ignore();
                    getline(cin, book);
                    cout << "Enter the author name: ";
                    getline(cin, author);
                    cout << "------------------------------------------\n";
                    lb.return_book(book, author);
                }

                else if(select == 3){
                    lb.display_book();
                }

                else if (select == 4)
                {
                    break;
                }

                else
                {
                    cout << "------------------------------------------\n";
                    cout << "Enter the correct Entry!!\n"
                         << endl;
                }
            }
            return;
        }
    }
    if (!student_found)
    {
        cout << " Student not found or incorrect Password!" << endl;
    }
}

int main()
{
    system("cls");
    string admin_username = "Admin@.com";
    string admin_password = "12345678";
    Admin ad;
    library lb;

    int select;
    while (true)
    {
        cout << "------------------------------------------\n";
        cout << "Welcome to the Eternal Library!!\n";
        cout << "Select one of the option:\n";
        cout << "1. Student" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Exit\n"
             << endl;
        cin >> select;
        cout << "------------------------------------------\n";

        if (select == 1)
        {
            string student_username;
            string student_password;
            cout << "Enter the user name: ";
            cin.ignore();
            cin >> student_username;
            cout << "Enter the Password: ";
            cin >> student_password;
            ad.check_student(student_username, student_password, lb);
        }

        else if (select == 2)
        {
            string username;
            string password;
            cout << "Enter the username: ";
            cin >> username;
            cout << "Enter the Password: ";
            cin >> password;
            cout << "------------------------------------------\n";

            if (username == admin_username && password == admin_password)
            {
                ad.options();
            }

            else
            {
                cout << "Invalid ID or Password!!\n";
            }
        }

        else if (select == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid input!!" << endl;
        }
    }
    return 0;
}