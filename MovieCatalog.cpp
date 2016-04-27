#include "MovieCatalog.h"
#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <string>

using namespace std;

MovieCatalog::MovieCatalog() {
    hashSize = 0;
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = NULL;
    }
}

MovieCatalog::~MovieCatalog() {
    //dtor
}

void MovieCatalog::printCatalog() {

    string choice;
    bool quit = false;

    while (quit != true) {
        vector <MovieNode*> printOrder;
        MovieNode *tmp;
        MovieNode *hold = NULL;
        bool found = false;
        int counter = 0;
        int large;
        int small;

        cout << "How would you like to organize the catalog?" << endl;
        cout << "1. Alphabetically (A - Z)" << endl;
        cout << "2. Alphabetically (Z - A)" << endl;
        cout << "3. Price (Highest - Lowest)" << endl;
        cout << "4. Price (Lowest - Highest)" << endl;
        cout << "5. Exit to Main Menu" << endl;

        getline(cin, choice);

        /// A - Z
        if (choice == "1") {
            counter = 0;
            while (counter < hashSize) {
                for (int i = 0; i < tableSize; i++) { /// value is < 0 if str1 comes before str2
                    tmp = hashTable[i];
                    while (tmp != NULL) {
                        if (hold == NULL) {
                            hold = tmp;
                        }
                        if (hold -> visited == true) {
                            hold = tmp;
                        }
                        if ((hold -> title).compare(tmp -> title) >= 0 && tmp -> visited == false) {
                            hold = tmp;
                        }
                        //cout<<(hold -> title).compare(tmp -> title)<<endl;
                        tmp = tmp -> next;
                    }
                }
                hold -> visited = true;
                printOrder.push_back(hold);
                counter++;
            }
            for (int i = 0; i < printOrder.size(); i++) {
                printOrder[i] -> ID = i + 1;
                cout << "ID: " << printOrder[i] -> ID << " Title: " << printOrder[i] -> title << " Price: $" << printOrder[i] -> price << " Condition: " << printOrder[i] -> quality << endl;
            }
            bool quitPrint = false;

            while (quitPrint != true) {
                cout << "Choose a movie by its ID # to add it to your cart." << endl;
                cout << "Or select 0 to return to the print menu." << endl;
                string IDchoice;
                getline(cin, IDchoice);

                if (IDchoice == "0") {
                    quitPrint = true;
                }
                else {
                    int IDchoice2num = stoi(IDchoice);
                    for (int j = 0; j < printOrder.size(); j++) {
                        if (printOrder[j] -> ID == IDchoice2num)
                            addCart(printOrder[j]);
                    }
                }
            }
            reset();
        }
        /// Z - A
        if (choice == "2") {
            counter = 0;
            while (counter < hashSize) {
                for (int i = 0; i < tableSize; i++) {
                    tmp = hashTable[i];
                    while (tmp != NULL) {
                        if (hold == NULL) {
                            hold = tmp;
                        }
                        if (hold -> visited == true) {
                            hold = tmp;
                        }
                        if ((hold -> title).compare(tmp -> title) <= 0 && tmp -> visited == false) {
                            hold = tmp;
                        }
                        tmp = tmp -> next;
                    }
                }
                hold -> visited = true;
                printOrder.push_back(hold);
                counter++;
            }
            for (int i = 0; i < printOrder.size(); i++) {
                printOrder[i] -> ID = i + 1;
                cout << "ID: " << printOrder[i] -> ID << " Title: " << printOrder[i] -> title << " Price: $" << printOrder[i] -> price << " Condition: " << printOrder[i] -> quality << endl;
            }
            bool quitPrint = false;

            while (quitPrint != true) {
                cout << "Choose a movie by its ID # to add it to your cart." << endl;
                cout << "Or select 0 to return to the print menu." << endl;
                string IDchoice;
                getline(cin, IDchoice);

                if (IDchoice == "0") {
                    quitPrint = true;
                }
                else {
                    int IDchoice2num = stoi(IDchoice);
                    for (int j = 0; j < printOrder.size(); j++) {
                        if (printOrder[j] -> ID == IDchoice2num)
                            addCart(printOrder[j]);
                    }
                }
            }
            reset();
        }
        /// High - Low
        if (choice == "3") {
            counter = 0;
            while (counter < hashSize) {
                large = INT_MIN;
                for (int i = 0; i < tableSize; i++) {
                    tmp = hashTable[i];
                    while (tmp != NULL) {
                        if (large <= tmp -> price && tmp -> visited == false) {
                            large = tmp -> price;
                            hold = tmp;
                        }
                        tmp = tmp -> next;
                    }
                }
                hold -> visited = true;
                printOrder.push_back(hold);
                counter++;
            }

            for (int i = 0; i < printOrder.size(); i++) {
                printOrder[i] -> ID = i + 1;
                cout << "ID: " << printOrder[i] -> ID << " Price: $" << printOrder[i] -> price << " Title: " << printOrder[i] -> title << " Condition: " << printOrder[i] -> quality << endl;
            }
            bool quitPrint = false;

            while (quitPrint != true) {
                cout << "Choose a movie by its ID # to add it to your cart." << endl;
                cout << "Or select 0 to return to the print menu." << endl;
                string IDchoice;
                getline(cin, IDchoice);

                if (IDchoice == "0") {
                    quitPrint = true;
                }
                else {
                    int IDchoice2num = stoi(IDchoice);
                    for (int j = 0; j < printOrder.size(); j++) {
                        if (printOrder[j] -> ID == IDchoice2num)
                            addCart(printOrder[j]);
                    }
                }
            }
            reset();
        }

        /// Low - High
        if (choice == "4") {
            counter = 0;
            while (counter < hashSize) {
                small = INT_MAX;
                for (int i = 0; i < tableSize; i++) {
                    tmp = hashTable[i];
                    while (tmp != NULL) {
                      //  cout << "hi" << endl;
                        if (small >= tmp -> price && tmp -> visited == false) {
                            small = tmp -> price;
                            hold = tmp;
                        }
                        tmp = tmp -> next;
                    }
                }
                hold -> visited = true;
                printOrder.push_back(hold);
                counter++;
            }

            for (int i = 0; i < printOrder.size(); i++) {
                printOrder[i] -> ID = i + 1;
                cout << "ID: " << printOrder[i] -> ID << " Price: $" << printOrder[i] -> price << " Title: " << printOrder[i] -> title << " Condition: " << printOrder[i] -> quality << endl;
            }

            bool quitPrint = false;

            while (quitPrint != true) {
                cout << "Choose a movie by its ID # to add it to your cart." << endl;
                cout << "Or select 0 to return to the print menu." << endl;
                string IDchoice;
                getline(cin, IDchoice);

                if (IDchoice == "0") {
                    quitPrint = true;
                }
                else {
                    int IDchoice2num = stoi(IDchoice);
                    for (int j = 0; j < printOrder.size(); j++) {
                        if (printOrder[j] -> ID == IDchoice2num)
                            addCart(printOrder[j]);
                    }
                }
            }
            reset();
        }
        if (choice == "5")
            quit = true;
    }
}

