#include <iostream>
#include <vector>
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
    ofstream outputfile;
    outputfile.open("candidates_result.txt");
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
    outputfile << "Candidates    " << "Votes        " << "Percent\n";
    for (int z=0; z<votes.size(); z++) {
        cout << setw(13) << left << candidates.at(z) << setw(6) << right << votes.at(z) << setw(14) << right << fixed << setprecision(1) << percents.at(z)*100 << "%" <<endl;
        outputfile << setw(13) << left << candidates.at(z) << setw(6) << right << votes.at(z) << setw(14) << right << fixed << setprecision(1) << percents.at(z)*100 << "%" <<endl;
    }
    int maxv=1500;
    string winner;
    double wp;
    for (int q=0; q<votes.size(); q++) {
        if (votes.at(q)>maxv) {
            maxv=votes.at(q);
            winner=candidates.at(q);
            wp=percents.at(q);
        }
    }
    //If a majority is reached, end the election immediately
    if (maxv*2>sum) {
        cout << "\nThe winner is " << winner << "with " << maxv << " votes and " << wp*100 << "% of the votes!";
        outputfile << "\nThe winner is " << winner << "with " << maxv << " votes and " << wp*100 << "% of the votes!";
        return 0;
    }
    //Repeat as many times as necessary until a majority is reached
    while (true) {
        string x;
        int swapv;
        maxv=1500;
        //If a majority is not reached, then rank the candidates based on the number of votes and remove lowest half
        for (int i=0; i<votes.size()-1;i++) {
            for (int j=i+1; j<votes.size(); j++) {
                if (votes.at(i)<votes.at(j)) {
                    x=candidates.at(i);
                    candidates.at(i)=candidates.at(j);
                    candidates.at(j)=x;
                    swapv=votes.at(i);
                    votes.at(i)=votes.at(j);
                    votes.at(j)=swapv;
                }
            }
        }
        votes.clear();
        percents.clear();
        //remove lowest half
        candidates.resize(candidates.size()/2);
        cout << "\nNo majority... eliminating half the lowvote candidates\n" << "Runoff election\n\n";
        outputfile << "\nNo majority... eliminating half the lowvote candidates\n" << "Runoff election\n\n";
        for (int e=0; e<candidates.size(); e++) votes.push_back((rand() % (max-min+1)+min));
        sum=0;
        for (int i=0; i<votes.size(); i++) sum+=votes.at(i);
        //determines and populates the percentsvector with the percentage of the votes for each candidate
        for (int j=0; j<votes.size(); j++) percents.push_back(votes.at(j)/sum);
        //Displays the names, number of votes, and percents for each candidate in a well-formatted table
        cout << "Candidates    " << "Votes        " << "Percent\n";
        outputfile << "Candidates    " << "Votes        " << "Percent\n";
        for (int z=0; z<votes.size(); z++) {
            outputfile << setw(13) << left << candidates.at(z) << setw(6) << right << votes.at(z) << setw(14) << right << fixed << setprecision(1) << percents.at(z)*100 << "%" <<endl;
            cout << setw(13) << left << candidates.at(z) << setw(6) << right << votes.at(z) << setw(14) << right << fixed << setprecision(1) << percents.at(z)*100 << "%" <<endl;
        }
        for (int w=0; w<votes.size(); w++) {
            if (votes.at(w)>maxv) {
                maxv=votes.at(w);
                winner=candidates.at(w);
                wp=percents.at(w);
            }
        }
        if (maxv*2>sum) break;
    }
    
    cout << "\nThe winner is " << winner << " with " << maxv << " votes and " << wp*100 << "% of the votes!";
    outputfile << "\nThe winner is " << winner << " with " << maxv << " votes and " << wp*100 << "% of the votes!";
    //displays the winning candidate(with a majority),along with the winning number of votesand percentage of total votes
    outputfile.close();
}
/*
1.
Candidates    Votes        Percent
Johnson        2344           3.1%
Crosby         1569           2.1%
Guffy          2056           2.7%
Mancini        5028           6.6%
Hong           3481           4.6%
Fremont        8770          11.6%
Iglesias       8998          11.9%
Bronski        6609           8.7%
Huffnagle      4881           6.4%
Maata          5420           7.2%
Malkin         4182           5.5%
Polamalu       6687           8.8%
O'Brien        2596           3.4%
Fahd           5024           6.6%
Santini        4949           6.5%
Rodriguez      3088           4.1%

No majority... eliminating half the lowvote candidates
Runoff election

Candidates    Votes        Percent
Iglesias       3634           9.0%
Fremont        3674           9.1%
Polamalu       3065           7.6%
Bronski        4639          11.5%
Maata          5009          12.4%
Mancini        7837          19.5%
Fahd           7438          18.5%
Santini        4963          12.3%

No majority... eliminating half the lowvote candidates
Runoff election

Candidates    Votes        Percent
Mancini        4358          20.7%
Fahd           6723          32.0%
Maata          6458          30.7%
Santini        3492          16.6%

No majority... eliminating half the lowvote candidates
Runoff election

Candidates    Votes        Percent
Fahd           2781          27.5%
Maata          7315          72.5%

The winner is Maata with 7315 votes and 72.5% of the votes!

2.
Candidates    Votes        Percent
Johnson        4211           4.5%
Crosby         7287           7.8%
Guffy          7777           8.3%
Mancini        7572           8.1%
Hong           6922           7.4%
Fremont        8735           9.4%
Iglesias       6444           6.9%
Bronski        6806           7.3%
Huffnagle      4561           4.9%
Maata          2524           2.7%
Malkin         6036           6.5%
Polamalu       1928           2.1%
O'Brien        7806           8.4%
Fahd           6382           6.8%
Santini        5595           6.0%
Rodriguez      2615           2.8%

No majority... eliminating half the lowvote candidates
Runoff election

Candidates    Votes        Percent
Fremont        8989          20.9%
O'Brien        4488          10.4%
Guffy          4412          10.3%
Mancini        5436          12.6%
Crosby         2074           4.8%
Hong           7034          16.4%
Bronski        1968           4.6%
Iglesias       8614          20.0%

No majority... eliminating half the lowvote candidates
Runoff election

Candidates    Votes        Percent
Fremont        5495          26.0%
Iglesias       6927          32.8%
Hong           5032          23.8%
Mancini        3687          17.4%

No majority... eliminating half the lowvote candidates
Runoff election

Candidates    Votes        Percent
Iglesias       7866          54.5%
Fremont        6579          45.5%

The winner is Iglesias with 7866 votes and 54.5% of the votes!
*/