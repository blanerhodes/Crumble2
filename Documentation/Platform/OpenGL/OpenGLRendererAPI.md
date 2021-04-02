## OpenGLRendererAPI
- Inherits from RendererAPI

# Public Functions:
**virtual void Init()**
- Enable blending
- Set blending function
- Enable depth test
- Basic general set up for OpenGL

**virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)**
- Set gl viewport

**virtual void SetClearColor(const glm::vec4& color)**
- Set the color to clear color buffers with

**virtual void Clear()**
- Clear the color buffer and depth buffer bits

**virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)**
- Draw elements using given vertexArray
- Bind 2D texture to 0 (default texture)