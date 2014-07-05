/********************************************************************
	File :			PushFramework.h
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
#ifndef PushFramework__INCLUDED
#define PushFramework__INCLUDED


#ifdef PUSHFRAMEWORK_EXPORTS
#define PUSHFRAMEWORK_API __declspec(dllexport)
#else
#define PUSHFRAMEWORK_API __declspec(dllimport)
#endif

#endif // PushFramework__INCLUDED

namespace PushFramework{

	#define ClientKey const char*
	#define WStrKey const char*


}


