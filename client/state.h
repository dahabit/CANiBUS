#ifndef __CANIBUS_STATE_H__
#define __CANIBUS_STATE_H__

#include <string>
#include <vector>

class CanibusClient;
class CanbusDevice;
class CanibusLogger;
class CanibusSession;

class CanibusState
{
public:
	CanibusState();
	~CanibusState();
	enum Status { Init, Lobby, Config, Run };
	void setStatus(Status status) { m_status = status; }
	Status status() { return m_status; }
	void setNick(std::string username);
	std::string nick() { return m_nick; }
	int updateClient(CanibusClient *cInfo);
	void delClient(CanibusClient *client);
	CanibusClient *findClientById(int id);
	int updateCanbusDevice(CanbusDevice *cbInfo);
	int updateSession(CanibusSession *sesionInfo);
	CanbusDevice *findCanbusDeviceById(int id);
	CanibusSession *findSessionById(int id);
	void clearDevices() { m_canbusDevices.clear(); }
	std::vector<CanibusClient *>clients() { return m_clients; }
	std::vector<CanbusDevice *>devices() { return m_canbusDevices; }
	std::vector<CanibusSession *>sessions() { return m_sessions; }
private:
	Status m_status;
	std::string m_nick;
	std::vector<CanibusClient *>m_clients;
	std::vector<CanbusDevice *>m_canbusDevices;
	std::vector<CanibusSession *>m_sessions;
	CanibusLogger *logger;
};

#endif
