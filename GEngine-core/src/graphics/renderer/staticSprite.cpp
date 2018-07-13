#include "staticSprite.h"

GEngine::graphics::StaticSprite::StaticSprite(float x, float y, float width, float height, const math::Vec4& color, Shader& shader) : Renderable2D(math::Vec3(x,y,0), math::Vec2(width, height), color), shader_(shader) {
	vertexArray_ = new VertexArray();
	GLfloat vertices[] = {
		0, 0, 0,
		0, height, 0,
		width, height, 0,
		width, 0, 0
	};
	GLfloat colors[] = {
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};
	vertexArray_->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	vertexArray_->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
	//default indicies until new ones provided
	GLushort indicies[] = { 0,1,2,2,3,0 };
	indexBuffer_ = new IndexBuffer(indicies, 6);
}
