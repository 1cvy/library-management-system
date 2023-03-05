# library_management_system
PROJECT: LIBRARY MANAGEMENT SYSTEM

DESCRIPTION
Library Management System is a system for librarians to keep track of their books in the library. This system allows the admin to manage user accounts and the librarian to manage books in the system. Admin can add, edit, delete, search, view all users and sorting features. Librarians can add, edit, delete, search, view all books and sorting features.

APP MODULES AND FEATURES
USER MANAGEMENT
Admin can add  user accounts to the system
Admin can edit user accounts from the system
Admin can delete user accounts from the system
Admin can search user accounts from the system for details
Admin can view all user accounts from the system
Admin can use sorting features (Admins first or Librarians first)
BOOK MANAGEMENT
Librarian can add books to the system
Librarian can edit books from the system
Librarian can delete books from the system
Librarian can search books from the system for details
Librarian can view all books from the system
Librarian can use sorting features (A-Z or Z-A)

UI DESIGN
Account Authentication:
LIBRARY MANAGEMENT SYSTEM
[1] LOGIN ACCOUNT
[0] CLOSE
Users just need to press keys from their keyboards to proceed forward; they don’t need to input their option number and press enter.
1.1. Login Account
	LOGIN
	Username: Admin
	Password: Admin
There are 2 types of accounts which are admin and librarian. Admin have access to user account management. Librarians have access to book management.
1.3. Close
	This option will close the program immediately.
After user successfully log in to their account they will be greeted with this menu:
1.1.2. For admin account
	     	ADMIN
			[1] ADD USER
			[2] EDIT USER
			[3] DELETE USER
			[4] SEARCH USER
			[5] SORT ALL USERS
			[5] VIEW ALL USERS
			[6] SAVE ALL USERS TO FILE
			[7] LOAD ALL USERS FROM FILE
			[0] LOG OUT
			1.1.2.1.1. If users choose option [1]
				ADD USER
				Username: Librarian
				Password: Librarian
				Role: Librarian
After users input their desired username, password and role then they will be greeted with input validation and input confirmation.
			1.1.2.1.2. If user choose option [2]
				EDIT USER ACCOUNT
				Search Username: Librarian
If the username is not in the system then there will be a message telling users that it is an invalid user account.
				Then:
				Current username: Librarian
				Current password: Librarian
				Current role: Librarian
				Are you sure you wanted to edit this user?
				[Y] Yes
				[N] No
				Then:
				New Username: Librarian2
				New Password: Librarian2
				New Role: Librarian
				Are you sure you wanted to edit this user?
				[Y] Yes
				[N] No
				Then:
You have successfully edited an user account from the system.
1.1.2.1.3. If user choose option [3]
	DELETE USER
				Search Username: Librarian
If the username is not in the system then there will be a message telling users that it is an invalid user account.
				Then:
				Username: Librarian
				Password: Librarian
				Role: Librarian
				Are you sure you wanted to delete this user?
				[Y] Yes
				[N] No
				Then:
You have successfully deleted an user account from the system.
1.1.2.1.4. If user choose option [4]
	SEARCH USER ACCOUNT
	Search Username: Librarian
If the username is not in the system then there will be a message telling users that it is an invalid user account.
				Then:
				Current username: Librarian
				Current password: Librarian
				Current role: Librarian
			1.1.2.1.5. If user choose option [5]
				SORT ALL USERS
				[1] Admins first
				[2] Librarians first
1.1.2.1.6. If user choose option [6]
VIEW ALL USERS
#		Username		Password		Role
1		admin			admin			admin
2		librarian		librarian		librarian
1.1.2.1.7. If user choose option [7]
All user accounts data will be saved to a binary file.
1.1.2.1.8. If user choose option [8]
All user accounts data will be loaded from a binary file.
		1.1.2.2. If user choose option [0]
They will be logged out of the account and go back to the first menu of the system.
	1.1.3. For librarian account
	     	LIBRARIAN
			[1] ADD BOOK
			[2] EDIT BOOK
			[3] DELETE BOOK
			[4] SEARCH BOOK
			[5] SORT ALL BOOKS
			[6] VIEW ALL BOOKS
[7] SAVE ALL BOOKS TO FILE
			[8] LOAD ALL BOOKS FROM FILE
			[0] LOG OUT
	1.1.3.1.1. If users choose option [1]
				ADD BOOK
				What type of book?
				[1] Local book
				[2] International book
				[0] Cancel
				Then:
				ADD INTERNATIONAL BOOK
				New book name: Book A
				New book author: Mr. A
				New book language: English
				You have successfully added a book!!
			1.1.3.1.2. If user choose option [2]
				EDIT BOOK
				Search Name: Book A
If the book is not in the system then there will be a message telling users that it is an invalid book.
				Then:
				Current book name: Book A
				Current book author: Mr. A
				Current book language: English
				Are you sure you wanted to edit this book?
				[Y] Yes
				[N] No
				Then:
				New book name: Book B
				New book author: Mr. B
				New book language: English
				Then:
You have successfully edited a book from the system.
1.1.3.1.3. If user choose option [3]
	DELETE BOOK
				Search Name: Book A
If the book is not in the system then there will be a message telling users that it is an invalid book.
				Then:
				Current book name: Book A
				Current book author: Mr. A
				Current book language: English
				Are you sure you wanted to delete this book?
				[Y] Yes
				[N] No
				Then:
You have successfully deleted a book from the system.
1.1.3.1.4. If user choose option [4]
	SEARCH BOOK
	Search book name: Book A
If the book is not in the system then there will be a message telling users that it is an invalid book.
				Then:
				Current book name: Book A
				Current book author: Mr. A
				Current book language: English
			1.1.3.1.5. If user choose option [5]
				SORT ALL BOOKS
				[1] A-Z
				[2] Z-A
1.1.3.1.5. If user choose option [6]
VIEW ALL BOOKS
#		Name			Author		Language
1		Book A		Mr. A			Khmer
2		Book B		Mr. B			English
1.1.3.1.6. If user choose option [7]
All books data will be saved to a binary file.
1.1.3.1.7. If user choose option [8]
All books data will be loaded from a binary file.
1.1.3.2. If user choose option [0]
They will be logged out of the account and go back to the first menu of the system.

THANK YOU
