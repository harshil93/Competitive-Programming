#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class SpamDetector
{
public:
	int countKeywords(string s,vector<string> keywords){
		std::vector<string> words;
		size_t cur_pos=0;
		size_t find_pos=0;
		while((find_pos = s.find(" ",cur_pos)) !=  string::npos){
			words.push_back(s.substr(cur_pos,find_pos-cur_pos));
			cur_pos = find_pos +1;
		}
		words.push_back(s.substr(cur_pos));
		for (int i = 0; i < words.size(); ++i)
		{
			std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
		}

		for (int i = 0; i < keywords.size(); ++i)
		{
			std::transform(keywords[i].begin(), keywords[i].end(), keywords[i].begin(), ::tolower);
		}
		int count=0;char cur_char;
		for (int i = 0; i < words.size(); ++i)
		{
			int z=0;
				for (int k = 0; k < keywords.size(); ++k)
				{
					z=0;
					bool matched = true;
					for (int l = 0; l < keywords[k].size() ; ++l)
					{
						cur_char = words[i][z];
						// PR(words[i][z]);
						if(words[i][z]==keywords[k][l]){
							if(l!= keywords[k].size()-1 && keywords[k][l] == keywords[k][l+1]){
								if(z != words[i].size() && words[i][z+1] == keywords[k][l+1]){
									l++;
									while(words[i][z] == words[i][z]){
										z++;
									}
									if(z>=words[i].size())
											break;
								}else{
									matched = false;
									break;
								}
							}else{
								// PR(z)
								while(cur_char == words[i][z]){
										z++;
									}
									if(z>=words[i].size())
											break;
							}
						}else{
							matched = false;
							break;
						}
					}
					if(matched){
						count++;
						break;
					}
				}
			
		}
		return count;
	}


};

int main(){
	SpamDetector S;
	string s = "LoooW INTEREST RATES available dont BE slow";
	std::vector<string> keywords;
	string keywords_arr[] ={"interest","rates","loan","available","LOW"};
	for (int i = 0; i < 5; ++i)
	{
		keywords.push_back(keywords_arr[i]);
	}

	S.countKeywords(s,keywords);
}