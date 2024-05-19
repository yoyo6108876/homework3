#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Subscrit
{
public:
	Subscrit() :numChannels(0) { channelList = new vector<string>(); };
	Subscrit(string name):name(name),numChannels(0){ channelList = new vector<string>(); }
	~Subscrit() { delete channelList; }
	string getname() { return name; }
	int getnum() { return numChannels; }
	vector<string>*getchannelList() { return channelList; }
	void setname(string name) { this->name = name; }
	void setnumChannels(int numChannels) { this->numChannels = numChannels; }
	void setchannelList(vector<string>channelList) { this->channelList = &channelList; }
	void output();
	void input();
	void reset();
	vector<string> operator =(vector<string>NewList);
private:
	string name;
	int numChannels;
	vector<string>*channelList;
};

void Subscrit::input()
{
	string temp;
	cout << "Enter the subxcriber name->" << endl;
	cin >> name;
	cout << endl << "Enter the name of channel you subscrib=>" << endl;
	getline(cin, temp);
	while (temp != "-999" ){
		channelList->push_back(temp);
		getline(cin, temp);
	} 
	cout << 1;
	numChannels = channelList->size();
}

void Subscrit:: reset()
{
	numChannels = 0;
	channelList->clear();
}
void Subscrit::output()
{
	cout << "The subscriber's name is " << name << endl;
	cout << "You have subscrib " << numChannels << " channels " << endl;
	cout << "The channel list is :" << endl;
	for (int i = 0; i < numChannels; i++)
	{
		cout << channelList->at(i) << endl;
	}
}
vector<string> Subscrit::operator =(vector<string>NewList)
{
	string temp;
	for (int i = 0; i < numChannels; i++)
	{
		NewList.push_back(channelList->at(i));
	}
	return NewList;
}
int
main()
{
	Subscrit first;
	vector<string>* list;
	first.input();
	first.output();
	string copy;
	cout << "If you want to copy the list? (Enter yes or no)" << endl;
	cin >> copy;
	if (copy=="yes"|| copy == "Yes")
	{
		list = first.getchannelList();
		for (int i = 0; i < list->size(); i++)
		{
			cout << list->at(i) << endl;
		}
	}
	first.reset();
	return 0;
}