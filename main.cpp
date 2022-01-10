#pragma once
#include "../analytics/structs/table.h"
#include <iostream>

using namespace std;

int main() {

	cout << "Okay" << endl;

	time_t now = time(0);   // current system date/time
	char* dt = ctime(&now);   // convert in string form
	tm* tm_1 = gmtime(&now);   // converting now to tm struct for UTC date/time



	vector<Row> rows {
		Row(*tm_1, RateType::OIS, 0.05),
		Row(*tm_1, RateType::LIBOR, 0.20)
	};


	Table table(rows);
	vector<vector<string>> display = table.display();

	for (auto& row : display)
	{
		for (auto& item : row)
		{
			cout << item << "\t";
		}

		cout << "\n";
	}


	return 0;
}
