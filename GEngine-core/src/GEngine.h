#pragma once

#include "graphics/renderer/label.h"
#include "graphics/renderer/sprite.h"
#include "graphics/renderer/renderer2d.h"
#include "graphics/renderer/batchRenderer2d.h"
#include "graphics/window.h"
#include "graphics/layers/layer.h"
#include "math/math.h"
#include "utilities/timer.h"

namespace GEngine {
	class GEngine {
	private:
		Timer* timer_;
		unsigned int framesPerSec_, updatesPerSec_;
	protected:
		graphics::Window* window_;
	protected:
		GEngine()
			: framesPerSec_(0), updatesPerSec_(0) {

		}

		virtual ~GEngine() {
			delete timer_;
			delete window_;
		}

		graphics::Window* createWindow(const char *name, int width, int height) {
			window_ = new graphics::Window(name, width, height);
			return window_;
		}

	public:
		void start() {
			init();
			run();
		}

	protected:
		// Runs once upon initialization
		virtual void init() = 0;
		// Runs once per second
		virtual void tick() {}
		// Runs 60 times per second
		virtual void update() {}
		// Runs as fast as possible (unless vsync is enabled)
		virtual void render() = 0;

		const unsigned int getFPS() const { return framesPerSec_; }
		const unsigned int getUPS() const { return updatesPerSec_; }
	private:
		void run() {
			timer_ = new Timer();
			float timer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f / 60.0f;
			unsigned int frames = 0;
			unsigned int updates = 0;
			while (!window_->closed()) {
				window_->clear();
				if (timer_->elapsed() - updateTimer > updateTick) {
					update();
					updates++;
					updateTimer += updateTick;
				}
				render();
				frames++;
				window_->update();
				if (timer_->elapsed() - timer > 1.0f) {
					timer += 1.0f;
					framesPerSec_ = frames;
					updatesPerSec_ = updates;
					frames = 0;
					updates = 0;
					tick();
				}
			}
		}
	};
}
