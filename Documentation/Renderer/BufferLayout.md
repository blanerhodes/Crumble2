## BufferLayout

# Public Functions:
**BufferLayout()**

**BufferLayout(const std::initializer_list<BufferElement>& elements)**
- Calls CalculateOffsetsAndStride()

**uint32_t GetStride()**
- Returns m_Stride

**const std::vector<BufferElements>& GetElements()**
- Returns m_Elements

**std::vector<BufferElement>::iterator begin()**
- Returns m_Elements.begin()

**std::vector<BufferElement>::iterator end()**
- Returns m_Elements.end()

**std::vector<BufferElement>::const_iterator begin()**
- Returns m_Elements.begin()

**std::vector<BufferElement>::const_iterator end()**
- Returns m_Elements.end()

# Private Functions:
**void CalculateOffsetsAndStride()**
- For each element in m_Elements, set that element's offset based on the sizes of previous elements, and calculate the overall stride (length) of m_Elements

# Private Variables:
**std::vector<BufferElement> m_Elements**
**uint32_t m_Stride**

# Related but not in class:
**enum class ShaderDataType**
- Enum for primitive data types the shader could be handling

**static uint32_t ShaderDataTypeSize(ShaderDataType type)**
- Returns the size in bytes of the given ShaderDataType (i.e. ShaderDataType::Mat3 returns 4*3*3)

# struct BufferElement
**Variables:**
- std::string Name
- ShaderDataType Type
- uint32_t Size
- uint32_t Offset
- bool Normalized

**BufferElement()**

**uint32_t GetComponentCount()**
- Returns the number of components in Type (i.e. ShaderDataType::Mat3 returns 3 * 3)