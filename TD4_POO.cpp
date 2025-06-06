#include <iostream>

class MyString {
private:
    char* chaine;
    int n;

public: 

    MyString();                                             // Constructeurs
    MyString(const char* s);
    MyString(int s_n, const char caractere);

    ~MyString();                                            // Destructeur
    MyString(const MyString& autre);                        // Constructeur de copie

    void operator=(const MyString& autre);                  // Surcharge de =
    void operator=(const char* s);

    void affiche();

    void init(const char* s);
    void init(const MyString& autre);

    MyString& maj();
    MyString& min();

    MyString concat(const MyString& autre);
    void concatIn(const MyString& autre);
};

MyString::MyString() : n(0), chaine(nullptr) {}

MyString::MyString(const char* s) {
    n = 0;

    while (s[n] != '\0') {
        n++;
    }

    chaine = new char[n+1];

    for (int i = 0; i < n; i++) {
        chaine[i] = s[i];
    }
    chaine[n] = '\0';
}

MyString::MyString(int s_n, const char caractere) {
    n = s_n;

    chaine = new char[n+1];

    for (int i = 0; i < n; i++) {
        chaine[i] = caractere;
    }

    chaine[n] = '\0';
}

MyString::~MyString() {
    delete[] chaine;
    std::cout << "Destruction du MyString" << std::endl;
}

MyString::MyString(const MyString& autre) {
    n = autre.n;

    chaine = new char[n+1];

    for (int i = 0; i < n; i++) {
        chaine[i] = autre.chaine[i];
    }

    chaine[n] = '\0';
}

void MyString::operator=(const MyString& autre) {
    n = autre.n;
    
    if(chaine != nullptr) { delete[] chaine; }
    chaine = new char[n + 1];

    for (int i = 0; i < n; i++) {
        chaine[i] = autre.chaine[i];
    }

    chaine[n] = '\0';
}

void MyString::operator=(const char* s) {
    n = 0;

    while (s[n] != '\0') {
        n++;
    }

    if(chaine != nullptr) { delete[] chaine; }
    chaine = new char[n + 1];

    for (int i = 0; i < n; i++) {
        chaine[i] = s[i];
    }
    chaine[n] = '\0';
}

void MyString::affiche() {
    if (chaine != nullptr) {
        for (int i = 0; i < n; i++) {
            std::cout << chaine[i];
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "*MyString vide*" << std::endl;
    }
}

void MyString::init(const char* s) {
    n = 0;

    while (s[n] != '\0') {
        n++;
    }
    
    if (chaine != nullptr) {delete[] chaine;}
    chaine = new char[n+1];

    for (int i = 0; i < n; i++) {
        chaine[i] = s[i];
    }
    chaine[n] = '\0';
}

void MyString::init(const MyString& autre) {
    n = 0;

    while (autre.chaine[n] != '\0') {
        n++;
    }

    if (chaine != nullptr) {delete[] chaine;}
    chaine = new char[n + 1];

    for (int i = 0; i < n; i++) {
        chaine[i] = autre.chaine[i];
    }
    chaine[n] = '\0';
}

MyString& MyString::maj() {

    int ascii;
    int i = 0;

    for (int i = 0; i<n; i++) {
        if (97 <= chaine[i] && chaine[i] <= 122) {
            ascii = chaine[i];
            ascii -= 32;
            chaine[i] = ascii;
        }
    }
    return *this;
}

MyString& MyString::min() {

    int ascii;
    int i = 0;

    for (int i = 0; i < n; i++) {
        if (65 <= chaine[i] && chaine[i] <= 90) {
            ascii = chaine[i];
            ascii += 32;
            chaine[i] = ascii;
        }
    }
    return *this;
}

MyString MyString::concat(const MyString& autre) {

    MyString res;
    res.n = (n + autre.n);
    res.chaine = new char[res.n + 1];

    int y = 0;

    for (int i = 0; i < n; i++) {
        res.chaine[i] = chaine[i];
        y++;
    }

    for (int i = 0; i < autre.n; i++) {
        res.chaine[i + y] = autre.chaine[i];
    }

    res.chaine[res.n] = '\0';

    return res;

}

void MyString::concatIn(const MyString& autre) {
    
    MyString res;
    res.n = (n + autre.n);
    res.chaine = new char[res.n + 1];

    int y = 0;

    for (int i = 0; i < n; i++) {
        res.chaine[i] = chaine[i];
        y++;
    }

    for (int i = 0; i < autre.n; i++) {
        res.chaine[i + y] = autre.chaine[i];
    }

    res.chaine[res.n] = '\0';

    *this = res;
}

int main()
{
    MyString s1("Jean");
    MyString s2(" Pierre");
    MyString s3;

    s3 = s1.concat(s2);

    s3.affiche();

    MyString s4("Jo");
    MyString s5("el");

    s4.concatIn(s5);
    s4.affiche();

    MyString s6;
    s6 = "Test";

    s6.affiche();
    return 0;
}
