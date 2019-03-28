/****************************************************************************
Copyright (c) 2018 Alejandro Santiago Varela

http://www.aeonphyxius.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef SIGNAL_H
#define SIGNAL_H

#include <functional>
#include <map>
//#include "debug.h"

 // A signal object may call multiple slots with the
 // same signature. You can connect functions to the signal
 // which will be called when the emit() method on the
 // signal object is invoked. Any argument passed to emit()
 // will be passed to the given functions.

namespace AeonLib
{
	struct EventHandler
	{
		static const int InvalidId = -1;
		static const EventHandler Invalid() { return EventHandler(InvalidId); }
		EventHandler() : m_Id(InvalidId) {}
		explicit EventHandler(const int id) : m_Id(id) {}

		bool operator<(const EventHandler& other) const { return m_Id < other.m_Id; }

		int m_Id;
	};

	template <typename... Args>
	class Signal
	{
	public:

		Signal()
			: m_currentId(EventHandler::InvalidId)
		{}

		Signal(Signal const& other) = delete; // delete Copy and Move constructors

		~Signal()
		{
			if (!m_slots.empty())
			{
				WARNING("A slot has not been disconnected from a signal.");
			}
		}

		// connects a std::function to the signal. The returned
		// value can be used to disconnect the function again
		template <typename A>
		EventHandler Connect(A&& slot)
		{
			m_slots.insert(std::make_pair(EventHandler(++m_currentId), std::forward<A>(slot)));
			return EventHandler(m_currentId);
		}

		// connects a member function of a given object to this Signal
		template <typename C, typename R, typename... A >
		EventHandler Connect(C* object, R(C::* memFunc)(A...))
		{
			return Connect([object = object, memFunc = memFunc](Args... p) { (object->*(memFunc))(p...); });
		}

		// disconnects a previously connected function
		void Disconnect(const EventHandler& id)
		{
			ASSERT(id.m_Id != EventHandler::InvalidId);
			m_slots.erase(id);
		}

		// disconnects all previously connected functions
		void DisconnectAll()
		{
			m_slots.clear();
		}

		// calls all connected functions
		void Emit(Args... p)
		{
			for (auto it : m_slots)
			{
				it.second(p...);
			}
		}

	private:
		std::map<EventHandler, std::function<void(Args...)>> m_slots;
		int m_currentId;
	};

}
#endif /* SIGNAL_HPP */