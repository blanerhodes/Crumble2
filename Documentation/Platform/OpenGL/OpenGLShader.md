## OpenGLShader

# Public Functions:
**OpenGLShader(const std::string& filepath)**
- Creates shader from sources in external file and assigns name of the shader 

**OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)**
- Creates shader from sources given in raw string format

**virtual ~OpenGLShader()**
- Delete program

**virtual void Bind()**
- gl use program

**virtual void Unbind()**
- set program to 0

**virtual void SetInt(const std::string& name, int value)**
- Calls associated Uniform Upload

**virtual void SetFloat(const std::string& name, float value)**
- Calls associated Uniform Upload

**virtual void SetFloat3(const std::string& name, const glm::vec3& value)**
- Calls associated Uniform Upload

**virtual void SetFloat4(const std::string& name, const glm::vec4& value)**
- Calls associated Uniform Upload

**virtual void SetMat4(const std::string& name, const glm::mat4& value)**
- Calls associated Uniform Upload

**virtual const std::string& GetName()**
- Returns m_Name

**void UploadUniformInt(const std::string& name, int value)**
- Gets uniform from gl location to modify its value

**void UploadUniformFloat(const std::string& name, float value)**
- Gets uniform from gl location to modify its value

**void UploadUniformFloat2(const std::string& name, const glm::vec2& value)**
- Gets uniform from gl location to modify its value

**void UploadUniformFloat3(const std::string& name, const glm::vec3& value)**
- Gets uniform from gl location to modify its value

**void UploadUniformFloat4(const std::string& name, const glm::vec4& value)**
- Gets uniform from gl location to modify its value

**void UploadUniformMat3(const std::string& name, const glm::mat3& matrix)**
- Gets uniform from gl location to modify its value

**void UploadUniformMat4(const std::string& name, const glm::mat4& matrix)**
- Gets uniform from gl location to modify its value

# Private Functions:
**std::string ReadFile(const std::string& filepath)**
- Reads shader file into program

**std::unordered_map<GLenum, std::string> PreProcess(const std::string& source)**
- Parses result from ReadFile() to assign shader sources

**void Compile(const std::unordered_map<GLenum, std::string>& shaderSources)**
- Create program
- Compile shaders based on type
- Attach shaders to program
- Link program
- Detach shaders

# Private Variables:
**uint32_t m_RendererID**
**std::string n_Name**

# Related but not in class
**static GLenum ShaderTypeFromString(const std::string& type)**
- Returns vertex/fragment shader as given