#include <iostream>
#include "HashTable.h"
using namespace std;

int main(){

    HashTable h(5);

    // ==============================
    // TEST 1: EMPTY
    // ==============================
    cout << "===== TEST 1: EMPTY =====" << endl;
    h.Show();


    // ==============================
    // TEST 2: DISTRIBUTION
    // ==============================
    cout << "\n===== TEST 2: DISTRIBUTION =====" << endl;

    h.Insert(10);
    h.Insert(11);
    h.Insert(12);
    h.Insert(13);
    h.Insert(14);

    h.Show();


    // ==============================
    // TEST 3: COLLISION
    // ==============================
    cout << "\n===== TEST 3: COLLISION =====" << endl;

    h.Insert(15);
    h.Insert(16);
    h.Insert(17);
    h.Insert(18);
    h.Insert(19);

    h.Show();


    // ==============================
    // TEST 4: HEAVY COLLISION
    // ==============================
    cout << "\n===== TEST 4: HEAVY COLLISION =====" << endl;

    h.Insert(20);
    h.Insert(25);
    h.Insert(30);
    h.Insert(35);

    h.Insert(21);
    h.Insert(26);
    h.Insert(31);

    h.Show();


    // ==============================
    // TEST 5: SEARCH
    // ==============================
    cout << "\n===== TEST 5: SEARCH =====" << endl;

    cout << "Search 10: " << h.Search(10) << endl;
    cout << "Search 25: " << h.Search(25) << endl;
    cout << "Search 35: " << h.Search(35) << endl;

    cout << "Search 99: " << h.Search(99) << endl;
    cout << "Search -10: " << h.Search(-10) << endl;


    // ==============================
    // TEST 6: DUPLICATE
    // ==============================
    cout << "\n===== TEST 6: DUPLICATE =====" << endl;

    h.Insert(25);
    h.Insert(25);
    h.Insert(25);

    h.Show();


    // ==============================
    // TEST 7: REMOVE HEAD
    // ==============================
    cout << "\n===== TEST 7: REMOVE HEAD =====" << endl;

    h.Remove(10);

    h.Show();


    // ==============================
    // TEST 8: REMOVE MIDDLE
    // ==============================
    cout << "\n===== TEST 8: REMOVE MIDDLE =====" << endl;

    h.Remove(25);

    h.Show();


    // ==============================
    // TEST 9: REMOVE TAIL
    // ==============================
    cout << "\n===== TEST 9: REMOVE TAIL =====" << endl;

    h.Remove(35);

    h.Show();


    // ==============================
    // TEST 10: REMOVE DUPLICATES
    // ==============================
    cout << "\n===== TEST 10: REMOVE DUPLICATES =====" << endl;

    h.Remove(25);
    h.Remove(25);
    h.Remove(25);

    h.Show();


    // ==============================
    // TEST 11: REMOVE NON-EXISTING
    // ==============================
    cout << "\n===== TEST 11: REMOVE NON-EXISTING =====" << endl;

    h.Remove(999);

    h.Show();


    // ==============================
    // TEST 12: NEGATIVE VALUES
    // ==============================
    cout << "\n===== TEST 12: NEGATIVE VALUES =====" << endl;

    h.Insert(-1);
    h.Insert(-2);
    h.Insert(-3);
    h.Insert(-4);
    h.Insert(-5);

    h.Show();


    // ==============================
    // TEST 13: SEARCH NEGATIVE
    // ==============================
    cout << "\n===== TEST 13: SEARCH NEGATIVE =====" << endl;

    cout << "Search -1: " << h.Search(-1) << endl;
    cout << "Search -3: " << h.Search(-3) << endl;
    cout << "Search -5: " << h.Search(-5) << endl;
    cout << "Search -10: " << h.Search(-10) << endl;


    // ==============================
    // TEST 14: REMOVE NEGATIVE
    // ==============================
    cout << "\n===== TEST 14: REMOVE NEGATIVE =====" << endl;

    h.Remove(-1);
    h.Remove(-3);
    h.Remove(-5);

    h.Show();


    // ==============================
    // TEST 15: INSERT AFTER REMOVE
    // ==============================
    cout << "\n===== TEST 15: INSERT AFTER REMOVE =====" << endl;

    h.Insert(100);
    h.Insert(101);
    h.Insert(102);
    h.Insert(103);
    h.Insert(104);

    h.Show();


    // ==============================
    // TEST 16: REMOVE EVERYTHING
    // ==============================
    cout << "\n===== TEST 16: REMOVE EVERYTHING =====" << endl;

    int values[] = {
        11, 12, 13, 14,
        15, 16, 17, 18, 19,
        20, 21, 26, 30,
        100, 101, 102, 103, 104,
        -2, -4
    };

    int n = sizeof(values) / sizeof(values[0]);

    for(int i = 0; i < n; i++){
        h.Remove(values[i]);
    }

    h.Show();


    // ==============================
    // TEST 17: REUSE TABLE
    // ==============================
    cout << "\n===== TEST 17: REUSE TABLE =====" << endl;

    h.Insert(1000);
    h.Insert(1001);
    h.Insert(1002);
    h.Insert(1003);
    h.Insert(1004);

    h.Show();

    cout << "\nSearch 1000: " << h.Search(1000) << endl;
    cout << "Search 1004: " << h.Search(1004) << endl;


    return 0;
}