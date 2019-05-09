#ifndef NETWORKMANAGERCLIENT_H_INCLUDED
#define NETWORKMANAGERCLIENT_H_INCLUDED

#include "SFML/Network.hpp"

#include "PacketTypes.h"
#include "PacketSender.h"

class Client;

class NetworkManagerClient {
  public:
	NetworkManagerClient(Client& _client);

	void update();

	void sendPacket(Packet::TCPPacket _type);
	void sendPacket(Packet::UDPPacket _type);
	void receiveTCPPackets();
	void receiveUDPPackets();

	void connect(const sf::IpAddress& _ip, unsigned short _port);
	bool connectionActive() const;

	//This function returns a bool that specifies whether new message
	//was received over the network or not. An optional pointer can be
	//passed that will be assigned the new message.
	bool receivedMessage(std::pair<std::string, std::string>* _ptr = nullptr);
	void clearLastReceivedMessage();

	//When we send a CHAT_MESSAGE packet, it sends the contents of
	//m_messageToSend. This function can be used to set that variable
	//(such as by the UserInterface class) before a chat message is sent.
	void setMessageToSend(std::pair<std::string, std::string> _msg);

	//See explanation below for details
	//Note: chunkDataReceived can optionally take a pointer to a
	//vector of ints. If it does, the IDs of the chunks that were
	//received will be written to the vector, and so, not all chunks
	//need to be updated whenever one changes.
	bool chunkDataReceived(std::vector<int>* _ids = nullptr) const;
	void setChunkDataProcessed(bool _val);

  private:
	//Data members --------------------------------
	Client&       m_client;
	bool          m_connectionActive;
	sf::UdpSocket m_udpSocket;
	sf::TcpSocket m_serverConnection;

	//m_chunkDataReceived will be set to true whenever we receive any
	//new chunk data. The reason for this is we only need to visually
	//refresh (call RendererChunk.update()) when blocks in a chunk
	//actually change; after we do that, we'll set it back to false.

	//Additionally, the IDs of the received chunks will be written to
	//m_lastReceivedChunks
	bool             m_chunkDataReceived{false};
	std::vector<int> m_lastReceivedChunks;

	std::pair<std::string, std::string> m_lastReceivedMessage;
	std::pair<std::string, std::string> m_messageToSend;
	//---------------------------------------------
};

#endif // NETWORKMANAGERCLIENT_H_INCLUDED
