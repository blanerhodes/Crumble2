## RenderCommand
- This class contains a reference to the platform specific RendererAPI to submit commands to

# Public Functions:
**static void Init()**
- Calls the platform specific RendererAPI's Init()


**static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)**
- Calls the platform specific RendererAPI's SetViewport()

**static void SetClearColor(const glm::vec4& color)**
- Calls the platform specific RendererAPI's SetClearColor

**static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)**
- Calls the platform specific RendererAPI's DrawIndexed

# Private Variables:

##CURRENTLY DEFAULTS TO OPENGL
**static RendererAPI* s_RendererAPI** 