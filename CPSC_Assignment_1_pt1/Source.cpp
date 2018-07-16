//Author: Victor G. Balcazar
//Title: CPSC335 - Assignment 1
//Contact info: victorbalcazar3@hotmail.com
//Compiler Used: Visual Studio 2015
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
/*While working out the problem in paper I noticed that there was a certain behavior that repeated every time I spwapped the disks.
After the first round of swapping, n swaps occured. In the subsequent step there were n - 1 swaps, and in the next there were n - 2
swaps, and so on and so on. So I wrote this simple function to do the operation. I realize I could just have made a counter and increased it
every time a swap was performed, but I figured I'd put it in here anyways.
INPUT: a positive integer. The n number of single colored disks
OUTPUT: a positive integer. The num of swaps performed by the operation*/
int numOfSwaps(int npar);
//This prints the output to a text file called CPSC335-A1.txt 
//INPUT: listpar = temporary string to hold the disk list before being modified. listpar2 = string that holds the modified disk list.
//npar = the number of single colored disks.
//OUTPUT: While the function returns void, it outputs the program output to a text file.
void printToFile(string listpar, string listpar2, int npar);
int main() {
	int n = 2;
	int shit = 0;
	int tmp_i = 0; //this one int is used to handle an odd number being int divided by 2, which rounds down.
	string listOfDisks = "";
	string tmp_s = "";
	char temp;
	char temp2;

	//cout << numOfSwaps(n) << endl;

	//output the first instructions and greetings 
	cout << "CPSC 335 - Programming assignment #1: \n";
	cout << "The alternating disks problem: Lawnmower algorithm \n" << "Enter the number of single colored disks (light or dark): \n";
	cin >> n;
	//populate the string listOfDisks
	for (int i = 0; i < n; i++) {
		listOfDisks += "dl";
	}

	//this is done to prevent errors when outputting to file
	tmp_s = listOfDisks;

	cout << "Initial configuration\nList of Disks\n" << listOfDisks << endl;
	cout << "After moving the dark disks to the right \n";

	//here is the handling of an odd integer being int divided by 2

	if (n % 2 == 1) {
		tmp_i = (n / 2) + 1;
	}
	else {
		tmp_i = n;
	}


	//Code for Lawnmower algorithm
		for (int i = 0; i < (tmp_i); i++) {
			for (int k = 0; k < (2 * n); k++) {
				if (listOfDisks[k] == 'd' && listOfDisks[k + 1] == 'l' && k < (2 * n) - 1) {
					temp = listOfDisks[k];
					temp2 = listOfDisks[k + 1];
					listOfDisks[k] = temp2;
					listOfDisks[k + 1] = temp;
				}
			}
			for (int j = ((2 * n) - 1); j > 0; j--) {
				if (listOfDisks[j] == 'l' && listOfDisks[j - 1] == 'd' && j > 0) {
					temp = listOfDisks[j];
					temp2 = listOfDisks[j - 1];
					listOfDisks[j] = temp2;
					listOfDisks[j - 1] = temp;
				}
			}
		}
	//END OF LAWNMOVER ALGORITHM
	cout << "List of Disks\n" << listOfDisks << endl;
	cout << "Number of Swaps is " << numOfSwaps(n) << endl;

	//print everything to file
	printToFile(tmp_s, listOfDisks, n);

	system("pause");
	return 0;
}

int numOfSwaps(int npar) {
	int temp_n = npar;
	int numOfSwaps = 0;
	for (int i = 1; i <= npar; i++) {
		numOfSwaps += i;
	}
	return numOfSwaps;
}

void printToFile(string listpar, string listpar2, int npar) {
	ofstream file_;
	file_.open("CPSC335-A1-Lwnmr.txt");

	file_ << "CPSC 335 - Programming assignment #1: \n";
	file_ << "The alternating disks problem: Lawnmower algorithm \n" << "Enter the number of single colored disks (light or dark): \n";
	file_ << npar << endl;

	file_ << "Initial configuration\nList of Disks\n" << listpar << endl;
	file_ << "After moving the dark disks to the right \n";

	file_ << "List of Disks\n" << listpar2 << endl;
	file_ << "Number of Swaps is " << numOfSwaps(npar) << endl;

	file_.close();
}