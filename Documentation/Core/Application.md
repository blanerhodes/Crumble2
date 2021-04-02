## Application
There will only be one active application at a time. An application accesses the Crumble engine and uses it.

#Public Functions:
**Application()**
- Sets application s_Instance variable
- Creates a Window object for m_Window
- Sets the Event Callback of m_Window
- Initializes the Renderer
- Creates an ImGuiLayer for m_ImGuiLayer
- Pushes the ImGuiLayer to the LayerStack

**virtual ~Application()**

**void Run()**
- This is application's run loop
- Calculates the Timestep
- Call OnUpdate on all layers if the window isn't minimized
- Call OnImGuiRender for each layer (mainly for debugging)
- Call OnUpdate for the window

**void OnEvent(Event&)**
- Creates EventDispatcher
- Dispatches a WindowCloseEvent and WindowResizeEvent by binding the corresponding private function calls where the EventDispatcher will decide which to handle and call.
- Iterate from end of m_LayerStack to beginning, calling each layer's OnEvent function until that even is handled.

**void PushLayer(Layer*)**
-Pushes given Layer to the LayerStack

**void PushOverlay(Layer*)**
-Pushes the given overlay to the LayerStack

**Window& GetWindow()**
- returns the current window

**static Application& Get()**
- returns reference to the current and only application


#Private Functions:
**bool OnWindowClose(WindowCloseEvent&)**
- flips flag to end run loop

**bool OnWindowResize(WindowResizeEvent&)**
- Sets m_Minimized so layers won't update if the window is fully minimized
- Call Renderer::OnWindowResize to adjust proper view window

#Private Variables:
**std::unique_ptr<Window> m_Window**
**ImGuiLayer* m_ImGuiLayer**
**bool m_Running**
**bool m_Minimized**
**LayerStack m_LayerStack**
**float m_LastFrameTime**
**static Application* s_Instance**


#Related but outside of class
**Application* CreateApplication()**
- This is defined by the client

**BIND_EVENT_FN**
- Binds a function to be handled by the event dispatcher