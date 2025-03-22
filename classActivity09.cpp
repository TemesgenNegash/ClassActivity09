// classActivity09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>
using namespace std;
//
struct Customer {
    int id;
    string name;
    string email;
};

struct Date {
    int releaseYear = 0;
    int releaseMonth = 0;
    int releaseDay = 0;

    bool equals(const Date& date) const {
        return releaseYear == date.releaseYear &&
            releaseMonth == date.releaseMonth &&
            releaseDay == date.releaseDay;
    }
};

struct Movie {
    string title;
    struct MoreDetails {
        string genre;
    } details;
    Date rdate;
    bool isPopular = false;

    bool equals(const Movie& otherMovie) const {
        return title == otherMovie.title &&
            details.genre == otherMovie.details.genre &&
            rdate.equals(otherMovie.rdate) &&
            isPopular == otherMovie.isPopular;
    }

    friend ostream& operator<<(ostream& stream, const Movie& movie) {
        stream << "Title: " << movie.title << "\n"
            << "Genre: " << movie.details.genre << "\n"
            << "Release Date: "
            << movie.rdate.releaseYear << "-"
            << movie.rdate.releaseMonth << "-"
            << movie.rdate.releaseDay << "\n"
            << "Popular: "
            << (movie.isPopular ? "Yes" : "No");
        return stream;
    }
};
//error Handling
int validInput(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= min && value <= max) {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error, Plz try again." << endl;
    }
    return value;
}

//function for movie object
Movie createMovie() {
    Movie movie;

    cout << "Enter movie title: ";
    getline(cin, movie.title);

    cout << "Enter movie genre: ";
    getline(cin, movie.details.genre);

    movie.rdate.releaseYear = validInput("Plz enter ther release year 1900-2025: ", 1900, 2025);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer

    movie.rdate.releaseMonth = validInput("Plz enter release month 1-12: ", 1, 12);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    movie.rdate.releaseDay = validInput("Plz enter release day 1-31: ", 1, 31);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    movie.isPopular = validInput("Enter 0 for -> not popular, 1 -> for popular: ", 0, 1) == 1;

    return movie;
}

int main() {
    //movie object using creatMovie()
    Movie myMovie = createMovie();

    //display
    cout << "\nMovie Details:\n" << myMovie << endl;

    //other Movie comparison
    Movie otherMovie;
    otherMovie.title = "Shrek";
    otherMovie.details.genre = "Animation";
    otherMovie.rdate.releaseYear = 2001;
    otherMovie.rdate.releaseMonth = 4;
    otherMovie.rdate.releaseDay = 22;
    otherMovie.isPopular = true;
    cout << "\nComparison Movie:\n" << otherMovie << endl;


    if (myMovie.equals(otherMovie)) {
        cout << "\nThe movies are equal." << endl;
    }
    else {
        cout << "\nThe movies are not equal." << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
