## Input
This class is static with pure virtual, protected implementation functions to act as an abstract class for different Input implementations (see WindowsInput for an example)

# Public Functions:
**Input(const Input&)**

**Input& operator=(const Input&)**

**static bool IsKeyPressed(int)**
- Calls this static class' IsKeyPressedImpl(int)

**static bool IsMouseButtonPressed(int)
- Calls this static class' IsMouseButtonPressedImpl(int)

**static std::pair<float, float> GetMousePosition()**
- Calls this static class' GetMousePositionImpl()

**static float GetMouseX()**
- Calls this static class' GetMouseXImpl()

**static float GetMouseY()**
- Calls this static class' GetMouseYImpl()

# Protected Functions:
**Input()**

**virtual bool IsKeyPressedImpl(int)**

**virtual bool IsMouseButtonPressedImpl(int)**

**virtual std::pair<float, float> GetMousePositionImpl()**

**virtual float GetMouseXImpl()**

**virtual float GetMouseYImpl()**

# Private Variables:
 **Input* s_Instance**