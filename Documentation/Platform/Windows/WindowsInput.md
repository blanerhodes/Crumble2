## windowsInput
- Inherits from Input

# Protected Functions:
**virtual bool IsKeyPressedImpl(int keycode)**
- Gets current window, checks if key was pressed and sets whether it was a press or repeat

**virtual bool IsMouseButtonPressedImpl(int button)**
- Gets current window, checks if mouse button was pressed

**virtual std::pair<float, float> GetMousePositionImpl()**
- Gets current window and gets the current cursor position
- Returns that position

**virtual float GetMouseXImpl()**

**virtual float GetMouseYImpl()**
