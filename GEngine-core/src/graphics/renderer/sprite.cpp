#include "sprite.h"

GEngine::graphics::Sprite::Sprite(float x, float y, float width, float height, const math::Vec4 & color) : Renderable2D(math::Vec3(x, y, 0), math::Vec2(width, height), color) {
	
}

GEngine::graphics::Sprite::Sprite(float x, float y, float width, float height, const unsigned int & color) : Renderable2D(math::Vec3(x, y, 0), math::Vec2(width, height), color) {

}

GEngine::graphics::Sprite::Sprite(float x, float y, float width, float height, Texture * texture) : Renderable2D(math::Vec3(x, y, 0), math::Vec2(width, height), 0xffffffff){
	texture_ = texture;
}
