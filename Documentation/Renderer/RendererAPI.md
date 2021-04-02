## RendererAPI
- Abstract class to be inherited from by the platform specific RendererAPIs

# Public Functions:
**virtual void Init()**

**virtual void SetViewport(int32_t x, uint32_t y, uint32_t width, uint32_t height)**

**virtual void SetClearColor(const glm::vec4& color)**

**virtual void Clear()**

**virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)**

**static API GetAPI()**
- Returns s_API

# Private Variables:
# CURRENTLY DEFAULTS TO OPENGL
**static API s_API**

**enum class API**
-None
-OpenGL