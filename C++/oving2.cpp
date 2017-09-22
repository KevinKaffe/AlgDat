#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <string.h>

using namespace std;

struct duo
{
	int nr;
	char letter;
	duo *next;
};
duo * merge2(duo *deck1, duo *deck2)
{
	duo * dummy = new duo();
	duo * current = dummy;
	while (deck1 && deck2)
	{
		if (deck1->nr > deck2->nr)
		{
			current->next = deck2;
			deck2 = deck2->next;
		}
		else
		{
			current->next = deck1;
			deck1 = deck1->next;
		}
		current = current->next;
	}
	if (deck1)
		current->next = deck1;
	else
	{
		current->next = deck2;
	}
	return dummy->next;
}
duo * merge(duo * decks[], int start, int slutt)
{
	if (start > slutt)
		return NULL;
	if (start == slutt)
		return decks[start];
	return merge2(merge(decks, start, (start + slutt) / 2),
		merge(decks, (start + slutt) / 2 + 1, slutt));
}
int main(int arg)
{
	duo *myArray[29];
	char line[300000], *val, *val1;
	int valsRead, value;
	int index = 0;
	//char delims[] = ",";
	while (fgets(line, 300000, stdin) != NULL)
	{
		char currentLetter = line[0];
		val = strtok(line, ":");
		val = strtok(NULL, ",");
		valsRead = sscanf(val, "%d", &value);
		duo * root = new duo();
		root->letter = line[0];
		root->nr = value;
		duo * prev = root;
		val = strtok(NULL, ",");
		valsRead = (val == NULL) ? 0 : sscanf(val, "%d", &value);
		duo * next;
		while (valsRead > 0)
		{
			next = new duo();
			next->nr = value;
			next->letter = currentLetter;
			prev->next = next;
			prev = next;
			val = strtok(NULL, ",");
			valsRead = (val == NULL) ? 0 : sscanf(val, "%d", &value);
		}
		myArray[index++] = root;

	}
	duo * it = merge(myArray, 0, index);
	index = 0;
	while (it)
	{
		line[index++] = it->letter;
		it = it->next;
	}
	line[index] = '\0';
	printf("%s\n", line);
	/*
	string ayy = "";
	bool finished = false;
	while (!finished)
	{
	char firstLetter;
	int val;
	bool started = false;
	for (int c = 0; c < lett.size(); c++)
	{
	char letter = lett[c];
	if (myMap[letter].empty())
	{
	continue;
	}
	if (!started)
	{
	firstLetter = letter;
	val = myMap[letter][0];
	started = true;
	}
	else {
	if (myMap[letter][0]<val)
	{
	val = myMap[letter][0];
	firstLetter = letter;
	}
	}
	}
	ayy += firstLetter;
	myMap[firstLetter].erase(myMap[firstLetter].begin());
	for (int c = 0; c<lett.size(); c++)
	{
	if (!myMap[lett[c]].empty())
	{
	break;
	}
	if (c == lett.size() - 1)
	{
	finished = true;
	}
	}
	}
	/*
	int i =0;
	string outputString="";
	while(i<=maxer)
	{
	for(int d =0; d < lett.size(); d++)
	{
	char letter = lett[d];
	bool flag=false;
	for(int c=0; c<myMap[letter].size(); c++)
	{
	if(myMap[letter][c]==i)
	{
	outputString+=letter;
	flag=true;
	break;
	}
	}
	if(flag)
	{
	break;
	}
	}
	i++;
	}*/
	return 0;
}
