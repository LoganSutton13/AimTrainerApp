#include "TestCases.hpp"
#include "List.hpp"
//#include "Target.hpp"
#include "Button.hpp"
#include "Scores.hpp"
#include "Data.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

#define EASY 1;
#define MEDIUM 2;
#define HARD 3;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

int main()
{
	// Test Cases //
	Test t;
	t.testInsertInOrder();
	t.testPrintCSV();
	t.testIncrementScore();
	t.testGenerateRandomPosition();
	t.testImport();
	// End Test Cases //

	ifstream easyLeaderboard, mediumLeaderboard, hardLeaderboard;
	easyLeaderboard.open("Leaderboard.csv");
	mediumLeaderboard.open("mediumLeaderboard.csv");
	hardLeaderboard.open("hardLeaderboard.csv");
	List easyList, mediumList, hardList;
	easyList.importFile(easyLeaderboard);
	mediumList.importFile(mediumLeaderboard); // mediumList has contents of mediumLeaderboard
	hardList.importFile(hardLeaderboard);
	easyLeaderboard.close();
	mediumLeaderboard.close();
	hardLeaderboard.close();

	int hits = 0, misses = 0;
	string playerName = "";

	cout << "Enter a username: ";
	std::getline(std::cin, playerName);


	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Target Practice");
	std::srand(std::time(nullptr));

	int radius = (int)(window.getSize().x * 0.025), roundLength = 30, levelChoice = 0;

	// testing a target of the color green to move through the screen, can later set certain objects as a specific color
	// and that color will have it's own point system - this is where we will use inheritanec
	//Target target(250.f, sf::Vector2f(0.5 * window.getSize().x, 0.5 * window.getSize().y), sf::Color::Green);
	Target target(radius, sf::Vector2f(0.5 * window.getSize().x, 0.5 * window.getSize().y), sf::Color::Green);



	std::string easy = "Easy", medium = "Medium", hard = "Hard", endGame = "End Game", htp = "How To Play",
		displayLeaderboard = "Display Leaderboard";
	Button button1(sf::Vector2f(640, 360), sf::Vector2f(200, 100), sf::Color(sf::Color::Green), easy, 30);
	Button button2(sf::Vector2f(960, 360), sf::Vector2f(200, 100), sf::Color(sf::Color::Blue), medium, 30);
	Button button3(sf::Vector2f(1280, 360), sf::Vector2f(200, 100), sf::Color(sf::Color::Red), hard, 30);
	Button endGameButton(sf::Vector2f(1775, 200), sf::Vector2f(150, 50), sf::Color::Red, endGame, 25);
	Button howToPlay(sf::Vector2f(1750, 900), sf::Vector2f(150, 75), sf::Color::Red, htp, 25);
	Button leaderboardButton(sf::Vector2f(1750, 800), sf::Vector2f(150, 75), sf::Color::Magenta,
		displayLeaderboard, 14);

	Score score(30, sf::Vector2f(1700, 50));

	sf::Clock clock; sf::Time time(sf::seconds(5)), timeStarted;


	bool runGame = false;
	bool gameStarted = false;
	bool showHowToPlay = false;
	bool showLeaderboard = false;

	sf::Font font;
	font.loadFromFile("ARIAL.TTF");

	sf::Text welcomeTitle("Welcome to Aim Trainer!", font, 100);
	welcomeTitle.setOrigin(welcomeTitle.getLocalBounds().width / 2, welcomeTitle.getLocalBounds().height / 2);
	welcomeTitle.setPosition(window.getSize().x / 2, window.getSize().y / 8);

	sf::Text timerText("", font, 30);
	timerText.setPosition(sf::Vector2f(1700, 100));

	sf::Text postGameStats("", font, 45);

	////////////////////// Leaderboard Text /////////////////////////
	string easyLeaderboardText = easyList.printScoreboardData();
	sf::Text easyLeaderboardPrint(easyLeaderboardText, font, 40);
	easyLeaderboardPrint.setPosition(sf::Vector2f(200, 200));

	sf::Text easyLabel("Easy Leaderboard", font, 40);
	easyLabel.setPosition(sf::Vector2f(230, 100));

	string mediumLeaderboardText = mediumList.printScoreboardData();
	sf::Text mediumLeaderboardPrint(mediumLeaderboardText, font, 40);
	mediumLeaderboardPrint.setPosition(sf::Vector2f(700, 200));

	sf::Text mediumLabel("Medium Leaderboard", font, 40);
	mediumLabel.setPosition(sf::Vector2f(720, 100));

	string hardLeaderboardText = hardList.printScoreboardData();
	sf::Text hardLeaderboardPrint(hardLeaderboardText, font, 40);
	hardLeaderboardPrint.setPosition(sf::Vector2f(1300, 200));

	sf::Text hardLabel("Hard Leaderboard", font, 40);
	hardLabel.setPosition(sf::Vector2f(1330, 100));
	////////////////////////////////////////////////////////////////////////


	//////////////////////// How to play //////////////////////////////////
	string htpText = "Try to hit as many of the targets as possible in 30 seconds!\n\
You'll be awarded points based on how many targets you hit.\n\
Accuracy matters. You'll lose points for each target you miss.";
	sf::Text howToPlayText(htpText, font, 40);
	howToPlayText.setOrigin(sf::Vector2f(howToPlayText.getLocalBounds().width / 2,
		howToPlayText.getLocalBounds().height));
	howToPlayText.setPosition(sf::Vector2f(960, 600));
	////////////////////////////////////////////////////////////////////////

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// Gets mouse position at real time
			sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

			//////////////// Target Hit //////////////////////////
			if (target.getGlobalBounds().contains(mousePosition) && runGame)
			{
				target.hover(true);
				if (event.type == sf::Event::MouseButtonPressed)
				{
					//cout << "Hit target!" << endl;
					score.incrementScore(5);
					target.setNewPosition(target.generateRandomPostition(window));
					hits += 1;

				}
			}
			else if (runGame)
			{
				target.hover(false);
				if (event.type == sf::Event::MouseButtonPressed)
				{
					misses += 1;
					if (levelChoice == 1)
						score.incrementScore(-1);
					else if (levelChoice == 2)
						score.incrementScore(-2);
					else if (levelChoice == 3)
						score.incrementScore(-3);
				}
			}

			//////////////////////// Button Hover /////////////////////////////////
			if (button1.getShape()->getGlobalBounds().contains(mousePosition)) { button1.hover(true); }
			else { button1.hover(false); }
			if (button2.getShape()->getGlobalBounds().contains(mousePosition)) { button2.hover(true); }
			else { button2.hover(false); }
			if (button3.getShape()->getGlobalBounds().contains(mousePosition)) { button3.hover(true); }
			else { button3.hover(false); }
			if (endGameButton.getShape()->getGlobalBounds().contains(mousePosition)) { endGameButton.hover(true); }
			else { endGameButton.hover(false); }
			if (howToPlay.getShape()->getGlobalBounds().contains(mousePosition)) { howToPlay.hover(true); }
			else { howToPlay.hover(false); }
			if (leaderboardButton.getShape()->getGlobalBounds().contains(mousePosition)) { leaderboardButton.hover(true); }
			else { leaderboardButton.hover(false); }
			// Easy Mode Button Click - turns run game true and started game true
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (button1.getShape()->getGlobalBounds().contains(mousePosition) && !runGame)
				{
					runGame = true;
					gameStarted = true;
					target.setFillColor(sf::Color::Green);
					levelChoice = EASY;
				}
			}

			// Medium Mode Button Click - turns run game true and started game true
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (button2.getShape()->getGlobalBounds().contains(mousePosition) && !runGame)
				{
					runGame = true;
					gameStarted = true;
					target.setRadius(target.getRadius() * 2 / 3);
					target.setFillColor(sf::Color::Blue);
					levelChoice = MEDIUM;
				}
			}

			// Hard Mode Button Click - turns run game true and started game true
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (button3.getShape()->getGlobalBounds().contains(mousePosition) && !runGame)
				{
					runGame = true;
					gameStarted = true;
					target.setRadius(target.getRadius() * 2 / 4);
					target.setFillColor(sf::Color::Red);
					levelChoice = HARD;
				}
			}

			// EndGame button
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (endGameButton.getShape()->getGlobalBounds().contains(mousePosition) && runGame)
				{
					runGame = false;
					target.setRadius(radius);
				}
			}

			// leaderboard button
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (leaderboardButton.getShape()->getGlobalBounds().contains(mousePosition) && !runGame)
				{
					showLeaderboard = !showLeaderboard;
					if (showLeaderboard)
					{
						string t = "Close Leaderboard";
						leaderboardButton.editText(t);
					}
					else
					{
						string t = "Display Leaderboard";
						leaderboardButton.editText(t);
					}
				}
			}

			// How to play button
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (howToPlay.getShape()->getGlobalBounds().contains(mousePosition) && !runGame)
				{
					showHowToPlay = !showHowToPlay;
					if (showHowToPlay)
					{
						string t = "Close";
						howToPlay.editText(t);
					}
					else
					{
						string t = "How To Play";
						howToPlay.editText(t);
					}
				}
			}
		}
		// Restarts gameclock and stats 
		if (gameStarted == true)
		{
			clock.restart();
			gameStarted = false;
			hits = 0;
			misses = 0;
			score.setScore(0);
		}
		// Gets elapsed time from the start of a round
		// TODO: load list once
		timeStarted = clock.getElapsedTime();
		if (runGame)
		{
			std::string timeString = std::to_string(roundLength - int(timeStarted.asSeconds())) + "s";
			timerText.setString(timeString);
			if (clock.getElapsedTime().asSeconds() > roundLength)
			{
				int currentScore = score.getScore();
				Data data(currentScore, hits, misses, playerName);
				float accuracy = 0.0;
				if (hits == 0)
					accuracy = 0;
				else
				{
					accuracy = (float)hits / (hits + misses) * 100;
					(int)accuracy / 100;
				}

				// working on putting the data on the text for the post game details screen - need to get accuracy and print it all into one string into a text
				string level = "";
				if (levelChoice == 1)
					level = "Easy";
				else if (levelChoice == 2)
					level = "Medium";
				else if (levelChoice == 3)
					level = "Hard";
				string hitsStr = std::to_string(hits), missesStr = std::to_string(misses), accuracyStr = std::to_string((int)accuracy), scoreStr = std::to_string(currentScore);
				string postGame = "Previous Round Stats: \nDifficulty: " + level + "\nScore: " + scoreStr + "\nHits: " + hitsStr + "\nMisses: " + missesStr + "\nAccuracry: " + accuracyStr + " % ";
				postGameStats.setString(postGame);
				postGameStats.setOrigin(postGameStats.getLocalBounds().width / 2, postGameStats.getLocalBounds().height / 2);
				postGameStats.setPosition(window.getSize().x / 2, window.getSize().y / 1.5);

				runGame = false;
				target.setRadius(radius);

				// make this insert a function?
				if (levelChoice == 1)
				{
					easyList.insertInOrder(data);
					easyLeaderboardText = easyList.printScoreboardData();
					easyLeaderboardPrint.setString(easyLeaderboardText);
				}
				else if (levelChoice == 2)
				{
					mediumList.insertInOrder(data);
					mediumLeaderboardText = mediumList.printScoreboardData();
					mediumLeaderboardPrint.setString(mediumLeaderboardText);
				}
				else if (levelChoice == 3)
				{
					hardList.insertInOrder(data);
					hardLeaderboardText = hardList.printScoreboardData();
					hardLeaderboardPrint.setString(hardLeaderboardText);
				}
			}
		}

		/// Render ///
		window.clear();
		if (!runGame)leaderboardButton.render(window);
		if (!showLeaderboard)
		{
			if (runGame) window.draw(target);
			if (!runGame)button1.render(window);
			if (!runGame)button2.render(window);
			if (!runGame)button3.render(window);
			if (!runGame)window.draw(welcomeTitle);
			if (!runGame)howToPlay.render(window);
			if (!runGame && !showHowToPlay)window.draw(postGameStats);
			if (runGame)endGameButton.render(window);
			if (runGame)window.draw(timerText);
			if (runGame)window.draw(score);
			if (showHowToPlay && !runGame)window.draw(howToPlayText);
		}
		else
		{
			window.draw(easyLeaderboardPrint);
			window.draw(mediumLeaderboardPrint);
			window.draw(hardLeaderboardPrint);
			window.draw(easyLabel);
			window.draw(mediumLabel);
			window.draw(hardLabel);
		}
		window.display();
	}
	//cout << "ScoreBoard" << endl;
	//cout << "Name: " << scoreboard.front().getName() << endl;
	//cout << "Score: " << scoreboard.front().getScore() << endl;
	//cout << "Hits: " << scoreboard.front().getHits() << endl;
	//cout << "Misses: " << scoreboard.front().getMisses() << endl;
	//cout << "Accuracy: " << scoreboard.front().getAccuracy() << endl;
	ofstream easyLeaderboardOut, mediumLeaderboardOut, hardLeaderboardOut;
	easyLeaderboardOut.open("Leaderboard.csv");
	mediumLeaderboardOut.open("mediumLeaderboard.csv");
	hardLeaderboardOut.open("hardLeaderboard.csv");
	easyList.printList(easyLeaderboardOut);
	mediumList.printList(mediumLeaderboardOut);
	hardList.printList(hardLeaderboardOut);
	easyLeaderboardOut.close();
	mediumLeaderboardOut.close();
	hardLeaderboardOut.close();
	return 0;
}