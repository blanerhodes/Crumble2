## OrthographicCamera

# Public Functions:
**OrthographicCamera(float left, float right, float bottom, float top)**
- Sets m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix

**void SetProjection(float, left, float right, float bottom, float top)**
- Sets m_ProjectionMatrix and then adjusts m_ViewProjectionMatrix

**const glm::vec3& GetPosition()**
- Returns m_Position

**void SetPosition(const glm::vec3& position)**
- Sets m_Position and calls RecalculateVewMatrix()

**float GetRotation()**
- Returns m_Rotation

**void SetRotation(float rotation)**
- Sets m_Rotation and calls RecalculateViewMatrix

**const glm::mat4& GetProjectionMatrix**
- Returns m_ProjectionMatrix

**const glm::mat4& GetViewMatrix()**
- Returns m_ViewMatrix

**const glm::mat4& GetViewProjectionMatrix)()**
- Returns m_ViewProjectionMatrix

# Private Functions:
**void RecalculateViewMatrix()**

# Private Variables:
**glm::mat4 m_ProjectionMatrix**
**glm::mat4 m_ViewMatrix**
**glm::mat4 m_ViewProjectionMatrix**
**glm::vec3 m_Position**
**float m_Rotation**