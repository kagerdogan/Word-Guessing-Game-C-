// Muhammed Kaðan Erdoðan 
// Word Guessing Game C++ Code
// 10.5.2020
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<set>
#include<time.h>
using namespace std;
char filename[30];
string xxxxx;
string A[2415];
	class Dictionary {
	private:
		set<string>words;
		vector<string>secrets;
		vector<string>v_words;
		int k = 0;
		bool TestLegalSecretWord(string word)
		{
			for (int f = 0; f < v_words.size(); f++)
			{
				char *cword = &word[0];
				int count = 0;
				for (int i = 0; i < word.length(); i++)
				{
					for (int j = i+1; j <word.length(); j++)
					{
						if (word[i] == word[j])
						{
							count++;
						}
					}
				}
				if (count==0)
				{
					secrets.push_back(word);
				}
			}
			return 1;
		}
	public:
		Dictionary() {}

		Dictionary(char *filename)
		{
			fstream dataFile;
			string tmp;
			dataFile.open(filename, std::fstream::in);
			if (!dataFile)
			{
				cout << "File open error!" << endl;
				exit(0);
			}
			else
			{
				cout << "File opened successfully!" << endl;

				dataFile >> tmp;
				while (!dataFile.eof())
				{
					words.insert(tmp);
					dataFile >> tmp;
				}
				v_words.assign(words.begin(), words.end());
				for (int i = 0; i < v_words.size(); i++)
				{
					A[i] = v_words[i];
				}
				for (int f = 0; f < v_words.size(); f++)
				{
					string check;
					check = A[f];
					char *cword = &check[0];
					int count = 0;
					for (int i = 0; i < check.length(); i++)
					{
						for (int j = i + 1; j <check.length(); j++)
						{
							if (check[i] == check[j])
							{
								count++;
							}
						}
					}
					if (count == 0)
					{
						secrets.push_back(check);
					}
				}
				return ;
			}
		}
		string BringValidWord()
		{
			string word;
			srand(time(NULL));
			int i = rand() % secrets.size() + 1;
			word = secrets[i];
			//cout << word;
			
			return word;
		}
		bool IsWordValid(string W)
		{
			
			int counter = 0;
			//cin >> W;
			for (int i = 0; i < v_words.size(); i++)
			{
				if (W == v_words[i])
				{
					counter++;
				}
			}
			if (counter==0)
			{
				cout << "This word not in the Dictionary" << endl;
				
			}
			return counter;
		}
	};
	class Words 
	{
	public:
		Words() {};
		~Words() {};		 
		void playgame(string W)
		{
			Dictionary*p = new Dictionary(filename);
			secret = p->BringValidWord();
			cout << endl << endl;
			cout << "Bilbakalim Oyununa Hosgeldiniz:" << endl;
			cout << "5 harften oluþan bir kelime tuttum." << endl;
			
			while (W!=secret)
			{
				cout << "Tahmininiz Nedir? " << "\t";
				cin >> W;
				p->IsWordValid(W);
				if (W == secret)
				{
					cout << "Tebrikler " << quesscount << " .Tahminde buldunuz." << endl;
				}
				else if (W == "xxxxx")
				{
					cout << "Gizli Kelime " << secret << endl;
				}
				else if (W!=secret)
				{
					countofMatchLetters(W, secret);
					countofTruePlaceLetters(W, secret);
				}
				else
				{

				}
				numguesses();
			}
		}

	private:
	
		int countofMatchLetters(string W,string secret)
		{
			char *TW = &secret[0];
			char *CW = &W[0];
			int counter = 0;
			
			for (int i = 0; i < W.length(); i++)
			{
				for (int j = 0; j < W.length(); j++)
				{
					if (W[i] == secret[j])
					{
						counter++;
					}
				}
			}
			
			cout << "Eslesen Harf Sayisi : " << counter << endl;
			return 1;
		}
		// find common letters in place
		int countofTruePlaceLetters(string W,string secret)
		{
			char *TW = &secret[0];
			char *CW = &W[0];
			int counter2 = 0;
			for (int i = 0; i < W.length(); i++)
			{
				if (W[i] == secret[i])
				{
					counter2++;
				}
			}
			cout << "Eslesen Harflerin Dogru Konumu : " << counter2 << endl;
			return counter2;
		}
		
		int numguesses()
		{
			quesscount++;	
			return quesscount;
		}
		bool cheated()
		{
			
		}
		string secret;
		int quesscount = 1;
	};
	int main()
	{
	string W;
	cout << "Enter file name to open:" << endl;
	cin >> filename;
	Words *k = new Words();
	k->playgame(W);
	
	system("pause");
}
