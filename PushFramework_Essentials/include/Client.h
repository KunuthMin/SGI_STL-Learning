/********************************************************************
	File :			Client.h
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
#ifndef Client__INCLUDED
#define Client__INCLUDED

#pragma once

#include "PushFramework.h"

namespace PushFramework{

class OutgoingPacket;
class ClientImpl;
class Dispatcher;
class ClientFactoryImpl;



/**
	Represent a client logged into the server. A client is  .
	*/
class PUSHFRAMEWORK_API Client
{
	friend Dispatcher;
	friend ClientFactoryImpl;
public:
	Client(void);
	~Client(void);

	/**
		\param pPacket a reference to the packet to be sent.

		Sends a packet through the connection attached to this Client instance. If buffer is full, packet is rejected and function returns false.
	*/
	bool pushPacket(OutgoingPacket* pPacket);
	/**
		\param waitForPendingPackets Allows to defer connection close until pending data is totally sent.

		Disconnects connection. If waitForPendingPackets is true, the TCP connection is closed after all pending outgoing packets are successfully sent. This excludes, however, the pending packets belonging to broadcasting channels client is subscribed to.
	*/
	void disconnect(bool waitForPendingPackets);
	virtual const char* getKey() = 0;

private:
	ClientImpl* pImpl;
};

}

#endif // Client__INCLUDED
