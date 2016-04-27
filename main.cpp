#include <iostream>
#include "MovieCatalog.h"
#include <string>

using namespace std;

int main() {
    bool quit = false;
    string input;
    MovieCatalog catalog;

        catalog.addMovie("Shawshank Redemption", 100, "New");
        catalog.addMovie("Shawshank Redemption", 36, "Used");
        catalog.addMovie("The Godfather", 30, "Used");
        catalog.addMovie("The Godfather", 28, "Used");
        catalog.addMovie("The Godfather: Part II", 48, "Used");
        catalog.addMovie("The Godfather: Part II", 52, "New");
        catalog.addMovie("The Godfather: Part II", 20, "Used");
        catalog.addMovie("The Dark Knight", 12, "Used");
        catalog.addMovie("Pulp Fiction", 40, "New");
        catalog.addMovie("Pulp Fiction", 27, "Used");
        catalog.addMovie("12 Angry Men", 12, "Used");
        catalog.addMovie("Schindler's List", 30, "New");
        catalog.addMovie("The Good the Bad and the Ugly", 16, "Used");
        catalog.addMovie("The Lord of the Rings: The Return of the King", 49, "New");
        catalog.addMovie("Fight Club", 10, "Used");
        catalog.addMovie("Fight Club", 8, "Used");
        catalog.addMovie("The Lord of the Rings: The Fellowship of the Ring", 11, "Used");
        catalog.addMovie("Star Wars: Episode V - The Empire Strikes Back", 28, "New");
        catalog.addMovie("Forrest Gump", 18, "New");
        catalog.addMovie("Forrest Gump", 1, "Used");
        catalog.addMovie("Inception", 90, "Used");
        catalog.addMovie("One Flew Over the Cuckoo's Nest", 19, "Used");
        catalog.addMovie("The Lord of the Rings: The Two Towers", 21, "Used");
        catalog.addMovie("The Lord of the Rings: The Two Towers", 15, "Used");
        catalog.addMovie("Goodfellas", 13, "Used");
        catalog.addMovie("The Matrix", 12, "Used");
        catalog.addMovie("The Matrix", 17, "New");
        catalog.addMovie("The Matrix", 19, "New");
        catalog.addMovie("Star Wars: Episode IV - A New Hope", 8, "New");
        catalog.addMovie("Seven Samurai", 15, "New");
        catalog.addMovie("Interstellar", 48, "New");
        catalog.addMovie("City of God", 89, "New");
        catalog.addMovie("Se7en", 7, "Used");
        catalog.addMovie("The Usual Suspects", 35, "New");
        catalog.addMovie("The Silence of the Lambs", 23, "Used");
        catalog.addMovie("It's a Wonderful Life", 21, "New");
        catalog.addMovie("Once Upon a Time in the West", 4, "Used");
        catalog.addMovie("Leon: The Professional", 7, "Used");
        catalog.addMovie("Life Is Beautiful", 28, "Used");
        catalog.addMovie("Casablanca", 17, "Used");
        catalog.addMovie("Casablanca", 11, "Used");
        catalog.addMovie("Raiders of the Lost Ark", 65, "New");
        catalog.addMovie("American History X", 44, "New");
        catalog.addMovie("Saving Private Ryan", 46, "New");
        catalog.addMovie("Saving Private Ryan", 47, "New");
        catalog.addMovie("City Lights", 78, "Used");
        catalog.addMovie("Back to the Future", 65, "New");
        catalog.addMovie("Dr. Strangelove or: How I Learned to Stop Worrying and Love the Bomb", 25, "New");
        catalog.addMovie("Gladiator", 51, "Used");
        catalog.addMovie("The Untouchables", 59, "Used");
        catalog.addMovie("Modern Times", 67, "New");
        catalog.addMovie("Terminator 2: Judgment Day", 16, "New");
        catalog.addMovie("Memento", 38, "New");
        catalog.addMovie("The Green Mile", 32, "Used");
        catalog.addMovie("The Pianist", 37, "Used");
        catalog.addMovie("The Departed", 34, "New");
        catalog.addMovie("Terminator 2: Judgment Day", 21, "New");
        catalog.addMovie("Memento", 26, "New");
        catalog.addMovie("The Green Mile", 15, "Used");
        catalog.addMovie("The Pianist", 15, "Used");
        catalog.addMovie("The Departed", 15, "New");
        catalog.addMovie("Terminator 2: Judgment Day", 2, "Used");
        catalog.addMovie("Memento", 4, "New");
        catalog.addMovie("The Green Mile", 6, "Used");
        catalog.addMovie("The Pianist", 90, "Used");
        catalog.addMovie("The Departed", 65, "New");
        catalog.addMovie("Apocalypse Now", 34, "New");
        catalog.addMovie("Sunset Blvd.", 21, "New");


    while (quit != true) {

        cout << "======Main Menu======" << endl;
        cout << "1. Search for a Movie" << endl;
        cout << "2. Sell a Movie" << endl;
        cout << "3. Print Catalog" << endl;
        cout << "4. View Shopping Cart" << endl;
        cout << "5. Quit" << endl;

        getline(cin, input);
        //Find title
        if (input == "1") {
            cout << "Enter Title:" << endl;
            string title;
            getline(cin, title);

            catalog.findMovie(title);
        }
        //Sell a movie
        if (input == "2") {
            cout << "What is the name of the movie you would like to sell?" << endl;
            string title;
            getline(cin, title);

            cout << "What is the asking price?" << endl;
            cout << "$";
            string price;
            getline (cin, price);
            int price2num = stoi(price);

            cout << "What is the condition of the movie?" << endl;
            cout << "1. New" << endl;
            cout << "2. Used" << endl;
            string condition;
            getline(cin, condition);

            if(condition == "1")
                condition = "New";
            else if (condition == "2")
                condition = "Used";
            else
                condition = "Unavailable";

            catalog.addMovie(title, price2num, condition);
        }
        //Print catalog
        if (input == "3") {
            catalog.printCatalog();
        }
        //View cart
        if (input == "4") {
            catalog.viewCart();
        }

        if (input == "5") {
            quit = true;
            cout << "Thank you for shopping with us!" << endl;
        }
    }


}
