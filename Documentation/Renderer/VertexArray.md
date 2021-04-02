## VertexArray
- Abstract class to be inherited from by platform specific vertex arrays

# Public Functions:
virtual ~VertexArray() {}

**virtual void Bind()**

**virtual void Unbind()**

**virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)**

**virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)**

**virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers()**

**virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer()**

**static Ref<VertexArray> Create()**
- Returns reference to platform specific VertexArray