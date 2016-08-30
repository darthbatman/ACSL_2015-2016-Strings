#include <iostream>
#include <string>
using namespace std;

string char_split(string a, int n, char c) {
	string newString = "";
	for (int i = 0; i < a.length(); i++) {
		newString += a[i];
		if ((i + 1) % n == 0) {
			newString += c;
		}
	}
	return newString;
}

string strrem(string a, string b) {
	while (a.find(b) >= 0 && a.find(b) < 100) {
		int beginning = a.find(b);
		a.erase(beginning, (b.length()));
	}
	return a;
}

string str_chr(string a, string b) {
	string newString = "";
	int firstOccurence = a.find(b);
	for (int i = 0; i < firstOccurence; i++) {
		newString += a[i];
	}
	return newString;
}

string str_tok(string a, char b) {
	string newString = "";
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == b) {
			newString += " ";
		}
		newString += a[i];
	}
	return newString;
}

string wordwrap(string a, int n, char c) {
	string newString = "";
	int nCounter = 2;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == c) {
			newString += " ";
			nCounter = 2;
		}
		else if (nCounter == 0) {
			newString += " ";
			nCounter = 2;
		}
		newString += a[i];
		nCounter--;
	}
	return newString;
}

int main() {

	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			string inputString;

			string splitString = "";
			int numChars;
			string numCharString;
			char specialChar;

			int numStartIndex;

			getline(cin, inputString);
			for (int j = 0; j < inputString.length(); j++) {
				splitString += inputString[j];
				if (inputString[j + 1] == ',') {
					numStartIndex = j + 3;
					break;
				}
			}
			for (int j = numStartIndex; j < inputString.length(); j++) {
				numCharString += inputString[j];
				if (inputString[j + 1] == ',') {
					specialChar = inputString[j + 3];
					break;
				}
			}
			numChars = stoi(numCharString);
			cout << char_split(splitString, numChars, specialChar) << endl;
		}
		if (i == 1) {
			string inputString;
			
			string originalString = "";
			string removeString = "";

			int rmStrStartIndex;
			
			getline(cin, inputString);
			for (int j = 0; j < inputString.length(); j++) {
				originalString += inputString[j];
				if (inputString[j + 1] == ','){
					rmStrStartIndex = j + 3;
					break;
				}
			}
			for (int j = rmStrStartIndex; j < inputString.length(); j++) {
				removeString += inputString[j];
			}
			cout << strrem(originalString, removeString) << endl;
		}
		if (i == 2) {
			string inputString;

			string originalString = "";
			string occString = "";

			int rmStrStartIndex;

			getline(cin, inputString);
			for (int j = 0; j < inputString.length(); j++) {
				originalString += inputString[j];
				if (inputString[j + 1] == ',') {
					rmStrStartIndex = j + 3;
					break;
				}
			}
			for (int j = rmStrStartIndex; j < inputString.length(); j++) {
				occString += inputString[j];
			}
			cout << str_chr(originalString, occString) << endl;
		}
		if (i == 3) {
			string inputString;

			string originalString = "";
			char tok;

			int rmStrStartIndex;

			getline(cin, inputString);
			for (int j = 0; j < inputString.length(); j++) {
				originalString += inputString[j];
				if (inputString[j + 1] == ',') {
					rmStrStartIndex = j + 3;
					break;
				}
			}
			for (int j = rmStrStartIndex; j < inputString.length(); j++) {
				tok = inputString[j];
			}
			cout << str_tok(originalString, tok) << endl;
		}
		if (i == 4) {
			string inputString;

			string splitString = "";
			int numChars;
			string numCharString;
			char specialChar;

			int numStartIndex;

			getline(cin, inputString);
			for (int j = 0; j < inputString.length(); j++) {
				splitString += inputString[j];
				if (inputString[j + 1] == ',') {
					numStartIndex = j + 3;
					break;
				}
			}
			for (int j = numStartIndex; j < inputString.length(); j++) {
				numCharString += inputString[j];
				if (inputString[j + 1] == ',') {
					specialChar = inputString[j + 3];
					break;
				}
			}
			numChars = stoi(numCharString);
			cout << wordwrap(splitString, numChars, specialChar) << endl;
		}
	}

	return 0;
}