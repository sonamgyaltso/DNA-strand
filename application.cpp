#include <iostream>
#include "dna.h"
#include <map>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // files for small and 1 etc
    string datafile;
    string dnafile;
    ifstream data;
    ifstream dna1;
    cout << "Welcome to the DNA Profiling App!" <<endl;
    cout << "Enter database file: ";
    cin >> datafile;
    data.open(datafile);
    // put those names etc into a vector
    string name;
    string sequence;
    vector<string> names;
    // gets the names
    getline(data, name, ',');
    names.push_back(name);
    // gets the dna sequence
    getline(data, sequence, '\n');
    string word = "";
    map< vector<string> , vector<string> > test_map;
    // break the sequence and put those into maps indiv
    // loop thur each until
    for (auto x : sequence) {
       if (x == ',') {
           test_map[names].push_back(word);
           word = "";
       } else {
           word = word + x;
       }
    }
    test_map[names].push_back(word);
    // this map is for checking the sequence
    map< vector<string> , vector<string> > check;
    vector<string> seq;
    // smame idea as the other one put the names
    // as keys in check and save the number of matches
    // we need
    while (!data.eof()) {
        getline(data, name, ',');
        if (name == "") {
            break;
        }
        seq.push_back(name);
        getline(data, sequence, '\n');
        word = "";
        for (auto y : sequence) {
            if (y == ',') {
                check[seq].push_back(word);
                word = "";
             } else {
                word = word + y;
             }
         }
        check[seq].push_back(word);
        seq.erase(seq.begin());
    }
    // open up the txt with strands
    // put those in a string
    // put the string in a linked lsit
    cout << "Enter dna file: ";
    cin >> dnafile;
    dna1.open(dnafile);
    string temp;
    while (!dna1.eof()) {
        dna1 >> temp;
    }
    dna d(temp);
    dna copy1(temp);
    dna copy(temp);
    string match = "";
    // loop thru the keys
    for ( const auto &p : check ) {
        // looping keys here
        for ( const auto &z : p.first ) {
            // index is gunna tell us how size of mathces
            int index = 0;
            // idk will be the checker basically
            int idk = 0;
             for ( const auto &s : p.second ) {
                 // i loop thru until y becomes false
                 // increment x by how many splcies we did
                bool y = d.splice(test_map[names].at(index));
                int x = 0;
                while (y == true) {
                       y = d.splice(test_map[names].at(index));
                       x++;
                }
                // clear the data and turn d back into
                // original
                d.clear();
                d = copy;
                // indx goes up for next data
                index++;
                // if x is equal to value of the number we needed
                // to match then we increament by 1 for idk
                if (x == stoi(s)) {
                     idk++;
                }
             }
             // now if idk gets incremented to same as index
             // then we know that its a match and set the string match
             // as our key
            if (index == idk) {
                match = z;
            }
        }
    }
    cout << "Searching database..." << endl;
    // this prints out the match
    if (match == "") {
        cout << "No match." << endl;
    } else {
        cout << "DNA match: " << match << endl;
    }
    return 0;
}
