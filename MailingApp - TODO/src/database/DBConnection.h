#pragma once

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <vector>

#define DB_SERVER   "TTC-206-22"
#define DB_PORT     "3306"
#define DB_NAME     "networks"
#define DB_USERNAME "pauor"
#define DB_USERPASS "47674995Ckr"


typedef std::string DBResultColumn;

struct DBResultRow
{
	std::vector<DBResultColumn> columns;
};

struct DBResultSet
{
	std::vector<DBResultRow> rows;

	void print() const;
};


class DBConnection
{
public:

	// Constructor
	DBConnection(
		const char *server       = DB_SERVER,
		const char *port         = DB_PORT,
		const char *dataBase     = DB_NAME,
		const char *userName     = DB_USERNAME,
		const char *userPassword = DB_USERPASS);

	// Destructor
	~DBConnection();

	// Tells if it is connected to a database
	bool isConnected() const;

	// Performs a sql query
	DBResultSet sql(const char *sql, ...);

private:

	// Connect to the database
	bool connect(
		const char *server,
		const char *port,
		const char *dataBase,
		const char *userName,
		const char *userPassword);

	// Disconnect from the database (automatic on destruction)
	void disconnect();
	
	//define handles and variables
	SQLHANDLE sqlConnHandle; // Connection handle
	SQLHANDLE sqlEnvHandle;  // Environment handle
};
