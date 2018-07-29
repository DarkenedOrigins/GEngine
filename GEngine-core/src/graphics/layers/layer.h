#pragma once

#include "../renderer/renderable2d.h"
#include "../renderer/renderer2D.h"

namespace GEngine {
	namespace graphics {
		//base class for our layers
		class Layer {
		protected:
			Renderer2D * renderer_;
			//takes control of passed renderable so gg famo 
			std::vector<Renderable2D*> renderables_;
			Shader* shader_;
			math::Matrix4 projectionMatrix_;
		//protected funcs we dont want people to create a base class layer
		protected:
			Layer(Renderer2D* renderer, Shader* shader, math::Matrix4 projectionMatrix);
		//public funcs
		public:
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();

			inline const std::vector<Renderable2D*> getRenderables() const { return renderables_; }
		};
	}
}