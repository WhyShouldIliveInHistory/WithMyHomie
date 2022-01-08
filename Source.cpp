#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <cstdlib>

using namespace std;



class spy
{
public:
	int budget;
	int hp;
	int action;
	spy()
	{
		budget = 100;
		hp = 100;
		action = 0;

	}
};

void change_hp(spy* spy_1, spy* spy_2)
{	
	cout << "The duel starts !" << endl;
	if (spy_1->action == spy_2->action)
	{
		cout << " Same action therefore nullified !" << endl;
	}
	else
	{
		if (spy_1->action == 1 && spy_2->action == 2)//Attack vs Shield ; Shield wins ; Attack reflected ; - 10 HP for the spy 1;
		{
			cout << "spy 2 couters spy 1" << endl;
			cout << " -10 hp inflected" << endl;
			spy_1->hp -= 10;

		}
		else if (spy_1->action == 2 && spy_2->action == 1)//Shield vs Attack ; Shield wins ; Attack reflected ; - 10 HP for the spy 2;
		{
			cout << "spy 1 couters spy 1" << endl;
			cout << " -10 hp inflected" << endl;
			spy_2->hp -= 10;

		}
		else if (spy_1->action == 1 && spy_2->action == 3)//Attack vs Steal ; Attack wins ; Attack inflencted ; - 10 HP for the spy 2;
		{
			cout << "spy 1 did 10 damage to spy 2" << endl;
			cout << " -10 hp inflected" << endl;
			spy_2->hp -= 10;

		}
		else if (spy_1->action == 3 && spy_2->action == 1)//Steal vs Attack ; Attack wins ; Attack inflected ; - 10 HP for the spy 1;
		{
			cout << "spy 2 did 10 damage to spy 2" << endl;
			cout << " -10 hp inflected" << endl;
			spy_1->hp -= 10;

		}
		else if (spy_1->action == 2 && spy_2->action == 3)//Shield vs Steal ; Steal wins ; Stealing... ; - 10 Euros for the spy 2;
		{
			cout << "spy 2 stole 10 euros" << endl;
			cout << " 1st Spy's Budget: -10 euros... "<< endl;
			spy_1->budget -= 10;
			spy_2->budget += 10;

		}
		else  //Steal vs Shield ; Steal wins ; Stealing... ; - 10 Euros for the spy 1;
		{
			cout << "spy 1 stole 10 euros" << endl;
			cout << " 2nd Spy's Budget: -10 euros..." << endl;
			spy_2->budget -= 10;
			spy_1->budget += 10;

		}
		

	}
	cout << "Printing overral:" << endl;
	cout << " spy 1 hp: " << spy_1->hp << endl;
	cout << " spy 1 budget: " << spy_1->budget << endl;
	cout << "spy 2 hp :" << spy_2->hp << endl;
	cout << " spy 2 budget: " << spy_2->budget << endl;


	


}
void random_action(spy* spy_p)
{
	srand(time(NULL));
	spy_p->action = 1 + (rand() % 3);
	cout << spy_p->action << endl;
	
}



int main(int argc, char *argv[])
{
	spy spy_1;
	spy spy_2;
	while (true)
	{
		thread t1(random_action, &spy_1);
		this_thread::sleep_for(1.5s);
		t1.join();
		thread t2(random_action, &spy_2);
		t2.join();

		change_hp(&spy_1,&spy_2);
		cin.get();
		if ((spy_1.hp == 0) || (spy_2.hp == 0) || (spy_1.budget == 0) || (spy_2.budget == 0))
		{
			cout << "GAME OVER !" << endl;
			break;
		}
	
	}





}