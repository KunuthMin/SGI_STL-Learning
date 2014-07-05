/********************************************************************
	File :			BroadcastManager.h
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
#ifndef BroadcastManager__INCLUDED
#define BroadcastManager__INCLUDED

#pragma once

#include "PushFramework.h"

namespace PushFramework{

class BroadcastManagerImpl;
class ClientFactoryImpl;
class Dispatcher;
class OutgoingPacket;
class ServerImpl;

class PUSHFRAMEWORK_API BroadcastManager
{
	friend ClientFactoryImpl;
	friend Dispatcher;
	friend ServerImpl;
public:
	BroadcastManager(void);
	~BroadcastManager(void);

	void createChannel(WStrKey channelKey, unsigned int maxPacket, bool requireSubscription, unsigned int uPriority, unsigned int uPacketQuota);
	void removeChannel(WStrKey channelKey);
	
	bool subscribeClient(ClientKey clientKey, WStrKey channelKey);
	bool unsubscribeClient(ClientKey clientKey, WStrKey channelKey);

	void pushPacket(OutgoingPacket* pPacket, WStrKey channelName, WStrKey killKey = "", int objectCategory = 0);
	void removePacket(WStrKey killKey, int objectCategory, WStrKey channelKey);

	void removeClient(ClientKey clientKey);
private:
	BroadcastManagerImpl* pImpl;
};

}
#endif // BroadcastManager__INCLUDED

