#pragma once


#include <cstddef>
#include "renderer2D.h"
#include "renderable2d.h"
#include "../buffers/indexBuffer.h"

#include "../../../ext/freetype-gl/freetype-gl.h"

namespace GEngine {
	namespace graphics {

		#define RENDERER_MAX_SPRITES	(60000)
		#define RENDERER_VERTEX_SIZE	( sizeof(VertexData) )
		#define	RENDERER_SPRITE_SIZE	(RENDERER_VERTEX_SIZE * 4)
		#define	RENDERER_BUFFER_SIZE	(RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES)
		#define	RENDERER_INDICES_SIZE	(RENDERER_MAX_SPRITES * 6)

		#define SHADER_VERTEX_INDEX		(0)
		#define SHADER_TEX_COORD_INDEX	(1)
		#define SHADER_TID_INDEX		(2)
		#define SHADER_COLOR_INDEX		(3)


		class BatchRenderer2D : public Renderer2D {
		private:
			GLuint vao_;	//vertex array object 
			GLuint vbo_;	//vertex buffer object
			IndexBuffer* ibo_;
			GLsizei indexCount_;
			VertexData* buffer_; //this is the buffer open in opengl
			std::vector<GLuint> textureSlots_;

			//string stuff
			ftgl::texture_atlas_t* ftAtlas_;
			ftgl::texture_font_t* ftFont_;

		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void drawString(const std::string& text, const math::Vec3 position, const unsigned int& color, unsigned int fontSize) override;
			void begin() override;
			void end() override;
			void submit(const Renderable2D* renderable) override;
			void flush() override;

		private:
			void init();

		};
	}
}
