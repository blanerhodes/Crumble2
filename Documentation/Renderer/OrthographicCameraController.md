## OrthographicCameraController

# Public Functions:
**OrthographicCameraController(float aspectRatio, bool rotation)**

**void OnUpdate(Timestep)**
- This handles what the camera should do when it updates per frame. This includes moving the camera, resetting its position, etc

**void OnEvent(Event& e)**
- Dispatches a MouseScrolledEvent and WindowResizeEvent

**OrthographicCamera& GetCamera()**
- Return m_Camera

**const OrthographicCamera& GetCamera()**

**float GetZoomLevel()**
- Returns m_ZoomLevel

**void SetZoomLevel(float level)**

# Private Functions:
**bool OnMouseScrolled(MouseScrolledEvent& e)**
- Sets the projection matrix based on the zoom level

**bool OnWindowResized(WindowResizeEvent& e)**
- Adjusts the aspect ratio based on window size and sets the projection matrix accordingly

# Private Variables:
**float m_AspectRatio**
**float m_ZoomLevel**
**OrthographicCamera m_Camera**
**bool m_Rotation**
**glm::vec3 m_CameraPosition**
**float m_CameraRotation**
**float m_CameraTranslationSpeed**
**float m_CameraRotationSpeed**