#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Game
{
private:
	int Computer_score = 0;
	int User_score = 0;

public:

	Game();
	///Global Vectors one for dictionary and one for if the word is used then pushback
	vector<string>Dictionary = { "car","road","pot","right","wrong","tremble","elephant","light","trouble","trum","acrobat","drum","drought","word"
	,"use","zebra","react","rode","might","melow","eight","read","ear","seven","river","drums","pot","parrot","person","mumble","crumble"};
	vector<string>word_used;
	
	vector<string>Dictionary1;

	bool if_found_in_dictionary(string str);
	bool if_word_is_used(string str);
	bool word_found(string str);
	void throw_word(string str);


	bool if_found_in_dictionary1(string str);
	bool word_found1(string str);
	void throw_word1(string str);

	void set_user_score(int user_score)
	{
		User_score = User_score+user_score;
	}
	void set_computer_score(int computer_score)
	{
		Computer_score = Computer_score+computer_score;
	}
	void deduce_user_score(int deduced_user_score)
	{
		User_score =User_score- deduced_user_score;
	}

	///Display Functions for Scores only
	int display_user_score()
	{
		return User_score;
	}
	int display_computer_score()
	{
		return Computer_score;
	}
	/*void display_user_score(int deduced_user_score)
	{
		cout<<User_score;
	}*/
};

/// <summary>
/// Constructor use to store the word from file to a vector
/// </summary>
Game::Game()
{
	fstream myfile;
	myfile.open("Dictionary1.txt");
	string random;

	while (getline(myfile, random))
	{
		Dictionary1.push_back(random);
	}

	cout << "\t\t\t\tAll Words Loaded" << endl;
}

/// <summary>
/// Returns true if the word is found inside the dictionary
/// Must be used for the user purpose. 
/// The success of this fucntion depends when the fucntion returns true..
/// </summary>
/// <returns></returns>
bool Game:: if_found_in_dictionary(string str)
{
	//For custom Dictionary
	vector<string>::iterator l_iterator;

	//for Computer Dictionary
	vector<string>::iterator l_iterator2;

	l_iterator = find(Dictionary.begin(), Dictionary.end(), str);

	if (l_iterator != Dictionary.end())
		return true;

	return false;
}

bool Game::if_found_in_dictionary1(string str)
{
	//For custom Dictionary
	vector<string>::iterator l_iterator;

	l_iterator = find(Dictionary1.begin(), Dictionary1.end(), str);

	if (l_iterator != Dictionary1.end())
		return true;

	return false;
}

