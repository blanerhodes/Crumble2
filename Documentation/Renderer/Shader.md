## Shader
- Abstract class to be inherited by a platform specific shader

# Public Functions:
**virtual ~Shader()**

**virtual void Bind()**

**virtual void Unbind()**

**virtual void SetInt(const std::string& name, int value)**

**virtual void SetFloat(const std::string& name, float value)**

**virtual void SetFloat3(const std::string& name, const glm::vec3& value)**

**virtual void SetFloat4(const std::string& name, const glm::vec4& value)**

**virtual void SetMat4(const std::string& name, const glm::mat4& value)**

**virtual const std::string& GetName()**

**static Ref<Shader> Create(const std::string& filepath)**
-Returns reference to platform specific shader using the filepath

**static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)**
- Returns reference to platform specific shader with a given name and vertex/fragment shader sources