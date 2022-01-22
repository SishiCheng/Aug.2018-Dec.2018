#include <iostream>
#include <cctype>
using namespace std;

string titleCase(string);
string alterCase(string);
string allCaps(string);
string alphabetOnly(string);
bool yesOrNo();

int main() {
    string input;
    cout << "Enter a string to test:\n";
    getline(cin, input);
    cout << "titleCase: " << titleCase(input) <<endl;
    cout << "alterCase: " << alterCase(input) <<endl;
    cout << "allCaps: " << allCaps(input) << endl;
    cout << "alphabetOnly: " << alphabetOnly(input) <<endl;
    yesOrNo();
}

//Returns a modified version of inputwhere each word startswith an uppercase letter
string titleCase(string input) {
    input[0]=toupper(input[0]);
    for (int i=1; i<input.size(); i++) {
        if (input[i]==' ') {
            input[i+1]=toupper(input[i+1]);
        }
    }
    return input;
}

//Returns a modified version of inputwhichalternates between upper-and lowercase
string alterCase(string input) {
    int i=0;
    while (i<=input.size()) {
        input[i]=toupper(input[i]);
        input[i+1]=tolower(input[i+1]);
        i+=2;
    }
    return input;
}

//Returns a modified version of inputthat capitalizes each letter
string allCaps(string input) {
    for (int i=0; i<=input.size(); i++) {
        input[i]=toupper(input[i]);
    }
    return input;
}

//Returns a modified version of inputthat only contains alphabet letters
string alphabetOnly(string input) {
    bool isalpha1=true;
    for (int i=0; i<input.size(); i++) {
        isalpha1=isalpha(input[i]);
        if (isalpha1==false) {
            input.erase(i,1);
            i--;    
        }
    }
    return input;
}

//Prompts the user fora "yes" or "no" answer, accepting any upper-and lowercasecombination of eachword
////Uses a loop to validate the input
bool yesOrNo() {
    string answer;
    cout << "Enter yes or no: ";
    cin >> answer;
    while (allCaps(answer)!="YES" && allCaps(answer)!="NO") {
        cout << "Invalid input, try again!\n" << "Enter yes or no: ";
        cin >> answer;
    }
    return true;
}

/*
1.
Enter a string to test:
tattoos have to be meaningful
titleCase: Tattoos Have To Be Meaningful
alterCase: TaTtOoS HaVe tO Be mEaNiNgFuL
allCaps: TATTOOS HAVE TO BE MEANINGFUL
alphabetOnly: tattooshavetobemeaningful
Enter yes or no: nO

2.
Enter a string to test:
tattoos have to be meaningful
titleCase: Tattoos Have To Be Meaningful
alterCase: TaTtOoS HaVe tO Be mEaNiNgFuL
allCaps: TATTOOS HAVE TO BE MEANINGFUL
alphabetOnly: tattooshavetobemeaningful
Enter yes or no: y
Invalid input, try again!
Enter yes or no: we
Invalid input, try again!
Enter yes or no: ac
Invalid input, try again!
Enter yes or no: nO

2.
Enter a string to test:
fjkwayfew8 686 #^&*)   Leran
titleCase: Fjkwayfew8 686 #^&*)   Leran
alterCase: FjKwAyFeW8 686 #^&*)   lErAn
allCaps: FJKWAYFEW8 686 #^&*)   LERAN
alphabetOnly: fjkwayfewLeran
Enter yes or no: YeS
*/
