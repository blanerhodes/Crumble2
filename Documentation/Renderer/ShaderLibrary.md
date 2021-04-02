## ShaderLibrary

# Public Functions
**void Add(const std::string& name, const Ref<Shader>& shader)**
- Adds shader to m_Shaders with key:value name:shader

**void Add(const Ref<Shader>& shader)**
- Same as above but retrieves the name from the shader

**Ref<Shader> Load(const std::string& filepath)**
- Creates a shader from the given filepath and adds it to m_Shaders

**Ref<Shader> Load(const std::string& name, const std::string& filepath)**
- Creates shader from the given filepath and the given name and adds it to m_Shaders

**Ref<Shader> Get(const std::string& name)**
- Returns the shader with key = name

**bool Exists(const std::string& name)**
- Checks if shader is already in m_Shaders

# Private Variables:
**std::unordered_map<std::string, Ref<Shader>> m_Shaders**