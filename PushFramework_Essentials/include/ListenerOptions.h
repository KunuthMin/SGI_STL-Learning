/********************************************************************
	File :			ListenerOptions.h
	Creation date :	2011/03/21
		
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
#pragma once


#include "PushFramework.h"

namespace PushFramework{

	class Protocol;

	typedef struct PUSHFRAMEWORK_API ListenerOptions
	{
		const char* interfaceAddress;
		int listeningBackLog;
		bool isTcpNoDelay;
		bool synAttackPrevention;
		
		Protocol* pProtocol;

		unsigned int uReadBufferSize;
		unsigned int uSendBufferSize;

		unsigned int uIntermediateSendBufferSize;
		unsigned int uIntermediateReceiveBufferSize;

		ListenerOptions()
		{
			interfaceAddress = NULL;
			listeningBackLog = 100;
			isTcpNoDelay = true;
			synAttackPrevention = false;
			pProtocol = NULL;
			uReadBufferSize = 8192;
			uSendBufferSize = 8192;

			uIntermediateReceiveBufferSize = uReadBufferSize*2;
			uIntermediateSendBufferSize = uSendBufferSize*3;
		}
		~ListenerOptions()
		{
			//
		}



	}ListenerOptions;
}