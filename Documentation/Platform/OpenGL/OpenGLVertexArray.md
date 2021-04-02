## OpenGLVertexArray
- Inherits from VetexArray

# Public Functions:
**OpenGLVertexArray()**
- Creates vertex array

**virtual ~OpenGLVertexArray()**
- Deletes vertex array

**virtual void Bind()**
- Binds the vertex array

**virtual void Unbind()**
- Binds the vertex array to 0

**virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)**
- Binds vertex array and vertexBuffer
- Enables vertex attrib array using m_VertexBufferIndex
- Uses the vertexBuffer layout and m_VertexBufferIndex to set up vertex attrib pointers
- Adds the new vertexBuffer to m_VertexBuffers

**virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)**
- Binds vertex array
- Binds indexBuffer
- Sets m_IndexBuffer to indexBuffer

**virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
- Returns m_VertexBuffers

**virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
- Returns m_IndexBuffer

# Private Functions:
**uint32_t m_RendererID**
**uint32_t m_VertexBufferIndex**
**std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers**
**std::shared_ptr<IndexBuffer> m_IndexBuffer**

# Related but not in class
**static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)**
- Returns the associated GLenum based on data type