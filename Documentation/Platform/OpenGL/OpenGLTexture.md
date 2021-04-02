## OpenGLTexture
- Inherits from Texture2D

# Public Functions:
**OpenGLTexture2D(uint32_t width, uint32_t height)**
- Sets format of data and what the system expects (i.e. RGBA/RGBA8 etc)
- Creates 2D texture
- Assings texture store, texture filtering, and texture wrapping
- Basically any global setting you want to set for the texture

**OpenGLTexture2D(const std::string& path)**
- Loads texture from path using stbi
- Sets format based on number of channels
- Sets global settings you want for the texture

**virtual ~OpenGLTexture2D()**
- Delete the texture

**virtual uint32_t GetWidth()**
- Returns m_Width

**virtual uint32_t GetHeight()**
-Returns m_Height

**virtual void SetData(void* data, uint32_t size**
- Set texture subimage directly

**virtual void Bind(uint32_t slot = 0)**
- Binds texture to given texture slot

# Private Variables
**std::string m_Path**
**uint32_t m_Width**
**uint32_t m_Height**
**uint32_t m_RendererID**
**GLenum m_InternalFormat**
**GLenum m_DataFormat**