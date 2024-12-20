#include <iostream>
using namespace std;

class Publication
{
protected:
    string name;
    float price;
public:
    Publication()
    {
        name = "";
        price = 0;
    }
    void getdata()
    {
        cout << "The name of the Publication is: " << endl;
        cin >> name;
        cout << "Price of production is" << endl;
        cin >> price;
    }
};

class Book : public Publication{
private:
    string author;
    int page_count;

public:
    Book()
    {
        author = "";
        page_count = 0;
    }
    void getData()
    {
        getdata();
        cout << "Author's name is:"<<endl;
        cin >> author;
        cout << "The number of pages is: " << endl;
        cin >> page_count;
    }
    void display()
    {
        cout << "Book name: " << name << endl;
        cout << "Author name: " << author << endl;
        cout << "Number of pages: " << page_count << endl;
        cout << "Printing cost: " << price << endl;
    }
};

class Tape : public Publication{
private:
    int play_time;
    string prod;

public:
    Tape()
    {
        play_time = 0;
        prod = "";
    }
    void getData()
    {   getdata();
        cout << "The name of the Producer is: " << endl;
        cin >> prod;
        cout << "The play-time in minutes: " << endl;
        cin >> play_time;
    }
    void display()
    {
        cout << "Track name: " << name << endl;
        cout << "Producer name: " << prod << endl;
        cout << "Play-time in minutes: " << play_time << endl;
        cout << "Recording cost: " << price << endl;
    }
};

int main(){
    int n;
    Tape t;
    Book b;
    cout << "Welcome to PRR Publictaion" << endl;
    cout << "Enter n required \n1. Book publishing \n2. Music Publishing"<<endl;;
    cin >> n;
    if (n == 1)
    {
        b.getData();
        cout << endl;
        b.display();
        cout << endl;
    }
    else if (n == 2)
    {
        t.getData();
        cout << endl;
        t.display();
        cout << endl;
    }
    else
    {
        cout << "invalid data\n";
    }
    return 0;
}