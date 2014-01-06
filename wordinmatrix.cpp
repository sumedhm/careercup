/*
*http://www.careercup.com/question?id=6114699053629440
*/

#include <iostream>
using namespace std;

int n;

int check_horizontally(char string[], char matrix[n][], int i, int j){
	int match = 1, k = 0;
	while(j<n && string[k]!='\0'){
		if(matrix[i][j] != string[k]){
			match = 0; j++; k++;
		}
	}
	return match;
}

int check_vertically(char string[], char matrix[][], int i, int j, int n){
        int match = 1, k = 0;
        while(i<n && string[k]!='\0'){
                if(matrix[i][j] != string[k]){
                        match = 0; i++; k++;
                }
        }
        return match;
}

int check_diagonally(char string[], char matrix[][], int i, int j, int n){
        int match = 1, k = 0;
        while(j<n && i<n && string[k]!='\0'){
                if(matrix[i][j] != string[k]){
                        match = 0; i++; j++; k++;
                }
        }
        return match;
}

int checkfor(char string[], char matrix[][], int i, int j, int n){
	return (check_horizontally(string, matrix, i, j) + 
		check_vertically(string, matrix, i, j) + 
		check_diagonally(string, matrix, i, j));
}

int main(){
	int i=0,j=0;
	int occurences=0;
	cout << "\nEnter the value of n: ";
	cin >> n;
	char matrix[n][n];
	cout << "\n\nInput the matrix:\n";
	for(i=0;i<n;i++) for(j=0;j<n;j++) cin >> matrix[i][j];
	char string[n];
	cout << "\n\nInput the string(<=n): ";
	cin >> string; cout<< "\n";
	for(i=0;i<n;i++) for(j=0;j<n;j++) if(string[0]==matrix[i][j]) occurences += checkfor(string, matrix, i, j, n);
	cout << "\n\nNumber of occurences of " << string << "in the matrix are " << occurences << ".\n\n";

	return 0;
}
