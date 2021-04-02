## LayerStack
Key Note: The difference between a layer and an overlay is that overlays are placed at the top of the layer stack.
The layer stack is subdivided into layers (towards the bottom) and overlays (towards the top).
Layers and overlays are fundamentally the same functionality wise.

# Public Functions:
**LayerStack()**

**~LayerStack()**
- Deletes all allocated layers

**void PushLayer(Layer*)**
- Inserts a new layer at the divide between layers and overlays (top most area of layer section)
- Calls the given layer's OnAttach() function

**void PushOverlay(Layer*)**
- Inserts a new overlay at the top of the layer stack
- Calls the given overlay's OnAttach() function

**void PopLayer(Layer*)**
- Searches only the layers section of the stack for the given layer
- If the layer is found the given layer's OnDetach function is called and the layer is removed from the stack

**void PopOverlay(Layer*)**
- Searches only the overlays section of the stack for the given overlay
- If the overlay is found the given overlay's OnDetach function is called and the overlay is removed from the stack

**std::vector<Layer*>::iterator begin()**
- Returns the beginning of the layer stack

**std::vector<Layer*>::iterator end()**
- Returns the end of the layer stack

# Private Variables:
**std::vector<Layer*> m_Layers**

**unsigned int m_LayerInsertIndex**