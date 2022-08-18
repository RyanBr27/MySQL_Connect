#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const char *password = "9NP$7!Rt&Enp%HD";

int main()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	try
	{
		//connect to database
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	con->setSchema("quickstartdb");

	//creating a table named managestock
	stmt = con->createStatement();
	stmt->execute("DROP TABLE IF EXISTS managestock");
	cout << "Finished dropping table (if existed)" << endl;
	stmt->execute("CREATE TABLE managestock (Inventory_id serial PRIMARY KEY, Name VARCHAR(50), Unit_Price DOUBLE, Quantity_In_Stock INTEGER);");
	cout << "Finished creating table" << endl;
	delete stmt;

	//manually uploading data onto table
	pstmt = con->prepareStatement("INSERT INTO managestock (Name, Unit_Price, Quantity_In_Stock) VALUES(?,?,?)");
	pstmt->setString(1, "flash light");
	pstmt->setDouble(2, 11.50);
	pstmt->setInt(3, 400);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "door mat");
	pstmt->setDouble(2, 25.00);
	pstmt->setInt(3, 220);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "bookshelf");
	pstmt->setDouble(2, 140.00);
	pstmt->setInt(3, 75);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "lawn mower");
	pstmt->setDouble(2, 400.00);
	pstmt->setInt(3, 530);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "power drill");
	pstmt->setDouble(2, 150.00);
	pstmt->setInt(3, 50);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "sand paper");
	pstmt->setDouble(2, 7.50);
	pstmt->setInt(3, 175);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "patio chair");
	pstmt->setDouble(2, 50.50);
	pstmt->setInt(3, 85);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "bug spray");
	pstmt->setDouble(2, 6.40);
	pstmt->setInt(3, 30);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "vase");
	pstmt->setDouble(2, 40.00);
	pstmt->setInt(3, 14);
	pstmt->execute();
	cout << "One row inserted." << endl;

	pstmt->setString(1, "tool set");
	pstmt->setDouble(2, 65.00);
	pstmt->setInt(3, 295);
	pstmt->execute();
	cout << "One row inserted." << endl;

	delete pstmt;
	delete con;
	system("pause");
	return 0;
}





