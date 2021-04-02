## IndexBuffer

# Public Functions:
**virtual ~IndexBuffer()**

**virtual void Bind()**

**virtual void Unbind()**

**virtual uin32_t Getcount()**

**static IndexBuffer* Create(uint32_t* indices, uint32_t size)**
- Returns a platform specific (i.e. OpenGL) index buffer