void MovieCatalog::findMovie(string title) {
    MovieNode *tmp;
    bool found = false;
    int IDcount = 0;
    string choice;
    vector <MovieNode*> foundMovie;

    for (int i = 0; i < tableSize; i++) {
        tmp = hashTable[i];
        while (tmp != NULL) {
            if (tmp -> title == title) {
                IDcount++;
                tmp -> ID = IDcount;
                cout << "ID: " << tmp -> ID << "  Title: " << tmp -> title << " Price: $" << tmp -> price << " Condition: " << tmp -> quality << endl;
                foundMovie.push_back(tmp);
                found = true;
            }
            tmp = tmp -> next;
        }
    }
    if (found == false) {
        cout << "We currently do not have that movie in stock." << endl;
        return;
    }
    bool quitPrint = false;

    while (quitPrint != true) {
        cout << "Choose a movie by its ID # to add it to your cart." << endl;
        cout << "Or select 0 to return to the main menu." << endl;
        string IDchoice;
        getline(cin, IDchoice);

        if (IDchoice == "0") {
            return;
        }
        else {
            int IDchoice2num = stoi(IDchoice);
            for (int j = 0; j < foundMovie.size(); j++) {
                if (foundMovie[j] -> ID == IDchoice2num)
                    addCart(foundMovie[j]);
            }
        }
    }
}

