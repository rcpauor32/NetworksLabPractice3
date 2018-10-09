#pragma once

#include "IDatabaseGateway.h"
#include "DBConnection.h"

class MySqlDatabaseGateway :
	public IDatabaseGateway
{
public:

	// Constructor and destructor

	MySqlDatabaseGateway();

	~MySqlDatabaseGateway();


	// Virtual methods from IDatabaseGateway

	void insertMessage(const Message &message) override;

	std::vector<Message> getAllMessagesReceivedByUser(const std::string &username) override;

	virtual void updateGUI() override;

private:

	// Text buffers for ImGUI
	char bufMySqlHost[64] = DB_SERVER;
	char bufMySqlPort[64] = DB_PORT;
	char bufMySqlDatabase[64] = DB_NAME;
	char bufMySqlTable[64] = "messages";
	char bufMySqlUsername[64] = DB_USERNAME;
	char bufMySqlPassword[64] = DB_USERPASS;
};

