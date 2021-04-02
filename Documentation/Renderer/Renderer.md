## Renderer

# Public Functions:
**static void Init()**
- Initializes RenderCommand and Renderer2D

**static void OnWindowResize(uint32_t widht, uint32_t height)**
- Sets RenderCommand::SetViewport

**static void BeginScene(OrthographicCamera& camera)**
- Sets s_SceneData ViewProjectionMatrix the camera's ViewProjectionMatrix

**static void EndScene()**

**static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f))**
- Binds the shader
- Uploads a platform specific view projection matrix and transform to the shader
- Binds the vertexArray
- Invokes RenderCommand::DrawIndexed with the vertexArray

**static RendererAPI::API GetAPI()**
- Returns RendererAPI::GetAPI()

# Private Variables:
**struct SceneData**
-glm::mat4 ViewProjectionMatrix

**static SceneData* s_SceneData**