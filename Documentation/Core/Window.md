## Window


# Public Functions:
**virtual ~Window()**

**virtual void OnUpdate()**

**virtual unsigned int GetWidth()**

**virtual unsinged int GetHeight()**

**virtual void SetEventCallback(const EventCallbackFn& callback)**

**virtual void SetVSync(bool enabled)**

**virtual bool IsVSync()**

**virtual void* GetNativeWindow()**

**static Window* Create(const WindowProps& props = WindowProps())**

# Related but not within class
**struct WindowProps**
{
-std::string Title
-unsigned int Width
-unsigned int Height

-WindowProps(const std::string& title, unsigned int width, unsigned int height)
}

**using EventCallbackFn = std::function<void(Event&)>**