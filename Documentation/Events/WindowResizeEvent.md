## WindowResizeEvent
-Inherits from Event

# Public Functions
**WindowResizeEvent(unsigned int width, unsigned int height)**

**unsigned int GetWidth()**
-returns m_Width

**unsigned int GetHeight()**
-reutnrs m_Height

**std::string ToString()**
-returns information about this event

**EVENT_CLASS_TYPE(WindowResize)**
**EVENT_CLASS_CATEGORY(EventCategoryApplication)**

# Private Variables
**unsigned int m_Width**
**unsigned int m_Height**