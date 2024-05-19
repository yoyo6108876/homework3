#include<iostream>
#include<vector>
using namespace std;
class Television
{
public:
	Television(string displayType, double dimension, vector <string> connectivitySupport) :displayType(displayType), dimension(dimension), connectivitySupport(connectivitySupport) {};
	Television() :displayType(""), dimension(0), connectivitySupport() {};
	Television(const Television&t);
	void setDisplayType(string displayType) { this->displayType = displayType; };
	void setDimension(double dimension) { this->dimension = dimension; };
	void setConnectivitySupport(vector <string> connectivitySupport) { this->connectivitySupport = connectivitySupport; };
	string getdisplayType() { return displayType; }
	double getdimension() { return dimension; }
	vector <string> *getconnectivitySupport() { return &connectivitySupport; }
	void input();
	void output();
	
private:
	string displayType;
	double dimension;
	vector <string> connectivitySupport;

};
int 
main()
{
	Television television,television1;
	vector<Television> televisionCopy;
	television.input();
	vector <string> connectivitySupport;
	television.output();
	television1 = television;
	cout << "How many copies you want ?" << endl;
	int copy;
	cin >> copy;
	for (int i = 0; i < copy; i++)
	{
		televisionCopy.push_back(television1);
		cout << "\nTelevision " << i + 2 << ":" << endl;
		televisionCopy.at(i).output();
	}
	string check;
	do
	{
	cout << "Do you want you change the details?(yes or no" << endl;
	cin >> check;
	if (check=="yes"|| check == "Yes")
	{
		cout << "Which television you want to change? "<<endl;
		int type;
		cin >> type;
		cout << "What do you want to change ?(displayType enter 1, dimension enter 2, connectivitySupport enter 3)" << endl;
		int type1;
		cin >> type1;
		if (type1 == 1)
		{
			string temp;
			cout << "Enter the display type of the television => ";
			cin >> temp;
			televisionCopy[type - 2].setDisplayType(temp);
		}
		else if (type1 == 2)
		{
			double temp;
			cout << "Enter the dimension of the television in inches => ";
			cin >> temp;
			televisionCopy[type - 2].setDimension(temp);
		}
		else if (type1 == 3)
		{
			string mode;
			cout << "Enter the different connectivity modes supported by the television (use -9999 to stop) => ";
			cin >> mode;
			while (mode != "-9999") {
				connectivitySupport.push_back(mode);
				cin >> mode;
			}
			televisionCopy[type - 2].setConnectivitySupport(connectivitySupport);
		}
	}
	} while (check != "no"); 
	cout << "This is your final list :" << endl;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < copy; i++)
	{
		cout << "\nTelevision " << i + 2 << ":" << endl;
		televisionCopy.at(i).output();
	}
	return 0;
}
void Television::input()
{
	string mode;

	cout << "Enter the display type of the television => ";
	cin >> displayType;

	do {
		cout << "Enter the dimension of the television in inches => ";
		cin >> dimension;
	} while (dimension <= 0);

	cout << "Enter the different connectivity modes supported by the television (use -9999 to stop) => ";
	cin >> mode;
	while (mode != "-9999") {
		connectivitySupport.push_back(mode);
		cin >> mode;
	}
}
void Television::output() {
	cout << "\nDisplay type: " << displayType << endl;
	cout << "Dimension: " << dimension << " inches" << endl;
	cout << "Connectivity modes: \n";
	for (int i = 0; i < connectivitySupport.size(); i++)
		cout << connectivitySupport[i] << endl;
	cout << "\n-----------------------------------\n\n";
}
Television::Television(const Television& t)
{
	displayType = t.displayType;
	dimension = t.dimension;
	connectivitySupport = t.connectivitySupport;
}