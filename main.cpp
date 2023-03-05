#include <iostream>
#include <string>
#include "local_book.cpp"
#include "international_book.cpp"
#include "book_manager.cpp"
#include "sort_all_books_input_exception.cpp"
#include "user_manager.cpp"
#include "invalid_option_exception.cpp"

using namespace std;

string local_book::local_language = "Khmer";

enum ADMIN_OPTIONS
{
    ADD_USER = '1',
    EDIT_USER = '2',
    DELETE_USER = '3',
    SEARCH_USER = '4',
    SORT_ALL_USERS = '5',
    VIEW_ALL_USERS = '6',
    LOG_OUT = '0',
};

enum LIBRARIAN_OPTIONS 
{
    ADD_BOOK = '1',
    EDIT_BOOK = '2',
    DELETE_BOOK = '3',
    SEARCH_BOOK = '4',
    SORT_ALL_BOOKS = '5',
    VIEW_ALL_BOOKS = '6',
    //LOG_OUT = 0
};

int main()
{
    try
    {
        user user1;
        user1.set_username("Admin");
        user1.set_password("Admin");
        user1.set_role("Admin");
        user user2;
        user2.set_username("Librarian");
        user2.set_password("Librarian");
        user2.set_role("Librarian");
        user_manager user_manager;
        user_manager.add_user(user1);
        user_manager.add_user(user2);
        book_manager book_manager;

        do
        {
            system("cls");
            cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
            cout << "[1] Login" << endl;
            cout << "[0] Close" << endl;
            char user_option = _getch();
            switch (user_option)
            {
                case '1':
                {
                    system("cls");
                    cout << "LOGIN" << endl;
                    cout << "Username: ";
                    string user_input;
                    getline(cin, user_input);
                    int i = user_manager.get_user_indice(user_input);
                    if (i != -1)
                    {
                        cout << "Password: ";
                        getline(cin, user_input);
                        if (user_manager.get_user(i).get_password() == user_input)
                        {
                            if (user_manager.get_user(i).get_role() == "Admin")
                            {
                                do
                                {
                                    system("cls");
                                    cout << "ADMIN" << endl;
                                    cout << "[1] Add user" << endl;
                                    cout << "[2] Edit user" << endl;
                                    cout << "[3] Delete user" << endl;
                                    cout << "[4] Search user" << endl;
                                    cout << "[5] Sort all users" << endl;
                                    cout << "[6] View all users" << endl;
                                    cout << "[0] Log out" << endl;
                                    char user_option = _getch();
                                    switch (user_option)
                                    {
                                    case ADD_USER:
                                    {
                                        system("cls");
                                        cout << "ADD USER" << endl;
                                        user user;
                                        cout << "New username: ";
                                        getline(cin, user_input);
                                        user.set_username(user_input);
                                        cout << "New password: ";
                                        getline(cin, user_input);
                                        user.set_password(user_input);
                                        cout << "New role (Admin|Librarian): ";
                                        getline(cin, user_input);
                                        user.set_role(user_input);
                                        user_manager.add_user(user);
                                        cout<<"You have successfully added an user!!"<<endl;
                                        system("pause");
                                        break;
                                    }
                                    case EDIT_USER:
                                    {
                                        system("cls");
                                        cout << "EDIT USER" << endl;
                                        cout << "Search username: ";
                                        getline(cin, user_input);
                                        user_manager.edit_user(user_input);
                                        system("pause");
                                        break;
                                    }
                                    case DELETE_USER:
                                    {
                                        system("cls");
                                        cout << "DELETE USER" << endl;
                                        cout << "Search username: ";
                                        getline(cin, user_input);
                                        user_manager.delete_user(user_input);
                                        system("pause");
                                        break;
                                    }
                                    case SEARCH_USER:
                                    {
                                        system("cls");
                                        cout << "SEARCH USER" << endl;
                                        cout << "Search username: ";
                                        getline(cin, user_input);
                                        user_manager.search_user(user_input);
                                        system("pause");
                                        break;
                                    }
                                    case SORT_ALL_USERS:
                                    {
                                        system("cls");
                                        cout << "SORT ALL USERS" << endl;
                                        cout << "[1] Admins first" << endl;
                                        cout << "[2] Librarians first" << endl;
                                        cout << "[0] Back" << endl;
                                        user_option = _getch();
                                        switch (user_option)
                                        {
                                        case '1':
                                        {
                                            user_manager.sort_all_users(1);
                                            system("cls");
                                            cout << "You have succesfully sorted all users!!" << endl;
                                            system("pause");
                                            break;
                                        }
                                        case '2':
                                        {
                                            user_manager.sort_all_users(2);
                                            system("cls");
                                            cout << "You have succesfully sorted all users!!" << endl;
                                            system("pause");
                                            break;
                                        }
                                        case '0':
                                        {

                                            break;
                                        }
                                        default:
                                        {
                                            throw invalid_option_exception();
                                            break;
                                        }
                                        }
                                        break;
                                    }
                                    case VIEW_ALL_USERS:
                                    {
                                        system("cls");
                                        cout << "VIEW ALL USERS" << endl;
                                        user_manager.view_all_users();
                                        system("pause");
                                        break;
                                    }
                                    case LOG_OUT:
                                    {
                                        goto exit_loop1;
                                        break;
                                    }
                                    default:
                                    {
                                        throw invalid_option_exception();
                                        break;
                                    }
                                    }
                                } while (true);
                            exit_loop1:;
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "LIBRARIAN" << endl;
                                    cout << "[1] Add book" << endl;
                                    cout << "[2] Edit book" << endl;
                                    cout << "[3] Delete book" << endl;
                                    cout << "[4] Search book" << endl;
                                    cout << "[5] Sort all books" << endl;
                                    cout << "[6] View all books" << endl;
                                    cout << "[0] Log out" << endl;
                                    char user_option = _getch();
                                    switch (user_option)
                                    {
                                    case ADD_BOOK:
                                    {
                                        system("cls");
                                        cout << "What type of book?" << endl;
                                        cout << "[1] Local book" << endl;
                                        cout << "[2] International book" << endl;
                                        cout << "[0] Cancel" << endl;
                                        char user_option = _getch();
                                        //book* book;
                                        switch (user_option)
                                        {
                                        case '1':
                                        {
                                            system("cls");
                                            cout << "ADD LOCAL BOOK" << endl;
                                            cout << "New book name: ";
                                            string name;
                                            getline(cin, name);
                                            local_book input_validation;
                                            input_validation.set_name(name);
                                            cout << "New book author: ";
                                            string author;
                                            getline(cin, author);
                                            input_validation.set_author(author);
                                            cout << "New language: ";
                                            string language;
                                            getline(cin, language);
                                            //input_validation.set_language(language);
                                            book_manager.add_book(new local_book(name, author, language));
                                            system("pause");
                                            break;
                                        }
                                        case '2':
                                        {
                                            system("cls");

                                            cout << "ADD INTERNATIONAL BOOK" << endl;
                                            cout << "New book name: ";
                                            string name;
                                            getline(cin, name);
                                            international_book input_validation;
                                            input_validation.set_name(name);
                                            cout << "New book author: ";
                                            string author;
                                            getline(cin, author);
                                            input_validation.set_author(author);
                                            cout << "New language: ";
                                            string language;
                                            getline(cin, language);
                                            //input_validation.set_language(language);
                                            book_manager.add_book(new international_book(name, author, language));
                                            system("pause");
                                            break;
                                        }
                                        case '0':
                                        {

                                            break;
                                        }
                                        default:
                                        {
                                            throw invalid_option_exception();
                                            break;
                                        }
                                        }
                                        break;
                                    }
                                    case EDIT_BOOK:
                                    {
                                        system("cls");
                                        cout << "EDIT BOOK" << endl;
                                        cout << "Search book name: ";
                                        getline(cin, user_input);
                                        book_manager.edit_book(user_input);
                                        system("pause");
                                        break;
                                    }
                                    case DELETE_BOOK:
                                    {
                                        system("cls");
                                        cout << "DELETE BOOK" << endl;
                                        cout << "Search book name: ";
                                        getline(cin, user_input);
                                        book_manager.delete_book(user_input);
                                        system("pause");
                                        break;
                                    }
                                    case SEARCH_BOOK:
                                    {
                                        system("cls");
                                        cout << "SEARCH BOOK" << endl;
                                        cout << "Search book name: ";
                                        getline(cin, user_input);
                                        book_manager.search_book(user_input);
                                        system("pause");
                                        break;
                                    }
                                    case SORT_ALL_BOOKS:
                                    {
                                        system("cls");
                                        cout << "SORT ALL BOOKS" << endl;
                                        cout << "[1] A-Z" << endl;
                                        cout << "[2] Z-A" << endl;
                                        cout << "[0] Back" << endl;
                                        user_option = _getch();
                                        switch (user_option)
                                        {
                                        case '1':
                                        {
                                            book_manager.sort_all_books(1);
                                            system("cls");
                                            cout << "You have succesfully sorted all books!!" << endl;
                                            system("pause");
                                            break;
                                        }
                                        case '2':
                                        {
                                            book_manager.sort_all_books(2);
                                            system("cls");
                                            cout << "You have succesfully sorted all books!!" << endl;
                                            system("pause");
                                            break;
                                        }
                                        case '0':
                                        {

                                            break;
                                        }
                                        default:
                                        {
                                            throw invalid_option_exception();
                                            break;
                                        }
                                        }
                                        break;
                                    }
                                    case VIEW_ALL_BOOKS:
                                    {
                                        system("cls");
                                        cout << "VIEW ALL BOOKS" << endl;
                                        book_manager.view_all_books();
                                        system("pause");
                                        break;
                                    }
                                    case LOG_OUT:
                                    {
                                        goto exit_loop2;
                                        break;
                                    }
                                    default:
                                    {
                                        throw invalid_option_exception();
                                        break;
                                    }
                                    }
                                } while (true);
                            exit_loop2:;
                            }
                        }
                        else
                        {
                            cout << "Incorrect password!!" << endl;
                            system("pause");
                        }
                    }
                    else
                    {
                        cout << "User not found!!" << endl;
                        system("pause");
                    }
                    break;
                }
                case '0':
                {
                    system("cls");
                    cout << "You have successfully closed the system!!" << endl;
                    system("pause");
                    goto exit_loop3;
                    break;
                }
                default:
                {
                    throw invalid_option_exception();
                    break;
                }
            }
        } while (true);
    }
    catch (yes_or_no_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (book_name_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (book_author_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (book_language_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (sort_all_books_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (invalid_option_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (password_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (role_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (sort_all_users_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
    catch (username_input_exception& exception)
    {
        system("cls");
        cout << "Exception: " << exception.what() << endl;
        system("pause");
    }
exit_loop3:;
    return 0;
}