void MovieCatalog::deleteMovie(string title, int price, string quality ) {
    int index = hashSum(title, tableSize);
    MovieNode *tmp = hashTable[index];
    MovieNode *prev = NULL;

    while (tmp != NULL) {
        if (tmp -> title == title && tmp -> price == price && tmp -> quality == quality) {
            if (prev == NULL) {
                hashTable[index] = tmp -> next;
                delete tmp;
            }
            else {
                prev -> next = tmp -> next;
                tmp -> next -> previous = prev;
                delete tmp;
            }
            return;
        }
        prev = tmp;
        tmp = tmp -> next;
    }
    hashSize--;
    if (hashSize == 0) {
        cout << "All movies have been purchased. Please check in later for an updated inventory!" << endl;
        return;
    }
}

void MovieCatalog::addMovie(string title, int price, string quality) {
    int index = hashSum(title, tableSize);
    MovieNode *movie = new MovieNode(title, price, quality);
    MovieNode *tmp = hashTable[index];
    MovieNode *prev;

    if (tmp == NULL) {
        hashTable[index] = movie;
    }
    else {
        while (tmp != NULL) {
            prev = tmp;
            tmp = tmp -> next;
        }
        prev -> next = movie;
        movie -> previous = prev;
    }
    hashSize++;
}

void MovieCatalog::addCart(MovieNode *add) {
    if (add -> inCart == true) {
        cout << "This item is already in your cart!" << endl;
    }
    else {
        MovieNode *cartMovie = new MovieNode(add -> title, add -> price, add -> quality);
        add -> inCart = true;
        cout << "You have added "<< add -> title << " to your cart!" << endl;
        cout << " " << endl;
        cart.push_back(cartMovie);
    }
}

void MovieCatalog::removeCart(MovieNode *sub) {
    for (int i = 0; i < cart.size(); i++) {
        if (cart[i] -> title == sub -> title && cart[i] -> price == sub -> price && cart[i] -> quality == sub -> quality) {
            cart.erase(cart.begin() + i);
        }
    }
    viewCart();
}

void MovieCatalog::viewCart() {
    int total = 0;

    cout << "___________Your Cart__________" << endl;
    for (int i = 0; i < cart.size(); i++) {
        cart[i] -> ID = i + 1;
        total = total + cart[i] -> price;
        cout << "ID: " << cart[i] -> ID << "  Title: " << cart[i] -> title << " Price: $" << cart[i] -> price << " Condition: " << cart[i] -> quality << endl;
    }
    cout << " " << endl;
    cout << "Cart Total: $" << total << endl;
    cout << "______________________________" << endl;

    bool quit;
    string choice;
    while (quit != true) {
        cout << " " << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Empty cart" << endl;
        cout << "2. Remove movie" << endl;
        cout << "3. Check out" << endl;
        cout << "4. Continue shopping" << endl;

        getline(cin, choice);

        if (choice == "1") {
            if (cart.size() == 0) {
                cout << "Your cart is already empty!" << endl;
            }
            else {
                cout << "Your cart is now empty." << endl;
                emptyCart();
            }
        }
        else if (choice == "2") {
            if (cart.size() == 0) {
                cout << "Your cart is empty, there is nothing to remove" << endl;
            }
            else {
                cout << "Choose the ID # of the movie you would like to remove." << endl;
                string a;
                getline (cin, a);
                int a2n = stoi(a);

                for (int j = 0; j < cart.size(); j++) {
                    if (cart[j] -> ID = a2n)
                        removeCart(cart[j]);
                }
            }
        }
        else if (choice == "3") {
            if (cart.size() == 0) {
                cout << "Your cart is empty, there is nothing to purchase" << endl;
            }
            else {
                cout << "Your total is: $" << total << endl;
                cout << "Thank You for your purchase!" << endl;
                total = 0;

                for (int i = 0; i < cart.size(); i++) {
                    deleteMovie(cart[i] -> title, cart[i] -> price, cart[i] -> quality);
                }
                emptyCart();
                quit = true;
            }
        }
        else if (choice == "4") {
            quit = true;
        }
    }
}

void MovieCatalog::emptyCart() {
    cart.erase(cart.begin(),cart.end());
}

int MovieCatalog::hashSum(string x, int s) {
    int ASCII;
    int sum = 0;
    for (int i = 0; i < x.size(); i++) {
        ASCII = x[i];
        sum = sum + ASCII;
    }
    sum = sum % s;
    return sum; ///index value of the movie
}

void MovieCatalog::reset() {
    MovieNode *tmp;
    for (int i = 0; i < tableSize; i++) {
        tmp = hashTable[i];
        while (tmp != NULL) {
            tmp -> visited = false;
            tmp = tmp -> next;
        }
    }
}
