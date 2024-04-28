#include "TestCases.hpp"
void Test::testInsertInOrder()
{
	List l;
	int n1 = 1, n2 = 1, n3 = 1, m2 = 2, m1 = 2, m3 = 2, o1 = 3, o2 = 3, o3 = 3;
	string nStr = "Arch", mStr = "Kobe", oStr = "Lebron";
	Data n(n1, n2, n3, nStr), m(m1, m2, m3, mStr), o(o1, o2, o3, oStr);
	l.insertInOrder(m);
	l.insertInOrder(n);
	l.insertInOrder(o);
	if (l.getHeadPtr()->getData().getScore() > l.getHeadPtr()->getNextPtr()->getData().getScore()
		&& l.getHeadPtr()->getNextPtr()->getData().getScore() > l.getHeadPtr()->getNextPtr()->getNextPtr()->getData().getScore())
	{
		cout << "Insetring in Order works" << endl;
	}
	else
	{
		cout << "Failure in inserting in order" << endl;
	}
}
void Test::testPrintCSV()
{
	ofstream outfile;
	outfile.open("dummy.csv");
	List l;
	int n1 = 1, n2 = 1, n3 = 1, m2 = 2, m1 = 2, m3 = 2, o1 = 3, o2 = 3, o3 = 3;
	string nStr = "Arch", mStr = "Kobe", oStr = "Lebron";
	Data n(n1, n2, n3, nStr), m(m1, m2, m3, mStr), o(o1, o2, o3, oStr);
	l.insertInOrder(m);
	l.insertInOrder(n);
	l.insertInOrder(o);
	l.printList(outfile); // testing this function
	outfile.close();
	ifstream infile;
	infile.open("dummy.csv");
	if (infile.peek() != ifstream::traits_type::eof())
	{
		cout << "Success in printing to file" << endl;
	}
	else
	{
		cout << "Failure in printing to file" << endl;
	}
	infile.close();
}
void Test::testIncrementScore()
{
	Score s(30, sf::Vector2f(1700, 50));
	int a = s.getScore();
	string aStr = s.getString();
	s.incrementScore(5);
	if (a + 5 == s.getScore())
	{
		cout << "success in incrementing score" << endl;
	}
	else
	{
		cout << "Failure in incrementing score" << endl;
	}
	if (s.getString() == "Score: 5")
	{
		cout << "Success in incrementing string score" << endl;
	}
	else
	{
		cout << "Failure in incrementing string score" << endl;
	}
}
void Test::testGenerateRandomPosition()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test Case");
	Target T(20.f, sf::Vector2f(0.5 * window.getSize().x, 0.5 * window.getSize().y), sf::Color::Green);
	sf::Vector2f A(T.getPosition());
	T.generateRandomPostition(window);
	sf::Vector2f B(T.getPosition());
	T.generateRandomPostition(window);
	sf::Vector2f C(T.getPosition());
	sf::Vector2f A1(A.x, A.y), B1(B.x, B.y), C1(C.x, C.y);
	if (A == B || A == C || B == C)
	{
		cout << "Success in randomly generating position " << endl;
	}
	else
	{
		cout << "Failure in randomly generating position" << endl;
	}
}
void Test::testImport()
{
	ifstream infile;
	infile.open("dummy.csv");
	List l;
	l.importFile(infile);
	if (l.getHeadPtr() == nullptr)
		cout << "Failure in importing file" << endl;
	else
		cout << "Success in importing file" << endl;
}