/// <summary>
/// 
/// This fucntion check if the words which are input have been used previosuly or not
/// The success of this fucntion depends on when it returns a false value.
/// 
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
bool Game::if_word_is_used(string str)
{
	vector<string>::iterator l_iterator;

	l_iterator = find(word_used.begin(), word_used.end(), str);

	if (l_iterator != word_used.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}






/// <summary>
/// This fucntion is used to check if a word which stars with the last letter of previous word exists or not
/// if the word exists then the fucntion will return true.
/// </summary>
/// <param name="string str"></param>
/// <returns></returns>
bool Game::word_found(string str)
{
	bool count = false;
	
	for (int i = 0; i < Dictionary.size(); i++)
	{	
		if (str.back() == Dictionary[i].front() && count == false)
		{
			bool m_temp = if_word_is_used(Dictionary[i]);

			if (m_temp == false)
			{
				return true;
				count = true;
			}	
		}
	}
}

bool Game::word_found1(string str)
{
	bool count = false;

	for (int i = 0; i < Dictionary1.size(); i++)
	{
		if (str.back() == Dictionary1[i].front() && count == false)
		{
			bool m_temp = if_word_is_used(Dictionary1[i]);

			if (m_temp == false)
			{
				return true;
				count = true;
			}
		}
	}
}





/// <summary>
/// 
/// This Function is the replica of the function called "word_found()"
/// This function uses the same statement but returns nothing.
/// The output fucntion inside the fucntion throws a meaning full word from the dictionary vector.
/// This fucntion throws a word.
/// 
/// </summary>
/// <param name="string str"></param>
void Game::throw_word(string str)
{
	bool count = false;

	for (int i = 0; i < Dictionary.size(); i++)
	{

		if (str.back() == Dictionary[i].front() && count == false)
		{
			bool m_temp = if_word_is_used(Dictionary[i]);
			if (m_temp == false)
			{
				count = true;
				cout << "\t The Word Thrown by the Computer is : " << Dictionary[i] << endl;
				cout << "\t-----------------------------------------------------------------------------------------------------" << endl;
				cout << "\t-----------------------------------------------------------------------------------------------------" << endl;
				word_used.push_back(Dictionary[i]);
			}
		}
	}
}

void Game::throw_word1(string str)
{
	bool count = false;

	for (int i = 0; i < Dictionary1.size(); i++)
	{

		if (str.back() == Dictionary1[i].front() && count == false)
		{
			bool m_temp = if_word_is_used(Dictionary1[i]);
			if (m_temp == false)
			{
				count = true;
				cout << "\t The Word Thrown by the Computer is : " << Dictionary1[i] << endl;
				cout << "\t-----------------------------------------------------------------------------------------------------" << endl;
				cout << "\t-----------------------------------------------------------------------------------------------------" << endl;
				word_used.push_back(Dictionary1[i]);
			}
		}
	}
}

void play_with_Computer_dictionary()
{

	///Use with custom dictionary.
	int rounds = 10000;
	Game gameobject;

	cout << "\t\t\t WORD-TAKSHRI GAME (Version 2.0)" << endl;
	cout << "\t\t\t---------------------------------" << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t     Rules of the game are : " << endl;
	cout << "\t\t\t---------------------------------" << endl;

	cout << "       Rules : " << endl;
	cout << endl;
	cout << "    1. There will be infinte Rounds in the game until the words finish from the dictionary." << endl;
	cout << "    2. You will be asked to throw a word." << endl;
	cout << "    3. If your word is from the Dictionary then computer throws a word." << endl;
	cout << "    4. The word should start from the last letter of the word thrown by the Computer." << endl;
	cout << "		4.a The above part only applies after the very first attempt." << endl;
	cout << "    5. On every successfull word you gain 10 points and on every retry you loose 2 points." << endl;
	cout << "    6. If computer fails to find a word then you win otherwise at the end of the game the person with highest score wins." << endl;
	cout << "    7. Later parts of the game will contain more dictionary words." << endl;

	cout << endl;
	cout << endl;


	int c_count = 1;
	while (rounds--)
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "                                 |  Round Number : " << c_count << "  |" << endl;
		cout << "	\t\t\t   ------------------" << endl;
		cout << "																									Your Score : " << gameobject.display_user_score() << endl;
		cout << "																									Computer Score : " << gameobject.display_computer_score() << endl;
		cout << "\t-----------------------------------------------------------------------------------------------------" << endl;

		string temporary;
		int user_score = 0;
		int pc_score = 0;

		cout << "\tIt's Your chance : " << endl;
		cout << "\tChoose a word : " << endl;


		cin >> temporary;
		bool a = gameobject.if_found_in_dictionary1(temporary);
		bool b = gameobject.if_word_is_used(temporary);

		if (a == true && b == false)
		{
			/// <summary>
			/// adds the thrown word to vector words used
			/// </summary>
			/// <returns></returns>
			gameobject.word_used.push_back(temporary);


			cout << endl;
			gameobject.set_user_score(10);

			//Computer Begins methods
			cout << "\t Chance Passed to Computer :" << endl;
			cout << "\t Throwing....!!!" << endl;
			cout << endl;
			bool c = gameobject.word_found1(temporary);

			if (c == true)
			{
				gameobject.throw_word1(temporary);
				gameobject.set_computer_score(10);
			}
			else
			{
				cout << "\tNo words found By the computer" << endl;
				cout << "\tYou win" << endl;
				break;
			}
			c_count = c_count + 1;
		}
		else if (a == false)
		{
			cout << "\tWord thrown out of the dictionary" << endl;
			cout << endl;
			cout << "\tRetry" << endl;
			gameobject.deduce_user_score(2);
			c_count = c_count + 1;
		}
		else if (b == true)
		{
			cout << "\tWord already Used" << endl;
			gameobject.deduce_user_score(2);
			cout << endl;
			cout << "retry" << endl;
			c_count = c_count + 1;
		}

	}

	if (gameobject.display_user_score() < gameobject.display_computer_score())
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "\n\t\t\t\t   Computer Wins  ; P  " << endl;
		cout << "	\t\t\t   ------------------" << endl;
	}
	else if (gameobject.display_computer_score() == gameobject.display_user_score())
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "\n\t\t\t\t   The game is Drawww : " << endl;
		cout << "	\t\t\t   ------------------" << endl;
	}
	else
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "\n\t\t\t\t   You win  : )  " << endl;
		cout << "	\t\t\t   ------------------" << endl;
	}
}

