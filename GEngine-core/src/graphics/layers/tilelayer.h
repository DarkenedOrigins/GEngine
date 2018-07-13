#pragma once

#include "layer.h"
#include "../renderer/batchRenderer2D.h"

namespace GEngine {
	namespace graphics {
		class TileLayer : public Layer {
		public:
			TileLayer(Shader* shader);
			~TileLayer() {};
		};
	}
}
