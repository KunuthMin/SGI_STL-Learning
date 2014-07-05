/********************************************************************
	File :			ClientFactory.h
	Creation date :	2010/6/27
		
	License :			Copyright 2010 Ahmed Charfeddine, http://www.pushframework.com

				   Licensed under the Apache License, Version 2.0 (the "License");
				   you may not use this file except in compliance with the License.
				   You may obtain a copy of the License at
				
					   http://www.apache.org/licenses/LICENSE-2.0
				
				   Unless required by applicable law or agreed to in writing, software
				   distributed under the License is distributed on an "AS IS" BASIS,
				   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
				   See the License for the specific language governing permissions and
				   limitations under the License.
	
	
*********************************************************************/
#ifndef ClientFactory__INCLUDED
#define ClientFactory__INCLUDED

#pragma once

#include "PushFramework.h"

namespace PushFramework{

class Client;
class ClientFactory;
class IncomingPacket;
class OutgoingPacket;
class ClientFactoryImpl;
class Dispatcher;
class Server;
class ServerImpl;

/**
	Contains the clients management logic (creation, login, disconnection, disposal, storage, ref count etc).
	*/
class PUSHFRAMEWORK_API ClientFactory
{
	friend Dispatcher;
	friend ServerImpl;
public:
	typedef enum
	{
		RefuseRequest = -2,
		RefuseAndClose,
		CreateClient,
		CreateAndRouteRequest,		
	}Result;

	ClientFactory(void);
	~ClientFactory(void);

	/**
		\param lpContext Used to store any contextual infos that can be provided to you back when the first request is received from the same connection.

		When a new connection is accepted, you can choose to send an outgoing packet before receiving a first request.
		You may need to push a dynamic context that can be provided to you when the first request is received.
		(used to separate legitemate users between illegetemate users).
		If you return NULL, the framework simply waits for client request and does not send anything untill then.
	*/
	virtual OutgoingPacket* onNewConnection(void*& lpContext) = 0;
	/**
		\param packet OutgoingPacket instance to encode.

		Override to encode the OutgoingPacket instance. Save the result into the same input.
	*/
	virtual void onClientDisconnected(ClientKey key) = 0;
	/**
		\param packet OutgoingPacket instance to encode.

		Override to encode the OutgoingPacket instance. Save the result into the same input.
	*/
	virtual void onBeforeDisposeClient(Client* pClient)=0;
	/**
		\param packet OutgoingPacket instance to encode.

		Override to encode the OutgoingPacket instance. Save the result into the same input.
	*/
	virtual void onClientReconnected(ClientKey key)=0;
	/**
		\param key Client key.

		Called after you successful login a Client in OnFirstRequest.
	*/
	virtual void onClientConnected(ClientKey key)=0;
	/**
		\param client key OutgoingPacket instance to encode.

		When the frameswork detects that an existing client has logged in through another connection,
		the past connection is closed and the new one is attached the existing Client structure.
		Furthermore, this function is triggered so you can perform certain logic.
	*/
	virtual void disposeClient(Client* pClient)=0;
	/**
	\param request A reference to the received request packet.
	\param lpContext reference to the context data that you supplied at ::onNewConnection.
	\param lpClient reference address to write your newly allocated Client structure to.
	\param lpPacket used to send a reply when the request is refused.

		Called for the first request received by an accepted connection.
		The function behaves like a login function. You may decide to create a new Client or refuse the request.
	*/
	virtual int onFirstRequest(IncomingPacket& request, void* lpContext, Client*& lpClient, OutgoingPacket*& lpPacket) = 0;



	Client* getClient(ClientKey clientKey);
	void returnClient(ClientKey clientKey);

	Server* getServer();
private:
	ClientFactoryImpl* pImpl;
};

}
#endif // ClientFactory__INCLUDED

