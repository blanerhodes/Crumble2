## VertexBuffer

# Public Functions:
**virtual ~VertexBuffer()**

**virtual void Bind()**

**virtual void Unbind()**

**virtual const BufferLayout& GetLayout()**

**virtual void SetLayout(const BufferLayout& layout)**

**static VertexBuffer* Create(float* vertices, uint32_t size)**
- Returns a platform specific (i.e. OpenGL) vertex buffer