## WindowsWindow
- Inherits from Window

# Public Functions:
**WindowsWindow(const WindowProps& props)**
- Inits a new WindowsWindow

**virtual ~WindowsWindow()**
- Calls Shutdown()

**void OnUpdate()**
- Poll events and swaps buffers of m_Context

**unsigned int GetWidth()**
- Returns m_Data.Width

**inline unsigned int GetHeight()**
- Returns m_Data.Height

**inline void SetEventCallback(const EventCallbackFn& callback)**
- Returns m_Data.EventCallback

**void SetVSync(bool enabled)**
- Changes swap interval and sets VSync

**bool IsVSync()**
- Returns m_Data

**inline virtual void* GetNativeWindow()**
- Return m_Window

**Window* Create(const WindowProps& props)**
- Returns new WindowsWindow based on props

# Private Functions:
**virtual void Init(const WindowProps& props)**
- sets m_Data
- Inits glfw
- Creates glfw window for m_Window
- Creates new OpenGLContext and Inits
- Sets glfw window pointer
- Sets VSync
- Sets glfw window callbacks

**virtual void Shutdown()**
- Destroys window

# Private Variables:
**GLFWwindow* m_Window**
**GraphicContext& m_Context**

**struct WindowData**
-std::string Title
-unsigned int Width
-unsigned int Height
-bool VSync
-EventCallbackFn EventCallback

**WindowData m_Data**

# Related but not in class
**static bool s_GLFWInitialized**
**static void GLFWErrorCallBack(int error, const char* description)**
