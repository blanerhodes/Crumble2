## OpenGLContext
- Inherits from GraphicsContext
- The graphics context is setting up the working area for OpenGL

# Public Funtions:
**OpenGLContext(GLFWwindow* windowHandle)**
- Set window handle

**virtual void Init()**
- Set current window context to m_WindowHandle
- Gets context address for glad

**virtual void SwapBuffers()**
- Swap glfw buffers

# Private Variables:
**GLFWwindow* m_WindowHandle**