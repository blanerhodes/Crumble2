## Layer
This acts as an abstract class for layers created by the client application to inherit from

# Public Functions:
**Layer(const std::string&)**

**virtual ~Layer()**

**virtual void OnAttach()**

**virtual void OnDetach()**

**virtual void ONUpdate(Timestep)**

**virtual void OnImGuiRender()**

**virtual void OnEvent(Event&)**

**const std::string& GetName()**
-returns m_DebugName

# Protected Variables:
**std::string m_DebugName**