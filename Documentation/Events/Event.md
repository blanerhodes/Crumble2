## Event/EventDispatcher

#**Event**
An abstract class to be inherited from by other events

# Public Functions:
**virtual EventType GetEventType()**

**virtual const char* GetName()**

**virtual int GetCategoryFlags()**

**virtual std::string ToString()**
- Returns GetName()

**bool IsInCategory(EventCategory category)**
- Returns GetCategoryFlags()

# Public Variables:
**bool Handled**


#**EventDispatcher**
This class handles generic events. When a dispatcher is made an Event is set to m_Event. The function passed to the dispatcher is then called.
This is intended to decouple the handling of events in different classes.

Usage:
EventDispatcher dispatcher(e);
dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

# Public Functions:
**EventDispatcher(Event& event)**

**template<typename T, typename F>**
**bool Dispatch(const F& func)**
- Returns true if m_Event is the same EventType as T and sets event T's handled flag based on func's return
- Returns false otherwise

# Related but not in class
**enum class EventType**

**enum EventCategory**
- Bit flags to set what categories an event falls under

**define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }**
- EVENT_CLASS_TYPE is for I DONT FUCKIN KNOW

**EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }**
- Returns this specific event's category flags

**std::ostream& operator<<(std:;ostream& os, const Event& e)**
- Calls the ToString() function of the given Event to print it's information