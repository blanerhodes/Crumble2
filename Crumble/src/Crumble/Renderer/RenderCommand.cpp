#include "crpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Crumble {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}