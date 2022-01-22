#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    //Maintains a parallel vectors named candidates
    vector <string> candidates;
    //Maintains a parallel vectors named votes
    vector <int> votes;
    //Maintains a parallel vectors named percents
    vector <double> percents;
    string name;
    ifstream inputfile;
    //Reads from a text file named candidates.txt
    inputfile.open("candidates.txt");
    if (!inputfile) {
        cout << "not open" <<endl;
    }    
    int min=1500, max=9000;
    srand(time(0));
    while (inputfile >> name) { 
        //populating the candidates vector
        candidates.push_back(name);
        //Populates the votesvector with random numbers between 1500 and 9000, indicating the number of votes for each candidate
        votes.push_back((rand() % (max-min+1)+min));
    }
    float sum=0;
    for (int i=0; i<votes.size(); i++) sum+=votes.at(i);
    //determines and populates the percentsvector with the percentage of the votes for each candidate
    for (int j=0; j<votes.size(); j++) percents.push_back(votes.at(j)/sum);
    //Displays the names, number of votes, and percents for each candidate in a well-formatted table
    cout << "Candidates    " << "Votes        " << "Percent\n";
    for (int z=0; z<votes.size(); z++) cout << setw(13) << left << candidates.at(z) << setw(6) << right << votes.at(z) << setw(14) << right << fixed << setprecision(1) << percents.at(z)*100 << "%" <<endl;
    int maxv=1500;
        string winner;
        double wp;
    //Determineswinning candidate(with a plurality)
    for (int q=0; q<votes.size(); q++) {
        if (votes.at(q)*2>sum) {
            cout << "We can not use plurality in the selection, since someone have has more than half the total number of votes.";
        }
    }
    for (int w=0; w<votes.size(); w++) {
        if (votes.at(w)>maxv) {
            maxv=votes.at(w);
            winner=candidates.at(w);
            wp=percents.at(w);
        }
    }
    //displays the winning candidate(with a plurality),along with the winning number of votesand percentage of total votes
    cout << "\nThe winner is " << winner << "with " << maxv << " votes and " << wp*100 << "% of the votes!";
}
/*
1.
Candidates    Votes        Percent
Johnson        8966          10.6%
Crosby         5290           6.2%
Guffy          6097           7.2%
Mancini        2825           3.3%
Hong           7114           8.4%
Fremont        7728           9.1%
Iglesias       7838           9.2%
Bronski        2803           3.3%
Huffnagle      4335           5.1%
Maata          2194           2.6%
Malkin         1746           2.1%
Polamalu       6908           8.2%
O'Brien        6156           7.3%
Fahd           3702           4.4%
Santini        5744           6.8%
Rodriguez      5290           6.2%

The winner is Johnsonwith 8966 votes and 10.6% of the votes!


2.
Candidates    Votes        Percent
Johnson        4228           4.7%
Crosby         4416           4.9%
Guffy          6499           7.2%
Mancini        7058           7.8%
Hong           7771           8.6%
Fremont        2839           3.1%
Iglesias       5358           5.9%
Bronski        8964           9.9%
Huffnagle      1862           2.1%
Maata          2721           3.0%
Malkin         8595           9.5%
Polamalu       2455           2.7%
O'Brien        7394           8.2%
Fahd           8053           8.9%
Santini        8613           9.5%
Rodriguez      3526           3.9%

The winner is Bronskiwith 8964 votes and 9.9% of the votes!
*/