void play_with_custom_dictionary()
{
	///Use with custom dictionary.
	int rounds = 10;
	Game gameobject;

	cout << "\t\t\t WORD-TAKSHRI GAME (Version 2.0)" << endl;
	cout << "\t\t\t---------------------------------" << endl;

	cout << endl;
	cout << endl;

	cout << "\t\t\t     Rules of the game are : " << endl;
	cout << "\t\t\t---------------------------------" << endl;

	cout << "       Rules : " << endl;
	cout << endl;
	cout << "    1. There will be 10 Rounds in the game." << endl;
	cout << "    2. You will be asked to throw a word." << endl;
	cout << "    3. If your word is from the Dictionary then computer throws a word." << endl;
	cout << "    4. The word should start from the last letter of the word thrown by the Computer." << endl;
	cout << "		4.a The above part only applies after the very first attempt." << endl;
	cout << "    5. On every successfull word you gain 10 points and on every retry you loose 2 points." << endl;
	cout << "    6. If computer fails to find a word then you win otherwise at the end of the game the person with highest score wins." << endl;
	cout << "    7. Later parts of the game will contain more dictionary words." << endl;

	cout << endl;
	cout << endl;


	int c_count = 1;
	while (rounds--)
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "                                 |  Round Number : " << c_count << "  |" << endl;
		cout << "	\t\t\t   ------------------" << endl;
		cout << "																									Your Score : " << gameobject.display_user_score() << endl;
		cout << "																									Computer Score : " << gameobject.display_computer_score() << endl;
		cout << "\t-----------------------------------------------------------------------------------------------------" << endl;

		string temporary;
		int user_score = 0;
		int pc_score = 0;

		cout << "\tIt's Your chance : " << endl;
		cout << "\tChoose a word : " << endl;


		cin >> temporary;
		bool a = gameobject.if_found_in_dictionary(temporary);
		bool b = gameobject.if_word_is_used(temporary);

		if (a == true && b == false)
		{
			/// <summary>
			/// adds the thrown word to vector words used
			/// </summary>
			/// <returns></returns>
			gameobject.word_used.push_back(temporary);


			cout << endl;
			gameobject.set_user_score(10);

			//Computer Begins methods
			cout << "\t Chance Passed to Computer :" << endl;
			cout << "\t Throwing....!!!" << endl;
			cout << endl;
			bool c = gameobject.word_found(temporary);

			if (c == true)
			{
				gameobject.throw_word(temporary);
				gameobject.set_computer_score(10);
			}
			else
			{
				cout << "\tNo words found By the computer" << endl;
				cout << "\tYou win" << endl;
				break;
			}
			c_count = c_count + 1;
		}
		else if (a == false)
		{
			cout << "\tWord thrown out of the dictionary" << endl;
			cout << endl;
			cout << "\tRetry" << endl;
			gameobject.deduce_user_score(2);
			c_count = c_count + 1;
		}
		else if (b == true)
		{
			cout << "\tWord already Used" << endl;
			gameobject.deduce_user_score(2);
			cout << endl;
			cout << "retry" << endl;
			c_count = c_count + 1;
		}

	}

	if (gameobject.display_user_score() < gameobject.display_computer_score())
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "\n\t\t\t\t   Computer Wins  ; P  " << endl;
		cout << "	\t\t\t   ------------------" << endl;
	}
	else if (gameobject.display_computer_score() == gameobject.display_user_score())
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "\n\t\t\t\t   The game is Drawww : " << endl;
		cout << "	\t\t\t   ------------------" << endl;
	}
	else
	{
		cout << "	\t\t\t   ------------------" << endl;
		cout << "\n\t\t\t\t   You win  : )  " << endl;
		cout << "	\t\t\t   ------------------" << endl;
	}


}

int main()
{
	int n;
	Game gameobject_temp;


	cout << "Press 1 to use the Computer Dictionary" << endl;
	cout << "Press 2 to use the Custom Dictioanry" << endl;
	cin >> n;
	

	switch (n)
	{
	case 1:
		play_with_Computer_dictionary();
		break;


	case 2:
		
		cout << "Use Words from the showcased Dictionary" << endl;
		for (auto i : gameobject_temp.Dictionary)
			cout << i << "  ";
		
		play_with_custom_dictionary();
		break;

	}

}

