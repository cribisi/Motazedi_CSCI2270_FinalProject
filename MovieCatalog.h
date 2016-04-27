#ifndef MOVIECATALOG_H
#define MOVIECATALOG_H
#include <string>
#include <vector>

struct MovieNode{
    std::string title;
    int price;
    int ID;
    std::string quality; //new - used
    bool visited;
    bool inCart;
    MovieNode *previous;
    MovieNode *next;

    MovieNode(){};
    MovieNode(std::string title_in, int price_in, std::string quality_in) {
        ID = 0;
        visited = false;
        inCart = false;
        title = title_in;
        price = price_in;
        quality = quality_in;
        next = NULL;
        previous = NULL;
    }

};

class MovieCatalog
{
    public:
        MovieCatalog();
        ~MovieCatalog();
        void printCatalog(); //print options? by alphabetical, price, condition
        void findMovie(std::string title);
        void deleteMovie(std::string title, int price, std::string quality);
        void emptyCart();
            //choose to buy or rent
        void addMovie(std::string title, int price, std::string quality);
        void addCart(MovieNode *add); //places
        void removeCart(MovieNode *sub);
        void viewCart();
        void reset();
        int hashSum(std::string x, int s);

    private:
        int tableSize = 10;
        MovieNode* hashTable[10];
        int hashSize;
        std::vector <MovieNode*> cart;
};

#endif // MOVIECATALOG_H
