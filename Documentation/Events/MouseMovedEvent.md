## MouseMovedEvent
-Inherits from Event

# Public Functions:
**MouseMovedEvent(float x, float y)**

**float GetX()**
- Returns m_MouseX

**float GetY()**
- Returns m_MouseY

**std::string ToString()**
- Returns information about the event

**EVENT_CLASS_TYPE(MouseMoved)**
**EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)**

# Private Variables:
**m_MouseX**
**m_MouseY**