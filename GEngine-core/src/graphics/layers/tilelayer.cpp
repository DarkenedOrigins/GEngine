#include "tilelayer.h"

GEngine::graphics::TileLayer::TileLayer(Shader * shader) : Layer(new BatchRenderer2D(), shader, math::Matrix4::orthographic(-16,16,-9,9,-1,1)) {
	
}
