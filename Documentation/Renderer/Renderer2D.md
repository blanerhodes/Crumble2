## Renderer2D

# Public Functions:
**static void Init()**
- Allocates new Renderer2DStorage
- Inits the VertexArray, VertexBuffer, and IndexBuffer
- The data for these are being made and set here but should be moved outside of this specific function


**static void Shutdown()*
- Deletes s_Data

**static void BeginScene(const OrthographicCamera& camera)**
- Each layer will call this in their OnUpdate
- Binds s_Data's shader and sets the shader's ViewProjectionMatrix to the camera's ViewProjectionMatrix

**static void EndScene()**
- Each layer will call this in their OnUpdate

**static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)**
- see below

**static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)**
- This is for flat color quads
- Sets s_Data's texture shader color, tiling factor, transform
- Binds the WhiteTexture shader
- Binds s_Data's VertexArray
- Issues RenderCommand::DrawIndexed call

**static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f))**
- see below

**static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f))**
- This is for textured quads
- Sets s_Data's texture shader tint color, tiling factor, transform
- Binds the given texture2D
- Binds s_Data's VertexArray
- Issues RenderCommand::DrawIndexed call

**static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color)**
- same as above but with a radian factor

**static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color)**
- same as above but with a radian factor

**static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f))**
- same as above but with a radian factor

**static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f))**
- same as above but with a radian factor

# Related but not in class
**struct Renderer2DStorage**
- Ref<VertexArray> QuadVertexArray
- Ref<Shader> TextureShader
- Ref<Texture2D> WhiteTexture

**static Renderer2DStorage* s_Data**