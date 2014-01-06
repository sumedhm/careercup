/*
*http://www.careercup.com/question?id=6114699053629440
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int n;

int check_horizontally(char string[], char **matrix, int i, int j){
	int match = 0, k = 0;
	//cout << "\nChecking horizontally @ " << i << "," << j << ", found : ";
	while(j<n){
		if(matrix[i][j] != string[k]){
			match = 0; break;
		}
		j++; k++;
		if(string[k]=='\0'){
			match = 1; break;
		}
	}
	//cout << match <".\n";
	return match;
}

int check_vertically(char string[], char **matrix, int i, int j){
        int match = 0, k = 0;
	//cout << "\nChecking vertically @ " << i << "," << j << ", found : ";
        while(i<n){
                if(matrix[i][j] != string[k]){
                        match = 0; break;
                }
		i++; k++;
		if(string[k]=='\0'){
                        match = 1; break;
                }
        }
	//cout << match <".\n";
        return match;
}

int check_diagonally(char string[], char **matrix, int i, int j){
        int match = 0, k = 0;
	//cout << "\nChecking diagonally @ " << i << "," << j << ", found : ";
        while(j<n && i<n){
                if(matrix[i][j] != string[k]){
                        match = 0; break;
                }
		i++; j++; k++;
		if(string[k]=='\0'){
                        match = 1; break;
                }
        }
	//cout << match <".\n";
        return match;
}

int checkfor(char string[], char **matrix, int i, int j){
	return (check_horizontally(string, matrix, i, j) + 
		check_vertically(string, matrix, i, j) + 
		check_diagonally(string, matrix, i, j));
}

int main(){
	int i=0,j=0;
	int occurences=0;
	cout << "\nEnter the value of n: ";
	cin >> n;
	char **matrix;
	cout << "\n\nInput the matrix:\n";
	matrix = (char **) malloc (sizeof(char *) * i);
	for(i=0;i<n;i++){
		matrix[i] = (char *) malloc (sizeof(char) * j);
		for(j=0;j<n;j++) cin >> matrix[i][j];
	}
	char string[n];
	cout << "\n\nInput the string(<=n): ";
	cin >> string; cout<< "\n";
	for(i=0;i<n;i++) for(j=0;j<n;j++) if(string[0]==matrix[i][j]) occurences += checkfor(string, matrix, i, j);
	cout << "\n\nNumber of occurences of " << string << " in the matrix are " << occurences << ".\n\n";

	return 0;
	free(matrix);
}
