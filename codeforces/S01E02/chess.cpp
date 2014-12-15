// AC

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

bool isSafe(int i, int j){
	return (i<8 && j<8 && i>=0 && j>=0);
}

void fillKnight(char **mat, int x, int y){
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

	for (int i = 0; i < 8; ++i)
	{
		if(isSafe(x + xMove[i], y+ yMove[i])){
			if(mat[x + xMove[i]][y+ yMove[i]] == '$' || mat[x + xMove[i]][y+ yMove[i]] == '#' ){
				mat[x + xMove[i]][y+ yMove[i]] = '#';
			}
		}
	}
}

void fillKing(char **mat, int x, int y){
	int xMove[8] = {  0, 0, 1, 1, 1, -1,  -1, -1 };
	int yMove[8] = {  -1, 1,  -1,  0, 1, -1, 0, 1 };

	for (int i = 0; i < 8; ++i)
	{
		if(isSafe(x + xMove[i], y+ yMove[i])){
			if(mat[x + xMove[i]][y+ yMove[i]] == '$' || mat[x + xMove[i]][y+ yMove[i]] == '#'){
				mat[x + xMove[i]][y+ yMove[i]] = '#';
			}
		}
	}
}

void fillRook(char **mat, int x, int y){
	for (int i = y-1; i >=0; --i)
	{
		if(mat[x][i] == '$' || mat[x][i] == '#') mat[x][i]='#';
		else break;
	}
	for (int i = y+1; i <8; ++i)
	{
		if(mat[x][i] == '$' || mat[x][i] == '#') mat[x][i]='#';
		else break;
	}

	for (int i = x-1; i >=0; --i)
	{
		if(mat[i][y] == '$' || mat[i][y] == '#') mat[i][y]='#';
		else break;
	}
	for (int i = x+1; i <8; ++i)
	{
		if(mat[i][y] == '$' || mat[i][y] == '#') mat[i][y]='#';
		else break;
	}
}

void fillCamel(char **mat, int x, int y){

	for (int i = 1; i < 8; ++i)
	{
		if(isSafe(x+i,y+i) && (mat[x+i][y+i]=='$' || mat[x+i][y+i]=='#')) {
			mat[x+i][y+i]='#';
		}else{
			break;
		}
	}

	for (int i = 1; i < 8; ++i)
	{
		if(isSafe(x-i,y+i) && (mat[x-i][y+i]=='$' || mat[x-i][y+i]=='#')){ mat[x-i][y+i]='#';;}
		else break;
	}

	for (int i = 1; i < 8; ++i)
	{	

		if(isSafe(x-i,y-i) && (mat[x-i][y-i]=='$' || mat[x-i][y-i]=='#')){
		 mat[x-i][y-i]='#';}
		else break;
	}

	for (int i = 1; i < 8; ++i)
	{
		if(isSafe(x+i,y-i) && (mat[x+i][y-i]=='$' || mat[x+i][y-i]=='#')){ mat[x+i][y-i]='#';}
		else break;
	}
}

void fillqueen(char **mat, int x, int y){
	fillRook(mat,x,y);
	fillCamel(mat,x,y);
}

void fillWPawn(char **mat, int x, int y){
	if(isSafe(x-1,y-1) && mat[x-1][y-1] == '$') mat[x-1][y-1] = '#';
	if(isSafe(x-1,y+1) && mat[x-1][y+1] == '$') mat[x-1][y+1] = '#';
}

void fillBPawn(char **mat, int x, int y){
	if(isSafe(x+1,y-1) && mat[x+1][y-1] == '$') mat[x+1][y-1] = '#';
	if(isSafe(x+1,y+1) && mat[x+1][y+1] == '$') mat[x+1][y+1] = '#';
}
int main(){
	string des;

	while(cin>>des){
		char **mat;
		mat = new char*[8];
		for (int i = 0; i < 8; ++i)
		{
			mat[i] = new char[8];
		}
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				mat[i][j]='$';
			}
		}
		int i=0; int j=0;
		for (int z = 0; z < des.length(); ++z)
		{
			if(isalpha(des[z])){
				mat[i][j] = des[z];
				j++;
			}else if(isdigit(des[z])){
				j = j+ des[z] - '0';
				
			}else{
				j=0;
				i++;
			}
		}

		/*for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				cout<<mat[i][j]<<" ";
				// if(mat[i][j] =='$') ans++;
			}
			cout<<endl;
		}
		cout<<endl<<endl;*/
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if(mat[i][j] == 'q' || mat[i][j] == 'Q') fillqueen(mat,i,j);
				else if(mat[i][j] == 'r' || mat[i][j] == 'R') fillRook(mat,i,j);
				else if(mat[i][j] == 'b' || mat[i][j] == 'B') fillCamel(mat,i,j);
				else if(mat[i][j] == 'k' || mat[i][j] == 'K') fillKing(mat,i,j);
				else if(mat[i][j] == 'n' || mat[i][j] == 'N') fillKnight(mat,i,j);
				else if(mat[i][j] == 'p') fillBPawn(mat,i,j);
				else if(mat[i][j] == 'P') fillWPawn(mat,i,j);
			}
		}
		// cout<<endl<<endl;
		int ans=0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				// cout<<mat[i][j]<<" ";
				if(mat[i][j] =='$') ans++;
			}
			// cout<<endl;
		}
		

		cout<<ans<<endl;
	}
}