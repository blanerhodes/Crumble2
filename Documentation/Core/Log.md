## Log
This class holds connections to the engine/client loggers an defines macros for both

# Public Functions:
**Init()**
- Basic set up for using spdlog

**static std::shared_ptr<spdlog::logger>& GetCoreLogger()**

**static std::shared_ptr<spdlog::logger>& GetClientLogger()**

# Private Variables:
**static std::shared_ptr<spdlog::logger> s_CoreLogger**
**static std::shared_ptr<spdlog::logger> s_ClientLogger**